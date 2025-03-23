#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
class Heap {
    std::vector<T> data;
public:
    void push(const T& item) { 
        data.push_back(item);
        std::push_heap(data.begin(), data.end());
    }
    T pop() {
        if(empty()) throw std::out_of_range("Heap is empty");
        std::pop_heap(data.begin(), data.end());
        T val = data.back();
        data.pop_back();
        return val;
    }
    bool empty() const { return data.empty(); }
};