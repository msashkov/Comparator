#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Comparator.h"


int main(int argc, char** argv) {

    if (argc != 3) {
        std::cout << "The count of arguments is incorrect!" << std::endl;
        return 1;
    }

    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);

    if (!file1.is_open() || !file2.is_open()) {
        throw std::invalid_argument("Wrong file names!");
    }

    Comparator c;

    try {
        c.report(file1, file2);
    }
    catch (std::out_of_range& ex) {
        std::cout << "out_of_range: " << ex.what() << std::endl;
    }
    

    return 0;

}