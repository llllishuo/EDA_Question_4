//
// Created by lishuo on 2023/11/23.
//

#ifndef CASE_H
#define CASE_H

#include "DataStructure.h"
#include "Cli.h"

void test_case(
        int id,
        std::string edge_filename,
        std::string setup_check_filename,
        std::string startpoints_filename,
        std::string endpoints_filename,
        std::string input_global_slack_filename,
        int thread_size
);

#endif
