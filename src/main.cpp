#include "ip_filter.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::vector<int>> ip_pool;
    std::string line;
    
    while (std::getline(std::cin, line)) {
        std::vector<std::string> parts = split(line, '\t');
        if (!parts.empty()) {
            ip_pool.push_back(parse_ip(parts[0]));
        }
    }

    sort_and_print(ip_pool);
    return 0;
}
