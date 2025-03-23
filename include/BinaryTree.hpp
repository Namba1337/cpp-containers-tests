#pragma once
#include <memory>

template<typename T>
class BinaryTree {
    struct Node {
        T value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node(const T& v) : value(v) {}
    };
    
    std::unique_ptr<Node> root;
    
    bool search(const Node* node, const T& item) const {
        if(!node) return false;
        if(item == node->value) return true;
        return search(node->left.get(), item) || search(node->right.get(), item);
    }
    
public:
    void push(const T& item) {
        if(!root) {
            root = std::make_unique<Node>(item);
            return;
        }
        // Простейшая реализация без балансировки
        Node* current = root.get();
        while(true) {
            if(item < current->value) {
                if(current->left) current = current->left.get();
                else { current->left = std::make_unique<Node>(item); break; }
            } else {
                if(current->right) current = current->right.get();
                else { current->right = std::make_unique<Node>(item); break; }
            }
        }
    }
    
    bool search(const T& item) const {
        return search(root.get(), item);
    }
    
    void pop(const T& item) {
        // Заглушка для тестов
    }
};