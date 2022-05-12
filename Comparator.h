#pragma once

#include <fstream>
#include <cctype>

struct Comparator {

    void report(std::ifstream& a, std::ifstream& b);
    bool is_space(char ch);

};