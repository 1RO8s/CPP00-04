#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {
    try {
        PmergeMe sorter;
        sorter.parseArgs(argc, argv);
        sorter.sort();
        sorter.displayResults();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
} 
