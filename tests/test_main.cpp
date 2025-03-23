#include <gtest/gtest.h>
#include <stdexcept>
#include "Queue.hpp"
#include "Heap.hpp"
#include "BinaryTree.hpp"

// ==================== Queue Tests ====================
TEST(QueueTest, InitiallyEmpty) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, PushPopSingleElement) {
    Queue<int> q;
    q.push(42);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.pop(), 42);
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, MaintainsFIFOOrder) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.pop(), 3);
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, PopEmptyThrows) {
    Queue<int> q;
    EXPECT_THROW(q.pop(), std::out_of_range);
}

// ==================== Heap Tests ====================
TEST(HeapTest, InitiallyEmpty) {
    Heap<int> h;
    EXPECT_TRUE(h.empty());
}

TEST(HeapTest, PushPopSingleElement) {
    Heap<int> h;
    h.push(5);
    EXPECT_EQ(h.pop(), 5);
    EXPECT_TRUE(h.empty());
}

TEST(HeapTest, PopsMaxElement) {
    Heap<int> h;
    h.push(3);
    h.push(1);
    h.push(4);
    h.push(2);
    EXPECT_EQ(h.pop(), 4);
    EXPECT_EQ(h.pop(), 3);
    EXPECT_EQ(h.pop(), 2);
    EXPECT_EQ(h.pop(), 1);
    EXPECT_TRUE(h.empty());
}

// ==================== BinaryTree Tests ====================
TEST(BinaryTreeTest, SearchInEmptyTree) {
    BinaryTree<int> tree;
    EXPECT_FALSE(tree.search(10));
}

TEST(BinaryTreeTest, PushAndSearch) {
    BinaryTree<int> tree;
    tree.push(10);
    EXPECT_TRUE(tree.search(10));
}

TEST(BinaryTreeTest, PopLeafNode) {
    BinaryTree<int> tree;
    tree.push(10);
    tree.push(5);
    tree.pop(5);
    EXPECT_FALSE(tree.search(5));
    EXPECT_TRUE(tree.search(10));
}

TEST(BinaryTreeTest, PopRootWithTwoChildren) {
    BinaryTree<int> tree;
    tree.push(10);
    tree.push(5);
    tree.push(15);
    tree.pop(10);
    EXPECT_FALSE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
}

// Main function
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}