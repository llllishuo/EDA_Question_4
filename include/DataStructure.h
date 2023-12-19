

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H


#include <string>
#include <vector>
#include <unordered_map>

static double ClockPeriod = 10.0;
static int N = 3;
struct Edge {
    std::string from_vertex;
    std::string to_vertex;
    std::string sense;
    double max_rise_delay_mean;
    double max_rise_delay_sigma;
    double max_fall_delay_mean;
    double max_fall_delay_sigma;
    double min_rise_delay_mean;
    double min_rise_delay_sigma;
    double min_fall_delay_mean;
    double min_fall_delay_sigma;
};
struct ArrivalTime {
    std::vector<double>  node_data_max_rise_delay_mean;
    std::vector<double>  node_data_max_fall_delay_mean;
    std::vector<double>  node_data_min_rise_delay_mean;
    std::vector<double>  node_data_min_fall_delay_mean;
    std::vector<double>  node_data_max_rise_delay_sigma;
    std::vector<double>  node_data_max_fall_delay_sigma;
    std::vector<double>  node_data_min_rise_delay_sigma;
    std::vector<double>  node_data_min_fall_delay_sigma;
    std::vector<double> max_rise;
    std::vector<double> max_fall;
    std::vector<double> min_rise;
    std::vector<double> min_fall;
};

struct SetupCheck {

    std::string sense;
    double rise_constraint;
    double fall_constraint;
};





struct Node{
    std::string from_vertex;
    std::string to_vertex;


};


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


struct GlobalSlacks{
    std::vector<std::string> endpoints;
    std::unordered_map<std::string, double> Slack_Rise;
    std::unordered_map<std::string, double> Slack_Fall;
    std::unordered_map<std::string, double> req_Time;
    std::unordered_map<std::string, double> arr_Time;
    std::unordered_map<std::string, double> global_slacks;

};
#endif
