#include "ip_filter.h"
#include <sstream>
#include <iostream>
#include <algorithm>

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> result;
    std::istringstream ss(str);
    std::string token;
    while (getline(ss, token, delim)) {
        result.push_back(token);
    }
    return result;
}

std::vector<int> parse_ip(const std::string& ip_str) {
    std::vector<std::string> parts = split(ip_str, '.');
    std::vector<int> ip;
    for (const auto& part : parts) {
        ip.push_back(std::stoi(part));
    }
    return ip;
}

void sort_and_print(std::vector<std::vector<int>>& ip_pool) {
    std::sort(ip_pool.begin(), ip_pool.end(), std::greater<std::vector<int>>());

    for (const auto& ip : ip_pool) {
        std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << std::endl;
    }
}
