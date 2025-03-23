#pragma once

template<typename T>
class BinaryTree {
public:
    void push(const T& item);
    void pop(const T& item);
    bool search(const T& item) const { return false; } // Заглушка
};