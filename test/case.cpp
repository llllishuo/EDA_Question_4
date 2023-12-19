#include <ctime>
#include "case.h"
#include "timing_Analysis.h"

void test_case(
        int id,
        std::string edge_filename,
        std::string setup_check_filename,
        std::string startpoints_filename,
        std::string endpoints_filename,
        std::string input_global_slack_filename,
        int thread_size
){

    Cli cli;
    cli.edge_filename = edge_filename,
    cli.setup_check_filename = setup_check_filename,
    cli.startpoints_filename = startpoints_filename,
    cli.endpoints_filename = endpoints_filename,
    cli.input_global_slack_filename = input_global_slack_filename;
    cli.thread_pool_len = thread_size;

    std::time_t t_bef = std::time(0);

    run(cli);
    
    std::time_t t_aft = std::time(0);
    std::cout << "test_case(id: "<< id <<"): time = " << difftime(t_aft , t_bef) << std::endl;
    

}