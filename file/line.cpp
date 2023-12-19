#include <iostream>
#include "line.h"

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



void  process_line_setup_check(std::vector<std::string> tokens,std::unordered_map<std::string,std::unordered_map<std::string, SetupCheck>>& setup_checks){
    SetupCheck to_from_setupcheck;
    std::unordered_map<std::string, SetupCheck> from_and_check;
    std::string from_vertex = tokens[0];
    std::string to_vertex = tokens[1];
    to_from_setupcheck.sense = tokens[2];
    to_from_setupcheck.rise_constraint = std::stod(tokens[3]);
    to_from_setupcheck.fall_constraint = std::stod(tokens[4]);
    from_and_check[from_vertex] = to_from_setupcheck;
    setup_checks[to_vertex] = from_and_check;
}

void  process_line_startpoints(std::vector<std::string>& startpoints, std::string line){
    std::string startpoint;
    startpoint = line;
    startpoints.push_back(startpoint);

}


void  process_line_endpoints(std::vector<std::string>& startpoints, std::string line){
    std::string startpoint;
    startpoint = line;
    startpoints.push_back(startpoint);

}

