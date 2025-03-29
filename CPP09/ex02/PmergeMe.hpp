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
    /**
     * @brief マージ挿入ソート（Ford-Johnsonアルゴリズム）のvector実装
     * @param arr ソートする配列
     */
    void mergeInsertSortVec(std::vector<int>& arr);
    
    /**
     * @brief 配列に要素をバイナリ挿入する関数（vector用）
     * @param arr 挿入先の配列
     * @param val 挿入する値
     * @param start 探索範囲の開始インデックス
     * @param end 探索範囲の終了インデックス
     */
    void binaryInsert(std::vector<int>& arr, int val, int start, int end);
    
    // deque実装
    /**
     * @brief マージ挿入ソート（Ford-Johnsonアルゴリズム）のdeque実装
     * @param arr ソートする配列
     */
    void mergeInsertSortDeq(std::deque<int>& arr);
    
    /**
     * @brief 配列に要素をバイナリ挿入する関数（deque用）
     * @param arr 挿入先の配列
     * @param val 挿入する値
     * @param start 探索範囲の開始インデックス
     * @param end 探索範囲の終了インデックス
     */
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
