#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _elements;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // メンバ関数
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    // 範囲追加用テンプレート関数
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int distance = std::distance(begin, end);
        if (_elements.size() + distance > _maxSize) {
            throw std::out_of_range("Cannot add range: would exceed maximum size");
        }
        _elements.insert(_elements.end(), begin, end);
    }

    // 例外クラス
    class FullSpanException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is already full";
        }
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Cannot calculate span with less than 2 elements";
        }
    };
};

#endif
