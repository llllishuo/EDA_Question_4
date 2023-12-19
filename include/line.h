//
// Created by lishuo on 2023/11/28.
//

#ifndef LINE_H
#define LINE_H


#include "DataStructure.h"
#include <string>
#include <vector>


void  process_line_edges(std::vector<std::string> tokens,TimingAnalysis& data);
void  process_line_setup_check(std::vector<std::string> tokens,std::unordered_map<std::string,std::unordered_map<std::string, SetupCheck>>& setup_checks);
void  process_line_startpoints(std::vector<std::string>& startpoints, std::string line);
void  process_line_endpoints(std::vector<std::string>& startpoints, std::string line);


#endif
