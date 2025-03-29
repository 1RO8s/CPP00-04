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

// 入力チェック
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
    // 入力シーケンスを表示
    std::cout << "Before: ";
    for (size_t i = 0; i < _originalSequence.size(); i++) {
        std::cout << _originalSequence[i] << " ";
    }
    std::cout << std::endl;
    
    // ソート済シーケンスを表示
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

// vector用のバイナリ挿入関数
/**
 * @brief 配列に要素をバイナリ挿入（二分探索挿入）する関数
 * 
 * 二分探索アルゴリズムを使用して、ソート済み配列内の正しい位置に新しい要素を挿入します。
 * この関数は再帰的に動作し、挿入位置を対数時間で特定します。
 * 
 * @param arr   挿入先の配列（std::vector<int>）
 * @param val   挿入する値
 * @param start 探索範囲の開始インデックス（初期呼び出しでは通常0）
 * @param end   探索範囲の終了インデックス（初期呼び出しでは通常arr.size()-1）
 * 
 * @details
 * - 基底ケース: start >= endの場合、現在のstartインデックスの位置に
 *   新しい要素を挿入します（値の比較に基づいて位置を微調整）
 * - 再帰ケース: 探索範囲の中間点を計算し、中間点の値と挿入値を比較して
 *   探索範囲を半分に絞り込み、再帰的に処理を続けます
 * 
 * @time O(log n) - 位置の特定
 * @space O(log n) - 再帰呼び出しのスタック
 * 
 * @note 挿入操作自体は位置を特定した後にO(n)の時間がかかりますが、
 *       位置の特定は効率的に行われます
 */
void PmergeMe::binaryInsert(std::vector<int>& arr, int val, int start, int end) {
    if (start >= end) {
        // 挿入位置の決定
        if (arr[start] < val) {
            // 現在の要素より大きい場合、その要素の後ろに挿入
            arr.insert(arr.begin() + start + 1, val);
        } else {
            // 現在の要素以下の場合、その要素の前に挿入
            arr.insert(arr.begin() + start, val);
        }
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
/**
 * @brief 配列に要素をバイナリ挿入（二分探索挿入）する関数
 * 
 * 二分探索アルゴリズムを使用して、ソート済み配列内の正しい位置に新しい要素を挿入します。
 * この関数は再帰的に動作し、挿入位置を対数時間で特定します。
 * 
 * @param arr   挿入先の配列（std::deque<int>）
 * @param val   挿入する値
 * @param start 探索範囲の開始インデックス（初期呼び出しでは通常0）
 * @param end   探索範囲の終了インデックス（初期呼び出しでは通常arr.size()-1）
 * 
 * @details
 * - 基底ケース: start >= endの場合、現在のstartインデックスの位置に
 *   新しい要素を挿入します（値の比較に基づいて位置を微調整）
 * - 再帰ケース: 探索範囲の中間点を計算し、中間点の値と挿入値を比較して
 *   探索範囲を半分に絞り込み、再帰的に処理を続けます
 * 
 * @time O(log n) - 位置の特定
 * @space O(log n) - 再帰呼び出しのスタック
 * 
 * @note 挿入操作自体は位置を特定した後にO(n)の時間がかかりますが、
 *       位置の特定は効率的に行われます
 */
void PmergeMe::binaryInsert(std::deque<int>& arr, int val, int start, int end) {
    if (start >= end) {
        // 挿入位置の決定
        if (arr[start] < val) {
            // 現在の要素より大きい場合、その要素の後ろに挿入
            arr.insert(arr.begin() + start + 1, val);
        } else {
            // 現在の要素以下の場合、その要素の前に挿入
            arr.insert(arr.begin() + start, val);
        }
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    if (arr[mid] > val) {
        binaryInsert(arr, val, start, mid - 1);
    } else {
        binaryInsert(arr, val, mid + 1, end);
    }
}

// マージ挿入ソート vector版
/**
 * @brief マージ挿入ソート（Ford-Johnsonアルゴリズム）のvector実装
 * 
 * このアルゴリズムは以下のステップで動作します：
 * 1. 要素をペアに分割し、各ペア内で大小関係を決定
 * 2. 各ペアの大きい方の要素で「主リスト」を作成
 * 3. 主リストを再帰的にマージ挿入ソートでソート
 * 4. 各ペアの小さい方の要素（「補助リスト」）をバイナリ挿入で主リストに挿入
 * 5. 奇数個の要素がある場合、余った要素も正しい位置に挿入
 * 
 * @param arr ソートする配列（std::vector<int>）
 * 
 * @details マージ挿入ソートは理論的に最適に近い比較回数でソートが可能です。
 * 特に、比較操作が高コストな場合に効果的です。
 * 
 * @time 約 nlog(n) - nlog(log(n)) + O(n)の比較回数
 * @space O(n) - 追加の配列が必要
 */
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
    
    // 主リストの作成
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].first);
    }
    
    // 主リストをソート（再帰的にマージ挿入ソートを適用）
    mergeInsertSortVec(largerElements);
    
    // 主リストを元に新しい配列を構築
    arr.clear();
    for (size_t i = 0; i < largerElements.size(); i++) {
        arr.push_back(largerElements[i]);
    }
    
    // 補助リストを挿入
    // すべての要素をバイナリ挿入で正しい位置に挿入
    for (size_t i = 0; i < pairs.size(); i++) {
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

// マージ挿入ソート deque版
/**
 * @brief マージ挿入ソート（Ford-Johnsonアルゴリズム）のdeque実装
 * 
 * このアルゴリズムは以下のステップで動作します：
 * 1. 要素をペアに分割し、各ペア内で大小関係を決定
 * 2. 各ペアの大きい方の要素で「主リスト」を作成
 * 3. 主リストを再帰的にマージ挿入ソートでソート
 * 4. 各ペアの小さい方の要素（「補助リスト」）をバイナリ挿入で主リストに挿入
 * 5. 奇数個の要素がある場合、余った要素も正しい位置に挿入
 * 
 * @param arr ソートする配列（std::deque<int>）
 * 
 * @details マージ挿入ソートは理論的に最適に近い比較回数でソートが可能です。
 * 特に、比較操作が高コストな場合に効果的です。
 * vector実装との性能比較のために実装されています。
 * 
 * @time 約 nlog(n) - nlog(log(n)) + O(n)の比較回数
 * @space O(n) - 追加の配列が必要
 */
void PmergeMe::mergeInsertSortDeq(std::deque<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    
    // 要素をペアに分ける
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
    
    // 主リストの作成
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].first);
    }
    
    // 主リストをソート（再帰的にマージ挿入ソートを適用）
    mergeInsertSortDeq(largerElements);
    
    // 主リストを元に新しい配列を構築
    arr.clear();
    for (size_t i = 0; i < largerElements.size(); i++) {
        arr.push_back(largerElements[i]);
    }
    
    // 補助リストを挿入
    // すべての要素をバイナリ挿入で正しい位置に挿入
    for (size_t i = 0; i < pairs.size(); i++) {
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
