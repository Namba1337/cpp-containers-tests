#pragma once
#include <stdexcept>
#include <list>

template<typename T>
class Queue {
    std::list<T> data;
public:
    void push(const T& item) { data.push_back(item); }
    T pop() { 
        if(empty()) throw std::out_of_range("Queue is empty");
        T val = data.front();
        data.pop_front();
        return val;
    }
    bool empty() const { return data.empty(); }
};