## 运行流程

1. [main](./main.md)
2. [timing_analysis](./timing_analysis.md).run()
3. [io](./io.md).read()
4. [timing_analysis](./timing_analysis.md).perform_timing_analysis()
    - [timing_analysis](./timing_analysis.md).search_node_to_end()
    - [timing_analysis](./timing_analysis.md).calculate_arrival_times()
    - ...
    - [timing_analysis](./timing_analysis.md).search_node_to_end()
    - [timing_analysis](./timing_analysis.md).calculate_arrival_times()
5. [timing_analysis](./timing_analysis.md).perform_operation_global_slack()
6. [io](./io.md).write_to_global_slack()
7. over

### read_csv_to_edges
(这里我只讲解一个读取函数，其它读取同理)

in [file/io.cpp](../file/io.cpp)
```c++
void read_csv_to_edges(const std::string& filename, TimingAnalysis& data){

    std::ifstream file(filename, std::ios::binary);
    std::string line;
    getline(file, line);
    std::vector<char> buffer(1024 * 1024); // 1MB 缓冲区

    std::string leftover; // 存储未完整读取的行的部分
    while (file.read(buffer.data(), buffer.size()) || file.gcount() > 0) {
        std::string currentChunk = leftover + std::string(buffer.data(), file.gcount());
        std::stringstream ss(currentChunk);
        std::string line;

        while (std::getline(ss, line)) {
            if (ss.peek() != EOF) {
                std::vector<std::string> tokens = split(line, ',');
                // 处理完整的行
                process_line_edges(tokens, data);
            } else {
                leftover = line; // 保存未完整的行，以便与下一块数据一起处理
                break;
            }
        }
    }

    // 处理文件最后一行（如果有）
    if (!leftover.empty()) {
        std::vector<std::string> tokens = split(leftover, ',');
        process_line_edges(tokens, data);
    }

}
```


首先将拿到的路径进行打开通过“ifstream”
之后定义缓冲区“buffer”为1MB既我们对文件进行读取时将以1MB的大小进行读取
再定义一个变量(leftover)用来存储未读取完整的部分
例如有如下文件
```angular2html
123456789\n
123456789\n
EOF
```
\n代表换行，EOF未文件结束标识符，这些再文件中都是隐性存在在此我将他可见

假设我们读取1MB读取到
```angular2html
123456789\n
123
```
那么第二行的123将存储到leftover，方便下面对下一个1MB进行拼接
```angular2html
123 + 456789\n
EOF
```
各种流是以这样的形式进行读取
```angular2html
   1 2 3 4 6 7\n 1 2 3 4 5 6 7\n EOF
   ^ ->  ^   ->    ^
```


我们清楚了这些意思我们进入while循环，我们将file文件读取到buffer读取大小为buffer.size()中并设定条件[gcount()](https://www.apiref.com/cpp-zh/cpp/io/basic_istream/gcount.html)读取完剩下的数据大小不为空

首先就是将之前未读取完整的部分拼接上”leftover + std::string(buffer.data(), file.gcount())“

然后我们将拼接好的数据变成字符串流的方式再根据内部while的条件(std::getline(ss, line))将这个字符串流一行一行进行提取

如果当前流还没到EOF就说明还没结束我们将这个行信息进行按‘,’分割，我们就拿到了各个数据再到process_line_edges()中封装到data中

in [file/line.cpp](../file/line.cpp)
```c++
void  process_line_edges(std::vector<std::string> tokens,TimingAnalysis& data){

    std::unordered_map<std::string, Edge> to_node_edge;
    Edge edge;
    edge.from_vertex = tokens[0];
    edge.to_vertex = tokens[1];
    edge.sense = tokens[2];
    edge.max_rise_delay_mean = std::stod(tokens[3]);
    edge.max_rise_delay_sigma = std::stod(tokens[4]);
    edge.max_fall_delay_mean = std::stod(tokens[5]);
    edge.max_fall_delay_sigma = std::stod(tokens[6]);
    edge.min_rise_delay_mean = std::stod(tokens[7]);
    edge.min_rise_delay_sigma = std::stod(tokens[8]);
    edge.min_fall_delay_mean = std::stod(tokens[9]);
    edge.min_fall_delay_sigma = std::stod(tokens[10]);

    data.node_len[edge.to_vertex] = 0;
    data.node_max_len[edge.to_vertex] ++;
    to_node_edge[edge.to_vertex] = edge;
    data.edges[edge.from_vertex] = to_node_edge;
}
```

#### 数据结构

一定要注意的是数据封装方式有所不同

根据[DataStructure.h](../include/DataStructure.h)

```c++
struct TimingAnalysis {
    std::unordered_map<std::string,unsigned int> node_max_len;
    std::unordered_map<std::string,unsigned int> node_len;
    //邻接矩阵
    std::unordered_map<std::string,std::unordered_map<std::string, Edge>> edges;
    //std::unordered_map<std::string,std::vector<std::string>> nodes_adjacency_matrix;

    std::unordered_map<std::string,std::unordered_map<std::string, SetupCheck>> setup_checks;
    std::vector<std::string> startpoints;
    std::vector<std::string> endpoints;
    std::unordered_map<std::string,std::string> start_end_map;
    std::unordered_map<std::string, ArrivalTime> arrival_times;
};
```
* edge的map(key: from_node value: map(key: to_node value: 各个数据))
例如
in [data/edge_data.csv](../data/edge_data.csv)
```text
from_vertex,to_vertex,sense,max_rise_delay_mean,max_rise_delay_sigma,max_fall_delay_mean,max_fall_delay_sigma,min_rise_delay_mean,min_rise_delay_sigma,min_fall_delay_mean,min_fall_delay_sigma
CLK,CBUF1/A,pos_unate,1.1,0.1,1.2,0.1,0.9,0.1,0.8,0.1
```
map(key: CLK, value: map(key: CBUF1/A, value: pos_unate,1.1,0.1,1.2,0.1,0.9,0.1,0.8,0.1))
需要注意的是这个形式map有个专有名词就是邻接矩阵下面也是同理

* setup_checks的map
是相反的
map(key: to_node value: map(key: from_node value: 各个数据))
例如
in [data/setup_check.csv](../data/setup_check.csv)
```text
from_vertex,to_vertex,sense,rise_constraint,fall_constraint
DFF3/CK,DFF3/D,setup_rising,0.5,0.6
```
map(key: DFF3/D, value: map(key:DFF3/CK, value: pos_unate,1.1,0.1,1.2,0.1,0.9,0.1,0.8,0.1))

* arrival_time代表的是计算的结果根据key为to_node进行存储



明白这些关于文件的读取就进行完了

回到解析中 [点击这里](./timing_analysis.md)