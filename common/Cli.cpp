#include "Cli.h"
#include <string>

// ./example.pl -g GRAPH_CSV_FILE -c CHECK_CSV_FILE -e ENDPOINT_LIST_FILE -o SLACK_OUTPUT_FILE
Cli get_cli(int argc, char *argv[], Cli c){
    Cli cli = c;
    int cli_code = 0;
    if (argc == 0) return cli;
    for(int i=0; i<argc; i++)
    {
        std::string argv_str = argv[i];
        if (!argv_str.compare("-g") || !argv_str.compare("--graph-csv")) {
            cli_code = 1;
        }else if (!argv_str.compare("-c") || !argv_str.compare("--check-file")) {
            cli_code = 2;
        }else if (!argv_str.compare("-e") || !argv_str.compare("--endpoints")) {
                cli_code = 3;
        }else if (!argv_str.compare("-p") || !argv_str.compare("--startpoints")) {
                cli_code = 4;
        }else if (!argv_str.compare("-o") || !argv_str.compare("--output")) {
                cli_code = 5;
        }else if (!argv_str.compare("-t") || !argv_str.compare("--thread")) {
            cli_code = 6;
        }else{
                if (cli_code == 1){
                    cli.edge_filename = argv_str;
                }else if (cli_code == 2){
                    cli.setup_check_filename = argv_str;
                }else if (cli_code == 3){
                    cli.startpoints_filename = argv_str;
                }else if (cli_code == 4){
                    cli.endpoints_filename = argv_str;
                }else if (cli_code == 5){
                    cli.input_global_slack_filename = argv_str;
                }else if (cli_code == 6){
                    cli.thread_pool_len = stoi(argv_str);
                }else{}
        }
    }
    return cli;
}
