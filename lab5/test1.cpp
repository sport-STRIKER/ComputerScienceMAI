#include "include/allocator.h"
#include "include/list.h"
#include "include/iterator.h"

#include <gtest/gtest.h>
#include <map>
#include <vector>

TEST(allocator, Base) {
    Allocator<int> allocator;
    int* ptr = allocator.allocate(1);
    allocator.deallocate(ptr, 1);
    
    SUCCEED();
}

TEST(allocator, BaseWithValues) {
    Allocator<int> allocator;
    int* ptr = allocator.allocate(1);
    allocator.construct(ptr, 8);
    allocator.destroy(ptr);
    allocator.deallocate(ptr, 1);

    SUCCEED();
}

TEST(allocator, ManyAlloc) {
    Allocator<double> allocator;
    double* ptr = allocator.allocate(1e4);
    allocator.deallocate(ptr, 1e4);

    SUCCEED();
}

TEST(allocator, CheckToMap)
{
    std::map<int, uint64_t, std::less<uint64_t>, Allocator<std::pair<const int, uint64_t>>> test;
    for (size_t i = 0; i < 100; ++i) {
        test[i] = i;
    }

    SUCCEED();
}

TEST(allocator, TooMoreArgs)
{
    Allocator<double> allocator;
    double* ptr = allocator.allocate(10);
    double value = 5;

    EXPECT_THROW(allocator.deallocate(&value, 1), std::logic_error);
}

TEST(node, ConstrBase) {
    ASSERT_NO_THROW(Node<int> node);
}

TEST(node, ConstrValue) {
    ASSERT_NO_THROW(Node<int> node(3));
}

TEST(node, ConstrValue2) {
    ASSERT_NO_THROW(Node<double> node(3.0));
}

TEST(node, ConstrValue3) {
    ASSERT_NO_THROW(Node<const char*> node("abcd"));
}

TEST(iterators, ConstrBase) {
    ASSERT_NO_THROW(ConstIterator<int> it1);
    ASSERT_NO_THROW(Iterator<float> it2);
}

TEST(iterators, ConstrValue) {
    Node<int> node{1};

    ASSERT_NO_THROW(ConstIterator<int> it1(&node));
    ASSERT_NO_THROW(Iterator<int> it2(&node));
}

TEST(iterators, ConstrCopyMove) {
    ConstIterator<int> it1;
    Iterator<int> it2;

    ASSERT_NO_THROW(ConstIterator<int> it11(it1));
    ASSERT_NO_THROW(Iterator<int> it22(std::move(it2)));
}

TEST(iterators, ConstrCopyMove2) {
    Node<int> node{1};
    ConstIterator<int> it1(&node);
    Iterator<int> it2(&node);

    ASSERT_NO_THROW(ConstIterator<int> it11(it1));
    ASSERT_NO_THROW(Iterator<int> it22(std::move(it2)));
}

TEST(iterators, OperatorCopyMove) {
    Node<int> node{1};
    ConstIterator<int> it1(&node);
    Iterator<int> it2(&node);
    Node<int> node2{2};
    ConstIterator<int> it11(&node2);
    Iterator<int> it22(&node2);
    it11 = it1;
    it22 = std::move(it2);
    Iterator<int> it3(&node);

    ASSERT_TRUE(it11 == it1 && it22 == it3);
}

TEST(list, ConstrBase) {
    List<int, Allocator<Node<int>>> list;
    
    SUCCEED();
}

TEST(list, ConstrInitList) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    
    SUCCEED();
}

TEST(list, IterBeginCbegin) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    auto it = list.begin();
    auto it2 = list.cbegin();

    ASSERT_TRUE(*it == *it2 && *it == 1);
}

TEST(list, IterPlus) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    auto it = list.begin();

    ASSERT_TRUE(*(++it) == 2 && *(it++) == 2);
}

TEST(list, FrontBack) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};

    ASSERT_TRUE(list.front() == 1 && list.back() == 5);
}

TEST(list, IterEndCend) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    auto it = list.end();
    auto it2 = list.cend();

    ASSERT_TRUE(it == nullptr && it2 == nullptr);
}

TEST(list, Size) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};

    ASSERT_TRUE(list.size() == 5);
}

TEST(list, Empty) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};

    ASSERT_FALSE(list.empty());
}

TEST(list, Clear) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    list.clear();

    ASSERT_TRUE(list.size() == 0);
}

TEST(list, Push) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    list.push_back(0);
    list.push_front(6);

    ASSERT_TRUE(list.front() == 6 && list.back() == 0 && list.size() == 7);
}

TEST(list, Pop) {
    List<int, Allocator<Node<int>>> list{1, 2, 3, 4, 5};
    list.pop_back();
    list.pop_front();

    ASSERT_TRUE(list.front() == 2 && list.back() == 4 && list.size() == 3);
}

TEST(list, PopError) {
    List<float, Allocator<Node<float>>> list;

    EXPECT_THROW(list.pop_back(), std::range_error);
    EXPECT_THROW(list.pop_front(), std::range_error);
    EXPECT_THROW(list.front(), std::range_error);
    EXPECT_THROW(list.back(), std::range_error);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
