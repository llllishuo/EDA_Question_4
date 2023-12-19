#include "timing_Analysis.h"
#include "ThreadPool.h"
#include <algorithm> // for std::max and std::min
#include <math.h>    // for mathematical operations

GlobalSlacks slacks;
int len = 0;

void perform_global_slack_on_path(GlobalSlacks& slacks, TimingAnalysis& data, std::string& endpoint, SetupCheck& setupCheck, std::string& start_str);
/**
 * 模拟正态分布 使用Box-Muller变换
 *
 * @param mean
 * @param sigma
 * @return
 * 使用 rand() 生成两个均匀分布在-1到1之间的随机数 u 和 v。然后计算 s，确保它小于1且不为0。使用Box-Muller变换公式计算最终的正态分布随机数。
 */

double normalDistribution(double mean, double sigma) {
    static bool hasSpare = false;
    static double spare;

    if (hasSpare) {
        hasSpare = false;
        return mean + sigma * spare;
    }

    hasSpare = true;
    static double u, v, s;
    do {
        u = (rand() / ((double) RAND_MAX)) * 2.0 - 1.0;
        v = (rand() / ((double) RAND_MAX)) * 2.0 - 1.0;
        s = u * u + v * v;
    } while (s >= 1.0 || s == 0.0);

    s = sqrt(-2.0 * log(s) / s);
    spare = v * s;
    return mean + sigma * u * s;
}

std::vector<double> get_max(std::vector<double> target){
    std::vector<double> new_vec;
    if (target.size() == 1) return target;
    double result = 0.0;
    for(double i: target){
        if (i > result){
            result = i;
        }
    }
    new_vec.push_back(result);
    return std::move(new_vec);
}
std::vector<double> get_min(std::vector<double> target){
    std::vector<double> new_vec;
    if (target.size() == 1) return target;
    double result = 99999999.0;
    for(double i: target){
        if (i < result){
            result = i;
        }
    }
    new_vec.push_back(result);
    return std::move(new_vec);
}

/**
 * 计算 arrival_time (每次计算完存储到数组里再将最大的赋予 0 索引处)
 * @param edge 当前路径节点段
 * @param from_arr_time from 节点 arrival_time
 * @param arrival_time 所有点的arrival_time
 * 根据公式计算 ( max_rise, max_fall, min_rise, min_fall)
 * 当 arrival time 经过 sense 为 neg_unate 的 edge 时，目标节点处 max rise arrival = 源节
 * 点处 max fall arrival + N(max rise delay mean, max rise delay
 * sigma2)；目标节点处 max fall arrival = 源节点处 max rise arrival + N(max
 * fall delay mean, max fall delay sigma2)。
 * 当 arrival time 经过 sense 为 rising_edge 的 edge 时，目标节点处 max rise arrival = 源
 * 节点处 max rise arrival + N(max rise delay mean, max rise delay
 * sigma2)；目标节点处 max fall arrival = 源节点处 max rise arrival + N(max
 * fall delay mean, max fall delay sigma2)。
 * 当 arrival time 经过 sense 为 falling_edge 的 edge 时，目标节点处 max rise arrival = 源
 * 节点处 max fall arrival + N(max rise delay mean, max rise delay
 * sigma2)；目标节点处 max fall arrival = 源节点处 max fall arrival + N(max
 * fall delay mean, max fall delay sigma2)。
 * 目标节点处 min rise arrival 和 min fall arrival 计算方式与 max 情况相同，只是
 * delay 选取相应的 min delay 即可。
 *
 * 最后计算 按照公式计算相应的 mean、sigma
 * MaxRiseMean(CBUF1/A) = MaxRiseMean(CLK) + MaxRiseDelay(CLK->CBUF1/A)
 * = 0 + 1.1 = 1.1.
 * MaxFallMean(CBUF1/A) = MaxFallMean(CLK) + MaxFallDelay(CLK->CBUF1/A)
 * = 0 + 1.2 = 1.2.
 * MinRiseMean(CBUF1/A) = MinRiseMean(CLK) + MinRiseDelay(CLK->CBUF1/A)
 * = 0 + 0.9 = 0.9.
 * MinFallMean(CBUF1/A) = MinFallMean(CLK) + MinFallDelay(CLK->CBUF1/A)
 * = 0 + 0.8 = 0.8.
 *
 */
void calculate_arrival_times(Edge edge,ArrivalTime& from_arr_time, std::unordered_map<std::string, ArrivalTime>& arrival_time) {

    int i = 0;
    // arr time 计算
    if (edge.sense == "pos_unate") {
        arrival_time[edge.to_vertex].max_rise.push_back(
                from_arr_time.max_rise[0] +
                normalDistribution(edge.max_rise_delay_mean, edge.max_rise_delay_sigma));

        arrival_time[edge.to_vertex].max_fall.push_back(
                from_arr_time.max_fall[0] +
                normalDistribution(edge.max_fall_delay_mean, edge.max_fall_delay_sigma));

       arrival_time[edge.to_vertex].min_rise.push_back(
               from_arr_time.min_rise[0] +
                normalDistribution(edge.min_rise_delay_mean, edge.min_rise_delay_sigma));
        arrival_time[edge.to_vertex].min_fall.push_back(
                from_arr_time.min_fall[0] +
                normalDistribution(edge.min_fall_delay_mean, edge.min_fall_delay_sigma));

    }else if (edge.sense == "neg_unate") {
        arrival_time[edge.to_vertex].max_rise.push_back(
                from_arr_time.max_fall[0] +
            normalDistribution(edge.max_rise_delay_mean, edge.max_rise_delay_sigma));
        arrival_time[edge.to_vertex].max_fall.push_back(
                from_arr_time.max_rise[0] +
            normalDistribution(edge.max_fall_delay_mean, edge.max_fall_delay_sigma));
        arrival_time[edge.to_vertex].min_rise.push_back(
                from_arr_time.min_fall[0] +
                normalDistribution(edge.min_rise_delay_mean, edge.min_rise_delay_sigma));
        arrival_time[edge.to_vertex].min_fall.push_back(
                from_arr_time.min_rise[0] +
                normalDistribution(edge.min_fall_delay_mean, edge.min_fall_delay_sigma));
    }else if (edge.sense == "rising_edge") {
        arrival_time[edge.to_vertex].max_rise.push_back(
                from_arr_time.max_rise[0] +
            normalDistribution(edge.max_rise_delay_mean, edge.max_rise_delay_sigma));
        arrival_time[edge.to_vertex].max_fall.push_back(
                from_arr_time.max_rise[0] +
            normalDistribution(edge.max_fall_delay_mean, edge.max_fall_delay_sigma));
        arrival_time[edge.to_vertex].min_rise.push_back(
                from_arr_time.min_rise[0] +
                normalDistribution(edge.min_rise_delay_mean, edge.min_rise_delay_sigma));
        arrival_time[edge.to_vertex].min_fall.push_back(
                from_arr_time.min_rise[0] +
                normalDistribution(edge.min_fall_delay_mean, edge.min_fall_delay_sigma));
    }else if (edge.sense == "falling_edge") {
        arrival_time[edge.to_vertex].max_rise.push_back(
                from_arr_time.max_fall[0] +
            normalDistribution(edge.max_rise_delay_mean, edge.max_rise_delay_sigma));
        arrival_time[edge.to_vertex].max_fall.push_back(
                from_arr_time.max_fall[0] +
            normalDistribution(edge.max_fall_delay_mean, edge.max_fall_delay_sigma));
        arrival_time[edge.to_vertex].min_rise.push_back(
                from_arr_time.min_fall[0] +
                normalDistribution(edge.min_rise_delay_mean, edge.min_rise_delay_sigma));
        arrival_time[edge.to_vertex].min_fall.push_back(
                from_arr_time.min_fall[0] +
                normalDistribution(edge.min_fall_delay_mean, edge.min_fall_delay_sigma));
	}
    ArrivalTime arrivalTime = arrival_time[edge.to_vertex];

//    if (arrival_time[edge.to_vertex].max_rise.size() > 1){
//        i=1;
//        std::cout << "edge.to: " << edge.to_vertex << "\n max_fall-" << arrival_time[edge.to_vertex].max_fall[0] << ",min_fall-" << arrival_time[edge.to_vertex].min_fall[0]
//                  << "\n max_rise-" << arrival_time[edge.to_vertex].max_rise[0]<< ",min_rise-" << arrival_time[edge.to_vertex].min_rise[0]
//                  <<std::endl;
//    }

    arrival_time[edge.to_vertex].max_rise = get_max(arrival_time[edge.to_vertex].max_rise);
    arrival_time[edge.to_vertex].max_fall = get_max(arrival_time[edge.to_vertex].max_fall);
    arrival_time[edge.to_vertex].min_rise = get_min(arrival_time[edge.to_vertex].min_rise);
    arrival_time[edge.to_vertex].min_fall = get_min(arrival_time[edge.to_vertex].min_fall);

    // mean 计算
    arrival_time[edge.to_vertex].node_data_max_rise_delay_mean.push_back(
            from_arr_time.node_data_max_rise_delay_mean[0] + arrival_time[edge.to_vertex].max_rise[0]
    );

    arrival_time[edge.to_vertex].node_data_max_fall_delay_mean.push_back(
            from_arr_time.node_data_max_fall_delay_mean[0] + arrival_time[edge.to_vertex].max_fall[0]
    );
    arrival_time[edge.to_vertex].node_data_min_rise_delay_mean.push_back(
            from_arr_time.node_data_min_rise_delay_mean[0] + arrival_time[edge.to_vertex].min_rise[0]
    );
    arrival_time[edge.to_vertex].node_data_min_fall_delay_mean.push_back(
            from_arr_time.node_data_min_fall_delay_mean[0] + arrival_time[edge.to_vertex].min_fall[0]
    );
    arrivalTime = arrival_time[edge.to_vertex];

//    if( arrival_time[edge.to_vertex].node_data_max_rise_delay_mean.size() > 1){
//        i=1;
//        std::cout << "\n node_data_max_rise_delay_mean-" << arrival_time[edge.to_vertex].node_data_max_rise_delay_mean[0]<< ",node_data_min_rise_delay_mean-" << arrival_time[edge.to_vertex].node_data_min_rise_delay_mean[0]
//                << "\n node_data_max_fall_delay_mean-" << arrival_time[edge.to_vertex].node_data_max_fall_delay_mean[0]<< ",node_data_min_fall_delay_mean-" << arrival_time[edge.to_vertex].node_data_min_fall_delay_mean[0]
//                <<std::endl;
//    }


    arrival_time[edge.to_vertex].node_data_max_rise_delay_mean = get_max(arrival_time[edge.to_vertex].node_data_max_rise_delay_mean);
    arrival_time[edge.to_vertex].node_data_max_fall_delay_mean = get_max(arrival_time[edge.to_vertex].node_data_max_fall_delay_mean);
    arrival_time[edge.to_vertex].node_data_min_rise_delay_mean = get_min(arrival_time[edge.to_vertex].node_data_min_rise_delay_mean);
    arrival_time[edge.to_vertex].node_data_min_fall_delay_mean = get_min(arrival_time[edge.to_vertex].node_data_min_fall_delay_mean);

    // sigma 计算
    arrival_time[edge.to_vertex].node_data_max_rise_delay_sigma.push_back(
            from_arr_time.node_data_max_rise_delay_sigma[0] + arrival_time[edge.to_vertex].max_rise[0]
    );

    arrival_time[edge.to_vertex].node_data_max_fall_delay_sigma.push_back(
            from_arr_time.node_data_max_fall_delay_sigma[0] + arrival_time[edge.to_vertex].max_fall[0]
    );
    arrival_time[edge.to_vertex].node_data_min_rise_delay_sigma.push_back(
            from_arr_time.node_data_min_rise_delay_sigma[0] + arrival_time[edge.to_vertex].min_rise[0]
    );
    arrival_time[edge.to_vertex].node_data_min_fall_delay_sigma.push_back(
            from_arr_time.node_data_min_fall_delay_sigma[0] + arrival_time[edge.to_vertex].min_fall[0]
    );
    arrivalTime = arrival_time[edge.to_vertex];
//    if (arrival_time[edge.to_vertex].node_data_min_rise_delay_sigma.size() > 1){
//        i=1;
//        std::cout << "\n node_data_max_rise_delay_sigma-" << arrival_time[edge.to_vertex].node_data_max_rise_delay_sigma[0]<< ",node_data_min_rise_delay_sigma-" << arrival_time[edge.to_vertex].node_data_min_rise_delay_sigma[0]
//                << "\n node_data_max_fall_delay_sigma-" << arrival_time[edge.to_vertex].node_data_max_fall_delay_sigma[0]<< ",node_data_min_fall_delay_sigma-" << arrival_time[edge.to_vertex].node_data_min_fall_delay_sigma[0]
//                << std::endl;
//    }

    arrival_time[edge.to_vertex].node_data_max_rise_delay_sigma = get_max(arrival_time[edge.to_vertex].node_data_max_rise_delay_sigma);
    arrival_time[edge.to_vertex].node_data_max_fall_delay_sigma = get_max(arrival_time[edge.to_vertex].node_data_max_fall_delay_sigma);
    arrival_time[edge.to_vertex].node_data_min_rise_delay_sigma = get_min(arrival_time[edge.to_vertex].node_data_min_rise_delay_sigma);
    arrival_time[edge.to_vertex].node_data_min_fall_delay_sigma = get_min(arrival_time[edge.to_vertex].node_data_min_fall_delay_sigma);

    arrivalTime = arrival_time[edge.to_vertex];
//    if (i == 1){
//        std::cout << "edge.to: " << edge.to_vertex << "\n max_fall-" << arrival_time[edge.to_vertex].max_fall[0] << ",min_fall-" << arrival_time[edge.to_vertex].min_fall[0]
//                  << "\n max_rise-" << arrival_time[edge.to_vertex].max_rise[0]<< ",min_rise-" << arrival_time[edge.to_vertex].min_rise[0]
//                  << "\n node_data_max_rise_delay_mean-" << arrival_time[edge.to_vertex].node_data_max_rise_delay_mean[0]<< ",node_data_min_rise_delay_mean-" << arrival_time[edge.to_vertex].node_data_min_rise_delay_mean[0]
//                  << "\n node_data_max_fall_delay_mean-" << arrival_time[edge.to_vertex].node_data_max_fall_delay_mean[0]<< ",node_data_min_fall_delay_mean-" << arrival_time[edge.to_vertex].node_data_min_fall_delay_mean[0]
//                  << "\n node_data_max_rise_delay_sigma-" << arrival_time[edge.to_vertex].node_data_max_rise_delay_sigma[0]<< ",node_data_min_rise_delay_sigma-" << arrival_time[edge.to_vertex].node_data_min_rise_delay_sigma[0]
//                  << "\n node_data_max_fall_delay_sigma-" << arrival_time[edge.to_vertex].node_data_max_fall_delay_sigma[0]<< ",node_data_min_fall_delay_sigma-" << arrival_time[edge.to_vertex].node_data_min_fall_delay_sigma[0]
//                  << std::endl;
//    }


}
void analysis_arrival_times(const std::vector<Edge> edges, TimingAnalysis& data){
//	for (Edge edge : edges) {
//		calculate_arrival_times(edge,data);
//	}
}

/**
 * 深度优先搜索  利用递归从from检索到end, 同时进行计算
 * @param from_node 当前节点
 * @param start_node 起点节点
 * @param end_node 终点节点
 * @param data 总数据
 * @return 是否到达终点
 *
 * 如果当前节点的邻接矩阵为空则当前路径穷尽，需要返回找到其它路径
 * 如果到达终点则将对终点与起点记录 key: start, value: end
 * 上述条件未执行则未到终点当前路径进行计算并向前运动直至到达终点
 * 如果遇到多分支情况既 node_max_len > 1 则利用 node_len 进行标记 并在交汇点进行等待 直至标记到 node_len >= node_len
 * 方为所有分支计算完成 取最大值继续执行
 *
 */
bool search_node_to_end(std::string from_node,std::string  start_node,std::string  end_node,TimingAnalysis& data){

    data.node_len[from_node]++;
    if (end_node == from_node){

        return true;
    }
    std::unordered_map<std::string, Edge> to = data.edges[from_node];
    for(auto it=to.begin();it!=to.end();it++){

//        std::cout << "start: " << start_node << ", end: " << end_node << std::endl;
        calculate_arrival_times(it->second,data.arrival_times[it->second.from_vertex], data.arrival_times);

        bool is_search =  search_node_to_end(it->first,start_node,end_node,data);
        if (is_search) {
            break;
        }else{
            continue;
        }
    }
}

void thread_for_end(TimingAnalysis& data,std::string end){
    for(std::string from: data.startpoints){
//            std::cout << "start: " << from << ", end: " << end << std::endl;

        data.node_len[from] = 0;
        search_node_to_end(from,from,end,data);

    }
}
/**
 * 计算起始函数
 * @param data
 * 根据起点文件进行初始化
 * 从起点开始一直循环到终点进行计算
 */
void perform_timing_analysis(TimingAnalysis& data, int thread_pool_len){
//    data.arrival_times["CLK"] = ArrivalTime{{0.0}, {0.0}, {0.0}, {0.0}};
    for (const auto& startpoint : data.startpoints) {
        data.arrival_times[startpoint] = ArrivalTime{
            {0.0}, {0.0}, {0.0}, {0.0},
            {0.0}, {0.0}, {0.0}, {0.0},
            {0.0}, {0.0}, {0.0}, {0.0}
        };
    }

    for (int i = 0; i < data.endpoints.size(); i += thread_pool_len){
        ThreadPool pool(thread_pool_len);

        for (size_t j = i; j < i + thread_pool_len && j < data.endpoints.size(); ++j) {
            std::string end = data.endpoints[j];
            if (data.node_len[end] > 0){
                for(auto it=data.node_len.begin();it!=data.node_len.end();it++) {
                    it->second = 0;
                }
            }

//            pool.enqueue(thread_for_end,data,data.startpoints[j]);
            thread_for_end(data,end);
        }

    }


}
/**
 * Global Slack计算
 * 根据终点节点与其CK节点进行计算
 * 公式:
 * SlackRise(DFF3/D) = ClockPeriod + MinRiseMean(DFF3/CK) –
 * MaxRiseMean(DFF3/D) – RiseConstraint(DFF3/CK->DFF3/D) = 10 + 4.5 –
 * 10.3 – 0.5 = 3.7
 * SlackFall(DFF3/D) = ClockPeriod + MinRiseMean(DFF3/CK) –
 * MaxFallMean(DFF3/D) – FallConstraint(DFF3/CK->DFF3/D) = 10 + 4.5 –
 * 10.5 – 0.6 = 3.4
 *
 * reqTime = clock period + mean(DFF/CK, min, rise) – N * sigma(DFF/CK, min, rise) –
 * setupValue(DFF/CK, DFF/D, fall)
 * arrTime = mean(DFF/D, max, fall) + N * sigma(DFF/D, max, fall)
 * slack = reqTime – arrTime
 */
void perform_global_slack_on_path(GlobalSlacks& slacks, TimingAnalysis& data, std::string& endpoint, SetupCheck& setupCheck, std::string& start_str){

    ArrivalTime test_arr_time = data.arrival_times[start_str];
    std::unordered_map<std::string, Edge> test_edge =  data.edges[start_str];
    if (setupCheck.sense.compare("setup_rising") == 0) {
        slacks.Slack_Rise.insert_or_assign(endpoint,
                ClockPeriod + data.arrival_times[start_str].node_data_min_rise_delay_mean[0] - data.arrival_times[start_str].node_data_max_rise_delay_mean[0] -
                setupCheck.rise_constraint);
        slacks.Slack_Fall.insert_or_assign(endpoint,
                ClockPeriod + data.arrival_times[start_str].node_data_min_rise_delay_mean[0] - data.arrival_times[start_str].node_data_max_fall_delay_mean[0] -
                setupCheck.fall_constraint);
        slacks.req_Time.insert_or_assign(endpoint,
                ClockPeriod + data.arrival_times[start_str].node_data_min_rise_delay_mean[0] - N * data.arrival_times[start_str].node_data_min_rise_delay_mean[0] -
                setupCheck.fall_constraint);
        slacks.arr_Time.insert_or_assign(endpoint,data.arrival_times[start_str].node_data_max_fall_delay_mean[0] + N * data.arrival_times[start_str].node_data_max_fall_delay_sigma[0]);
    } else{
        slacks.Slack_Rise.insert_or_assign(endpoint,
                ClockPeriod + data.arrival_times[start_str].node_data_min_fall_delay_mean[0] - data.arrival_times[start_str].node_data_max_rise_delay_mean[0] -
                setupCheck.rise_constraint);
        slacks.Slack_Fall.insert_or_assign(endpoint,
                ClockPeriod + data.arrival_times[start_str].node_data_min_fall_delay_mean[0] - data.arrival_times[start_str].node_data_max_fall_delay_mean[0] -
                setupCheck.fall_constraint);
        slacks.req_Time.insert_or_assign(endpoint,
                ClockPeriod + data.arrival_times[start_str].node_data_min_rise_delay_mean[0] - N * data.arrival_times[start_str].node_data_min_rise_delay_mean[0] -
                setupCheck.fall_constraint);
        slacks.arr_Time.insert_or_assign(endpoint, data.arrival_times[start_str].node_data_max_fall_delay_mean[0] + N * data.arrival_times[start_str].node_data_max_fall_delay_sigma[0]);

    }

}
void perform_operation_global_slack(int thread_pool_len,GlobalSlacks& slacks, TimingAnalysis& data){
    // 创建一个具有特定数量线程的线程池
    ThreadPool pool(thread_pool_len); // 假设使用4个线程


    for (std::string endpoint: data.endpoints){
        std::unordered_map<std::string, SetupCheck> from_checks= data.setup_checks[endpoint];
        SetupCheck setupCheck;
        std::string start_str;
        for(auto it=from_checks.begin();it!=from_checks.end();it++) {
            setupCheck = it->second;
            start_str = it->first;
        }
        if (!data.arrival_times.count(start_str)){
            len ++;
            ArrivalTime arrival_time;
            arrival_time.min_rise.push_back(0.0);
            arrival_time.max_rise.push_back(0.0);
            arrival_time.min_fall.push_back(0.0);
            arrival_time.max_fall.push_back(0.0);
            arrival_time.node_data_min_rise_delay_mean.push_back(0.0);
            arrival_time.node_data_max_rise_delay_mean.push_back(0.0);
            arrival_time.node_data_min_fall_delay_mean.push_back(0.0);
            arrival_time.node_data_max_fall_delay_mean.push_back(0.0);
            arrival_time.node_data_min_rise_delay_sigma.push_back(0.0);
            arrival_time.node_data_max_rise_delay_sigma.push_back(0.0);
            arrival_time.node_data_min_fall_delay_sigma.push_back(0.0);
            arrival_time.node_data_max_fall_delay_sigma.push_back(0.0);
            data.arrival_times.insert_or_assign(start_str,arrival_time);
        }

        perform_global_slack_on_path(slacks, data, endpoint, setupCheck, start_str);
    }


}



/**
 * 运行入口
 * @param cli 所有输入输出路径
 */
void run(Cli cli){



     TimingAnalysis data;
     //读取数据
     std::cout << "Reading data ..." << std::endl;
     read_csv_to_edges(cli.edge_filename, data);
     read_setup_check_data(cli.setup_check_filename, data.setup_checks);
     read_startpoints(cli.startpoints_filename, data.startpoints);
     read_endpoints(cli.endpoints_filename, data.endpoints);
     std::cout << "Reading data completed ..." << std::endl;
     //计算数据
     std::cout << "Calculate arr-time ..." << std::endl;
     perform_timing_analysis(data, cli.thread_pool_len);
     std::cout << "Calculate arr-time completed ..." << std::endl;

     //得到slack
     slacks.endpoints = data.endpoints;
    std::cout << "Calculate global-slack..." << std::endl;
    perform_operation_global_slack(cli.thread_pool_len,slacks,data);
    std::cout << "Calculate global-slack completed ..." << std::endl;
    std::cout << "--------" << len << "<>" << data.endpoints.size() << "<>" << data.arrival_times.size() << std::endl;
    // 输出到global_slack.csv
    std::cout << "Write Slack ..." << std::endl;
    write_to_global_slack(slacks, cli.input_global_slack_filename);
    std::cout << "Write Slack Complete ..." << std::endl;
	    for(auto it=slacks.Slack_Fall.begin();it!=slacks.Slack_Fall.end();it++) {
        std::cout << it->first <<","<<slacks.Slack_Rise[it->first]<<","<<slacks.Slack_Fall[it->first]<< std::endl;
    }
}

