#pragma once
#include <stdexcept>

template<typename T>
class Heap {
public:
    void push(const T& item);
    T pop();
    bool empty() const { return true; } // Заглушка
};