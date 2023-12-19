#include "io.h"
#include "timing_Analysis.h"
#include "Cli.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include "case.h"

void test(int,int);

int main(int argc, char *argv[]) {

    Cli cli;
    cli = get_cli(argc , argv , cli);

    std::time_t t_bef = std::time(0);
    std::cout<< "--------------------" << std::endl;
    std::cout<< "graph-csv = " << cli.edge_filename << std::endl;
    std::cout<< "check-file = " << cli.setup_check_filename << std::endl;
    std::cout<< "start-points = " << cli.startpoints_filename << std::endl;
    std::cout<< "endpoints = " << cli.endpoints_filename << std::endl;
    std::cout<< "output = " << cli.input_global_slack_filename << std::endl;
    std::cout<< "thread-size = " << cli.thread_pool_len<< std::endl;
    std::cout<< "--------------------" << std::endl;
    std::cout << "--run..." << std::endl;
    run(cli);
    std::time_t t_aft = std::time(0);
    std::cout << "--run time = " << difftime(t_aft , t_bef) << std::endl;
    std::cout << "--end..." << std::endl;

    return 0;
}

void test(int i, int thread_size){


    std::string test_name = "case" + std::to_string(i);
    std::string edge_filename = "../data/"+ test_name +"/" + test_name +".graph.csv";
    std::string setup_check_filename = "../data/"+ test_name +"/" + test_name +".setup_check.csv";
    std::string startpoints_filename = "../data/"+ test_name +"/" + test_name +".startpoints.list";
    std::string endpoints_filename = "../data/"+ test_name +"/" + test_name +".endpoints.list";
    std::string input_global_slack_filename = "../data/"+ test_name +"/" + test_name +".global_slack.csv";
    test_case(i,edge_filename,setup_check_filename,startpoints_filename,endpoints_filename,input_global_slack_filename,thread_size);


}




