#include "gtest/gtest.h"
#include "list.hpp"
#include <iostream>
using namespace DataStructures;
TEST(ListTest, Constructor)
{
    List l = List<int>();
    ASSERT_EQ(l.size(), 0);
    ASSERT_EQ(l.max(), 10);
}

TEST(ListTest, Push_Back)
{
    List<int> l(2);
    ASSERT_TRUE(l.is_empty());
    EXPECT_NO_THROW(l.push_back(1));
    ASSERT_EQ(l.size(), 1);
    EXPECT_NO_THROW(l.push_back(1));
    ASSERT_EQ(l.size(), 2);
    ASSERT_EQ(l.max(), 2);
    EXPECT_NO_THROW(l.push_back(1));
    ASSERT_EQ(l.size(), 3);
    ASSERT_EQ(l.max(), 4);
    ASSERT_EQ(l[2], 1);
    EXPECT_THROW(l[10], std::out_of_range);
}

TEST(ListTest, Pop_Back)
{
    List<bool> l(5);
    l.push_back(true);
    l.push_back(true);
    ASSERT_EQ(l.size(), 2);
    ASSERT_TRUE(l.pop_back());
    ASSERT_EQ(l.size(), 1);
    ASSERT_EQ(l.max(), 2);
    ASSERT_TRUE(l.pop_back());
    ASSERT_EQ(l.size(), 0);
    ASSERT_EQ(l.max(), 1);
    EXPECT_THROW(l.pop_back(), std::exception);
}

TEST(ListTest, Empty_List)
{
    List<bool> l(0);
    EXPECT_NO_THROW(l.push_back(true));
    ASSERT_EQ(l.size(), 1);
    ASSERT_EQ(l.max(), 1);
    ASSERT_TRUE(l[0]);
}

TEST(ListTest, Insert)
{
    List<int> l(3);
    EXPECT_THROW(l.insert(2, 0), std::out_of_range);
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    EXPECT_NO_THROW(l.insert(2, 3));
    ASSERT_EQ(l[2], 3);
    ASSERT_EQ(l[3], 2);
    EXPECT_NO_THROW(l.insert(4, 4));
    ASSERT_EQ(l[4], 4);
    EXPECT_NO_THROW(l.insert(0, 5));
    ASSERT_EQ(l[0], 5);
    ASSERT_EQ(l[1], 0);
}

TEST(ListTest, Equals)
{
    List<int> l(5);
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    List<int> l2(12);
    l2.push_back(0);
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);
    ASSERT_TRUE(l == l2);
    l2[0] = 6;
    ASSERT_FALSE(l == l2);
    List<int> l3 = l;
    ASSERT_TRUE(l == l3);
    l[0] = 6;
    ASSERT_FALSE(l == l3);
}