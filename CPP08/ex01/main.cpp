#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void testBasicFunctionality() {
    std::cout << "=== Basic Functionality Test ===" << std::endl;
    
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    // 例外テスト - 満杯の場合
    try {
        sp.addNumber(42);
        std::cout << "Error: Exception not thrown when adding to full Span" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }
}

void testLargeNumbers() {
    std::cout << "\n=== Large Numbers Test (10,000 elements) ===" << std::endl;
    
    Span largeSpan(10000);
    
    // 10,000個のランダムな数値を追加
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(std::rand());
    }
    
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
}

void testRangeAddition() {
    std::cout << "\n=== Range Addition Test ===" << std::endl;
    
    std::vector<int> numbers;
    for (int i = 1; i <= 1000; ++i) {
        numbers.push_back(i);
    }
    
    Span sp(1000);
    sp.addRange(numbers.begin(), numbers.end());
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    // 範囲追加の例外テスト
    try {
        sp.addRange(numbers.begin(), numbers.begin() + 10);
        std::cout << "Error: Exception not thrown when adding range to full Span" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }
}

void testEdgeCases() {
    std::cout << "\n=== Edge Cases Test ===" << std::endl;
    
    // 空のSpan
    Span emptySpan(5);
    try {
        emptySpan.shortestSpan();
        std::cout << "Error: Exception not thrown for empty Span" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }
    
    // 1つの要素だけのSpan
    Span singleElementSpan(5);
    singleElementSpan.addNumber(42);
    try {
        singleElementSpan.longestSpan();
        std::cout << "Error: Exception not thrown for Span with single element" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }
    
    // 同じ値のみのSpan
    Span sameValueSpan(5);
    for (int i = 0; i < 5; ++i) {
        sameValueSpan.addNumber(42);
    }
    std::cout << "Shortest span (same values): " << sameValueSpan.shortestSpan() << std::endl;
    std::cout << "Longest span (same values): " << sameValueSpan.longestSpan() << std::endl;
}

int main() {
    testBasicFunctionality();
    testLargeNumbers();
    testRangeAddition();
    testEdgeCases();
    
    return 0;
}
