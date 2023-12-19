# 2023（第五届）集成电路EDA设计精英挑战赛

## 小组: eda230336

### 环境
- Cmake
- C++20

### 输入输出
- in build/
./Analysis_of_time_series_problems 
[-g|--graph-csv] : graph.csv
[-c|--check-file] : setup_check.csv
[-e|--endpoints] : endpoint.list
[-p|--startpoints] : startpoint.list
[-o|--output] : slack.csv
[-t|--thread] : 线程数量
#### win:
```shell
.\Analysis_of_time_series_problems.exe -g data/case1/case1.graph.csv -c data/case1/case1.setup_check.csv  -e data/case1/case1.endpoints.list -p data/case1/case1.startpoints.list -o data/case1/case1.global_slack.csv -t 4
```
#### linux:
```shell
mkdir build
cd build
cmake ..
make
./Analysis_of_time_series_problems -g ../data/case1/case1.graph.csv -c ../data/case1/case1.setup_check.csv  -e ../data/case1/case1.endpoints.list -p ../data/case1/case1.startpoints.list -o ../data/case1/case1.global_slack.csv -t 2
```
#### 结果将打印到路径: [input_global_slack_filename] 

### 运行流程

1. main()
2. timing_analysis.run()
3. io.read()
4. timing_analysis.perform_timing_analysis()
   - timing_analysis.search_node_to_end()
   - timing_analysis.calculate_arrival_times()
   - ...
   - timing_analysis.search_node_to_end()
   - timing_analysis.calculate_arrival_times()
5. timing_analysis.perform_operation_global_slack()
6. io.write_to_global_slack()
7. over



