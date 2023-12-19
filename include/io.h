#ifndef IO_H
#define IO_H

#include "DataStructure.h"

std::vector<std::string> split(const std::string& str, char delim);
void read_csv_to_edges(const std::string& filename, TimingAnalysis& data);
void read_setup_check_data(const std::string& filename, std::unordered_map<std::string,std::unordered_map<std::string, SetupCheck>>& setup_checks);
void read_startpoints(const std::string& filename, std::vector<std::string>& startpoints);
void read_endpoints(const std::string& filename, std::vector<std::string>& endpoints);
void write_to_global_slack(GlobalSlacks globalSlacks, std::string filename);



#endif


