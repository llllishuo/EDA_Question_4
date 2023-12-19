#include "io.h"
#include "line.h"
#include "DataStructure.h"
#include "Cli.h"
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <sys/stat.h>

/**
 * 按符号分割
 * @param str 目标字符串
 * @param delim 分割字符
 * @return 分割完成字符串集合
 */
std::vector<std::string> split(const std::string& str, char delim){
	std::vector<std::string> tokens;
	std::stringstream ss(str);

	std::string token;
	while(getline(ss, token, delim)){
		tokens.push_back(token);
	}
	return tokens;


}


/**
 * 根据edge data文件读取数据
 * @param filename
 * @param data
 *
 * 按每行按','分割随即读取文件到TimingAnalysis& data中
 * 同时记录每个to节点数量，其代表to节点被多少from节点连接既有多少分支
 * 将读取到的节点存储到邻接矩阵中既结构为 std::unordered_map<std::string,std::unordered_map<std::string, Edge>> 的变量中
 * 其包含两层map
 * map1: key -> from , value -> map2{ key -> to , value -> edge_data }
 */
void read_csv_to_edges(const std::string& filename, TimingAnalysis& data){

    std::ifstream file(filename, std::ios::binary);
    std::string line;
    getline(file, line);
    std::vector<char> buffer(1024 * 1024); // 1MB 缓冲区

    std::string leftover; // 存储未完整读取的行的部分
    while (file.read(buffer.data(), buffer.size()) || file.gcount() > 0) {
        std::string currentChunk = leftover + std::string(buffer.data(), file.gcount());
        std::stringstream ss(currentChunk);
        std::string line;

        while (std::getline(ss, line)) {
            if (ss.peek() != EOF) {
                std::vector<std::string> tokens = split(line, ',');
                // 处理完整的行
                process_line_edges(tokens, data);
            } else {
                leftover = line; // 保存未完整的行，以便与下一块数据一起处理
                break;
            }
        }
    }

    // 处理文件最后一行（如果有）
    if (!leftover.empty()) {
        std::vector<std::string> tokens = split(leftover, ',');
        process_line_edges(tokens, data);
    }

}



/**
 * 读取setup_check文件
 * @param filename
 * @param setup_checks
 * 按行读取文件
 * 同样使用std::unordered_map<std::string,std::unordered_map<std::string, SetupCheck>>存储数据
 * 相较于edge_data,key进行了替换
 * 由于其终点是多个起点汇聚的节点并且为方便计算slack,
 * 既只需要遍历end文件便能通过其那到汇聚在这个终点的所有起点，在根据自己的名字拼接上"/CK"得到起点节点从而达到数据计算结果
 */
void read_setup_check_data(const std::string& filename, std::unordered_map<std::string,std::unordered_map<std::string, SetupCheck>>& setup_checks) {

    std::ifstream file(filename, std::ios::binary);
    std::string line;
    getline(file, line);
    std::vector<char> buffer(1024 * 1024); // 1MB 缓冲区

    std::string leftover; // 存储未完整读取的行的部分
    while (file.read(buffer.data(), buffer.size()) || file.gcount() > 0) {
        std::string currentChunk = leftover + std::string(buffer.data(), file.gcount());
        std::stringstream ss(currentChunk);
        std::string line;

        while (std::getline(ss, line)) {
            if (ss.peek() != EOF) {
                std::vector<std::string> tokens = split(line, ',');
                // 处理完整的行
                process_line_setup_check(tokens, setup_checks);

            } else {
                leftover = line; // 保存未完整的行，以便与下一块数据一起处理
                break;
            }
        }
    }

    // 处理文件最后一行（如果有）
    if (!leftover.empty()) {
        std::vector<std::string> tokens = split(leftover, ',');
        process_line_setup_check(tokens, setup_checks);
    }
}


void read_startpoints(const std::string& filename, std::vector<std::string>& startpoints) {

    std::ifstream file(filename, std::ios::binary);
    std::string line;
    getline(file, line);
    std::vector<char> buffer(1024 * 1024); // 1MB 缓冲区

    std::string leftover; // 存储未完整读取的行的部分
    while (file.read(buffer.data(), buffer.size()) || file.gcount() > 0) {
        std::string currentChunk = leftover + std::string(buffer.data(), file.gcount());
        std::stringstream ss(currentChunk);
        std::string line;

        while (std::getline(ss, line)) {
            if (ss.peek() != EOF) {
                std::vector<std::string> tokens = split(line, ',');
                // 处理完整的行
                process_line_startpoints(startpoints, line);
            } else {
                leftover = line; // 保存未完整的行，以便与下一块数据一起处理
                break;
            }
        }
    }

    // 处理文件最后一行（如果有）
    if (!leftover.empty()) {
        std::vector<std::string> tokens = split(leftover, ',');
        process_line_startpoints(startpoints, line);
    }
}

void read_endpoints(const std::string& filename, std::vector<std::string>& endpoints) {
    std::ifstream file(filename, std::ios::binary);
    std::string line;
    getline(file, line);
    std::vector<char> buffer(1024 * 1024); // 1MB 缓冲区

    std::string leftover; // 存储未完整读取的行的部分
    while (file.read(buffer.data(), buffer.size()) || file.gcount() > 0) {
        std::string currentChunk = leftover + std::string(buffer.data(), file.gcount());
        std::stringstream ss(currentChunk);
        std::string line;

        while (std::getline(ss, line)) {
            if (ss.peek() != EOF) {
                std::vector<std::string> tokens = split(line, ',');
                // 处理完整的行
                process_line_endpoints(endpoints, line);
            } else {
                leftover = line; // 保存未完整的行，以便与下一块数据一起处理
                break;
            }
        }
    }

    // 处理文件最后一行（如果有）
    if (!leftover.empty()) {
        std::vector<std::string> tokens = split(leftover, ',');
        process_line_endpoints(endpoints, line);
    }
}

void write_to_global_slack(GlobalSlacks globalSlacks, std::string filename){
    std::string line;

    std::ofstream myfile(filename);

    if (myfile.is_open()){
        myfile << "vertex,rise_slack,fall_slack\n";
        for (std::string str: globalSlacks.endpoints){
            myfile << str <<","<< globalSlacks.Slack_Rise[str] <<","<< globalSlacks.Slack_Fall[str] <<"\n";
        }
        myfile.close();
    }
    else {
        std::cout << "could not open file" << '\n';
    }

}




