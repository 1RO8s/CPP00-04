#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN {
private:
    std::stack<int> _stack;
    
    // 演算子かどうかをチェックする
    bool isOperator(char c) const;
    
    // 数字かどうかをチェックする
    bool isDigit(char c) const;
    
    // 演算を実行する
    void performOperation(char op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    // RPN式を評価する
    int evaluate(const std::string& expression);
};

#endif // RPN_HPP 
