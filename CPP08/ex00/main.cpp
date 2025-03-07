#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    // vectorのテスト
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "Testing vector: Finding 3..." << std::endl;
    std::vector<int>::iterator it = easyfind(vec, 3);
    if (it != vec.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    std::cout << "Testing vector: Finding 10..." << std::endl;
    it = easyfind(vec, 10);
    if (it != vec.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    // listのテスト
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    std::cout << "\nTesting list: Finding 30..." << std::endl;
    std::list<int>::iterator lst_it = easyfind(lst, 30);
    if (lst_it != lst.end()) {
        std::cout << "Found: " << *lst_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    std::cout << "Testing list: Finding 100..." << std::endl;
    lst_it = easyfind(lst, 100);
    if (lst_it != lst.end()) {
        std::cout << "Found: " << *lst_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    // dequeのテスト
    std::deque<int> deq;
    deq.push_back(15);
    deq.push_back(25);
    deq.push_back(35);
    deq.push_back(45);
    deq.push_back(55);

    std::cout << "\nTesting deque: Finding 35..." << std::endl;
    std::deque<int>::iterator deq_it = easyfind(deq, 35);
    if (deq_it != deq.end()) {
        std::cout << "Found: " << *deq_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    std::cout << "Testing deque: Finding 0..." << std::endl;
    deq_it = easyfind(deq, 0);
    if (deq_it != deq.end()) {
        std::cout << "Found: " << *deq_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    // const_iteratorのテスト
    const std::vector<int> const_vec = vec;
    std::cout << "\nTesting const vector: Finding 3..." << std::endl;
    std::vector<int>::const_iterator const_it = easyfind(const_vec, 3);
    if (const_it != const_vec.end()) {
        std::cout << "Found: " << *const_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    // const_iteratorのテスト
    const std::list<int> const_lst = lst;
    std::cout << "\nTesting const list: Finding 30..." << std::endl;
    std::list<int>::const_iterator const_lst_it = easyfind(const_lst, 30);
    if (const_lst_it != const_lst.end()) {
        std::cout << "Found: " << *const_lst_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }

    // const_iteratorのテスト
    const std::deque<int> const_deq = deq;
    std::cout << "\nTesting const deque: Finding 35..." << std::endl;
    std::deque<int>::const_iterator const_deq_it = easyfind(const_deq, 35);
    if (const_deq_it != const_deq.end()) {
        std::cout << "Found: " << *const_deq_it << std::endl;
    } else {
        std::cout << "Value not found in container" << std::endl;
    }
    
    return 0;   
}
