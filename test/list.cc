#include "gtest/gtest.h"
#include "list.h"

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
    ASSERT_TRUE(l.push_back(1));
    ASSERT_EQ(l.size(), 1);
    ASSERT_TRUE(l.push_back(1));
    ASSERT_EQ(l.size(), 2);
    ASSERT_EQ(l.max(), 2);
    ASSERT_TRUE(l.push_back(1));
    ASSERT_EQ(l.size(), 3);
    ASSERT_EQ(l.max(), 4);
    ASSERT_EQ(l[2], 1);
    EXPECT_THROW(l[10], std::exception);
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
    ASSERT_TRUE(l.push_back(true));
    ASSERT_EQ(l.size(), 1);
    ASSERT_EQ(l.max(), 1);
    ASSERT_TRUE(l[0]);
}