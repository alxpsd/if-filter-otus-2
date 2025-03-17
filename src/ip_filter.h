#pragma once
#include <vector>
#include <string>

// Разделение строки по заданному символу-разделителю
std::vector<std::string> split(const std::string& str, char delim);

// Преобразование строки с IP-адресом в вектор чисел
std::vector<int> parse_ip(const std::string& ip_str);

// Сортировка IP-адресов в обратном лексикографическом порядке и их вывод
void sort_and_print(std::vector<std::vector<int>>& ip_pool);
