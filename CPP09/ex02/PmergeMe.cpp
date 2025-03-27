#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecSortTime(0), _deqSortTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : 
    _vec(other._vec), 
    _deq(other._deq), 
    _originalSequence(other._originalSequence),
    _vecSortTime(other._vecSortTime),
    _deqSortTime(other._deqSortTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        _originalSequence = other._originalSequence;
        _vecSortTime = other._vecSortTime;
        _deqSortTime = other._deqSortTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// 引数の解析と処理
void PmergeMe::parseArgs(int argc, char** argv) {
    if (argc <= 1) {
        throw std::invalid_argument("引数が足りません。正の整数のシーケンスを入力してください。");
    }
    
    _originalSequence.clear();
    _vec.clear();
    _deq.clear();
    
    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int value;
        
        if (!(iss >> value) || !iss.eof() || value <= 0) {
            throw std::invalid_argument("引数には正の整数のみ指定できます: " + std::string(argv[i]));
        }
        
        if (value > INT_MAX) {
            throw std::overflow_error("整数の範囲を超えています: " + std::string(argv[i]));
        }
        
        _originalSequence.push_back(value);
        _vec.push_back(value);
        _deq.push_back(value);
    }
}

// 時間計測用
double PmergeMe::getTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// ソートの実行
void PmergeMe::sort() {
    // vectorのソート
    double startTime = getTimeInMicroseconds();
    mergeInsertSortVec(_vec);
    _vecSortTime = getTimeInMicroseconds() - startTime;
    
    // dequeのソート
    startTime = getTimeInMicroseconds();
    mergeInsertSortDeq(_deq);
    _deqSortTime = getTimeInMicroseconds() - startTime;
}

// 結果の表示
void PmergeMe::displayResults() const {
    // 元のシーケンスを表示
    std::cout << "Before: ";
    for (size_t i = 0; i < _originalSequence.size(); i++) {
        std::cout << _originalSequence[i] << " ";
    }
    std::cout << std::endl;
    
    // ソート後のシーケンスを表示
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
    
    // 処理時間を表示
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << _vecSortTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << _deqSortTime << " us" << std::endl;
}

// vector用のマージ関数
std::vector<int> PmergeMe::merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    size_t leftIdx = 0, rightIdx = 0;
    
    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] <= right[rightIdx]) {
            result.push_back(left[leftIdx]);
            leftIdx++;
        } else {
            result.push_back(right[rightIdx]);
            rightIdx++;
        }
    }
    
    // 残りの要素を追加
    while (leftIdx < left.size()) {
        result.push_back(left[leftIdx]);
        leftIdx++;
    }
    
    while (rightIdx < right.size()) {
        result.push_back(right[rightIdx]);
        rightIdx++;
    }
    
    return result;
}

// deque用のマージ関数
std::deque<int> PmergeMe::merge(const std::deque<int>& left, const std::deque<int>& right) {
    std::deque<int> result;
    size_t leftIdx = 0, rightIdx = 0;
    
    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] <= right[rightIdx]) {
            result.push_back(left[leftIdx]);
            leftIdx++;
        } else {
            result.push_back(right[rightIdx]);
            rightIdx++;
        }
    }
    
    // 残りの要素を追加
    while (leftIdx < left.size()) {
        result.push_back(left[leftIdx]);
        leftIdx++;
    }
    
    while (rightIdx < right.size()) {
        result.push_back(right[rightIdx]);
        rightIdx++;
    }
    
    return result;
}

// vector用のバイナリ挿入関数
void PmergeMe::binaryInsert(std::vector<int>& arr, int val, int start, int end) {
    if (start >= end) {
        arr.insert(arr.begin() + start + (arr[start] < val), val);
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    if (arr[mid] > val) {
        binaryInsert(arr, val, start, mid - 1);
    } else {
        binaryInsert(arr, val, mid + 1, end);
    }
}

// deque用のバイナリ挿入関数
void PmergeMe::binaryInsert(std::deque<int>& arr, int val, int start, int end) {
    if (start >= end) {
        arr.insert(arr.begin() + start + (arr[start] < val), val);
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    if (arr[mid] > val) {
        binaryInsert(arr, val, start, mid - 1);
    } else {
        binaryInsert(arr, val, mid + 1, end);
    }
}

// vector用の再帰的ソート関数
void PmergeMe::recursiveSortVec(std::vector<int>& arr) {
    size_t size = arr.size();
    
    if (size <= 1) {
        return;
    }
    
    // 配列を2つに分割
    std::vector<int> left;
    std::vector<int> right;
    
    for (size_t i = 0; i < size / 2; i++) {
        left.push_back(arr[i]);
    }
    
    for (size_t i = size / 2; i < size; i++) {
        right.push_back(arr[i]);
    }
    
    // 再帰的にソート
    recursiveSortVec(left);
    recursiveSortVec(right);
    
    // マージ
    arr = merge(left, right);
}

// deque用の再帰的ソート関数
void PmergeMe::recursiveSortDeq(std::deque<int>& arr) {
    size_t size = arr.size();
    
    if (size <= 1) {
        return;
    }
    
    // 配列を2つに分割
    std::deque<int> left;
    std::deque<int> right;
    
    for (size_t i = 0; i < size / 2; i++) {
        left.push_back(arr[i]);
    }
    
    for (size_t i = size / 2; i < size; i++) {
        right.push_back(arr[i]);
    }
    
    // 再帰的にソート
    recursiveSortDeq(left);
    recursiveSortDeq(right);
    
    // マージ
    arr = merge(left, right);
}

// Ford-Johnsonアルゴリズム（マージ挿入ソート）- vector実装
void PmergeMe::mergeInsertSortVec(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    
    // ステップ1: 要素をペアに分ける
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddElement = 0;
    
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size()) {
            int a = arr[i];
            int b = arr[i + 1];
            pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
        } else {
            // 奇数個の場合、最後の要素を保存
            hasOdd = true;
            oddElement = arr[i];
        }
    }
    
    // ステップ2: ペアの大きい方をソート
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].first);
    }
    
    recursiveSortVec(largerElements);
    
    // ステップ3: ソートされた大きい要素から新しい配列を構築
    arr.clear();
    for (size_t i = 0; i < largerElements.size(); i++) {
        arr.push_back(largerElements[i]);
    }
    
    // ステップ4: 小さい要素を挿入
    // 最初のペアの小さい方は常に最初に挿入
    if (!pairs.empty()) {
        arr.insert(arr.begin(), pairs[0].second);
    }
    
    // 残りの小さい要素をバイナリ挿入
    for (size_t i = 1; i < pairs.size(); i++) {
        int element = pairs[i].second;
        if (arr.empty()) {
            arr.push_back(element);
        } else {
            binaryInsert(arr, element, 0, arr.size() - 1);
        }
    }
    
    // 奇数個の要素がある場合、最後の要素を挿入
    if (hasOdd) {
        if (arr.empty()) {
            arr.push_back(oddElement);
        } else {
            binaryInsert(arr, oddElement, 0, arr.size() - 1);
        }
    }
}

// Ford-Johnsonアルゴリズム（マージ挿入ソート）- deque実装
void PmergeMe::mergeInsertSortDeq(std::deque<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    
    // ステップ1: 要素をペアに分ける
    std::deque<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddElement = 0;
    
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size()) {
            int a = arr[i];
            int b = arr[i + 1];
            pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
        } else {
            // 奇数個の場合、最後の要素を保存
            hasOdd = true;
            oddElement = arr[i];
        }
    }
    
    // ステップ2: ペアの大きい方をソート
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].first);
    }
    
    recursiveSortDeq(largerElements);
    
    // ステップ3: ソートされた大きい要素から新しい配列を構築
    arr.clear();
    for (size_t i = 0; i < largerElements.size(); i++) {
        arr.push_back(largerElements[i]);
    }
    
    // ステップ4: 小さい要素を挿入
    // 最初のペアの小さい方は常に最初に挿入
    if (!pairs.empty()) {
        arr.insert(arr.begin(), pairs[0].second);
    }
    
    // 残りの小さい要素をバイナリ挿入
    for (size_t i = 1; i < pairs.size(); i++) {
        int element = pairs[i].second;
        if (arr.empty()) {
            arr.push_back(element);
        } else {
            binaryInsert(arr, element, 0, arr.size() - 1);
        }
    }
    
    // 奇数個の要素がある場合、最後の要素を挿入
    if (hasOdd) {
        if (arr.empty()) {
            arr.push_back(oddElement);
        } else {
            binaryInsert(arr, oddElement, 0, arr.size() - 1);
        }
    }
}

// ゲッター
const std::vector<int>& PmergeMe::getOriginalSequence() const {
    return _originalSequence;
}

const std::vector<int>& PmergeMe::getSortedVec() const {
    return _vec;
}

const std::deque<int>& PmergeMe::getSortedDeq() const {
    return _deq;
}

double PmergeMe::getVecSortTime() const {
    return _vecSortTime;
}

double PmergeMe::getDeqSortTime() const {
    return _deqSortTime;
} 
