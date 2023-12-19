//
// Created by lishuo on 2023/11/23.
//

#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <iostream>
#include "io.h"

struct Cli{
    bool is_help;
    int thread_pool_len;
    std::string edge_filename;
    std::string setup_check_filename;
    std::string startpoints_filename;
    std::string endpoints_filename;
    std::string input_global_slack_filename;

};
Cli get_cli(int argc, char *argv[], Cli c);
#endif
