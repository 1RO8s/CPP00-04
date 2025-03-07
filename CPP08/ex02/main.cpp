#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>

void testBasicFunctionality() {
    std::cout << "=== Basic Functionality Test ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Stack contents using iterators: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testComparisonWithList() {
    std::cout << "\n=== Comparison with std::list ===" << std::endl;
    
    // MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "MutantStack contents: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // std::list for comparison
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testConstIterators() {
    std::cout << "\n=== Const Iterators Test ===" << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i) {
        mstack.push(i * 10);
    }
    
    const MutantStack<int> const_mstack(mstack);
    
    std::cout << "Const stack contents: ";
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testReverseIterators() {
    std::cout << "\n=== Reverse Iterators Test ===" << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i) {
        mstack.push(i * 10);
    }
    
    std::cout << "Stack contents (reverse order): ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testDifferentTypes() {
    std::cout << "\n=== Different Types Test ===" << std::endl;
    
    // String stack
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("42");
    
    std::cout << "String stack contents: ";
    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Double stack
    MutantStack<double> dblStack;
    dblStack.push(3.14);
    dblStack.push(2.71);
    dblStack.push(1.618);
    
    std::cout << "Double stack contents: ";
    for (MutantStack<double>::iterator it = dblStack.begin(); it != dblStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testComparisonWithList();
    testConstIterators();
    testReverseIterators();
    testDifferentTypes();
    
    return 0;
}
