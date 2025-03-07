#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {
    _elements.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _elements(other._elements) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _elements = other._elements;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_elements.size() >= _maxSize) {
        throw FullSpanException();
    }
    _elements.push_back(number);
}

int Span::shortestSpan() const {
    if (_elements.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted = _elements;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_elements.size() < 2) {
        throw NoSpanException();
    }

    int min = *std::min_element(_elements.begin(), _elements.end());
    int max = *std::max_element(_elements.begin(), _elements.end());
    
    return max - min;
}
