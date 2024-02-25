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
    l.push_back(1);
    ASSERT_EQ(l.size(), 1);
    l.push_back(1);
    ASSERT_EQ(l.size(), 2);
    ASSERT_EQ(l.max(), 2);
    l.push_back(1);
    ASSERT_EQ(l.size(), 3);
    ASSERT_EQ(l.max(), 4);
}