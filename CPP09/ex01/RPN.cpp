#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isDigit(char c) const {
    return (c >= '0' && c <= '9');
}

void RPN::performOperation(char op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: insufficient numbers for operation");
    }
    
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
    
    switch (op) {
        case '+':
            _stack.push(a + b);
            break;
        case '-':
            _stack.push(a - b);
            break;
        case '*':
            _stack.push(a * b);
            break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            _stack.push(a / b);
            break;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}

int RPN::evaluate(const std::string& expression) {
    // スタックをクリア
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        // トークンが単一の文字かチェック
        if (token.length() != 1) {
            // 複数桁の数値かチェック
            bool isNumber = true;
            for (size_t i = 0; i < token.length(); i++) {
                if (!isDigit(token[i])) {
                    isNumber = false;
                    break;
                }
            }
            
            if (isNumber) {
                int value = std::atoi(token.c_str());
                if (value >= 10) {
                    throw std::runtime_error("Error: number must be less than 10");
                }
                _stack.push(value);
            } else {
                throw std::runtime_error("Error: invalid token: " + token);
            }
            continue;
        }
        
        char c = token[0];
        
        if (isDigit(c)) {
            _stack.push(c - '0');
        } else if (isOperator(c)) {
            performOperation(c);
        } else if (c != ' ' && c != '\t') {
            throw std::runtime_error("Error: invalid character: " + token);
        }
    }
    
    if (_stack.empty()) {
        throw std::runtime_error("Error: no result");
    }
    
    if (_stack.size() != 1) {
        throw std::runtime_error("Error: incomplete expression");
    }
    
    return _stack.top();
} 
