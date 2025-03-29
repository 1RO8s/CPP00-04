#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <sys/time.h>

class PmergeMe {
private:
    // vector実装
    void mergeInsertSortVec(std::vector<int>& arr);
    void recursiveSortVec(std::vector<int>& arr);
    std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
    void binaryInsert(std::vector<int>& arr, int val, int start, int end);
    
    // deque実装
    void mergeInsertSortDeq(std::deque<int>& arr);
    void recursiveSortDeq(std::deque<int>& arr);
    std::deque<int> merge(const std::deque<int>& left, const std::deque<int>& right);
    void binaryInsert(std::deque<int>& arr, int val, int start, int end);

    std::vector<int> _vec;
    std::deque<int> _deq;
    std::vector<int> _originalSequence;
    double _vecSortTime;
    double _deqSortTime;
    double getTimeInMicroseconds();
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void parseArgs(int argc, char** argv);
    void sort();
    void displayResults() const;

    const std::vector<int>& getOriginalSequence() const;
    const std::vector<int>& getSortedVec() const;
    const std::deque<int>& getSortedDeq() const;
    double getVecSortTime() const;
    double getDeqSortTime() const;
};

#endif
