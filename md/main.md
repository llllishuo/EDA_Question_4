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

## 代码详讲
in [main.cpp](../main.cpp)
```c++
cli = get_cli(argc , argv , cli);

run(cli);
```

首先第一步进行命令行解析(get_cli(...));

in [common/Cli.cpp](../common/Cli.cpp)
```c++
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


```
根据赛题的格式```./example.pl -g GRAPH_CSV_FILE -c CHECK_CSV_FILE -e ENDPOINT_LIST_FILE -o SLACK_OUTPUT_FILE```进行解析
首先设置标识变量(cli_code)根据命令行输出格式从左向右逐个变量判断，一旦找到需要的“-g”、“-c”等(以及它的全称)将标识进行赋相应的值，那么在下次判断到“-g”后面的”GRAPH_CSV_FILE“时就能在else进行获取字符串，其它同理

这样命令行就解析完了，接下来就是run

go [the run()](./timing_analysis.md)
