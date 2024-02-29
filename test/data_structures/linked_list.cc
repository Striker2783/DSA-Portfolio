#include "gtest/gtest.h"
#include "linked_list.hpp"
using namespace DataStructures;

class LinkedListTest : public testing::Test
{
protected:
    LinkedList<int> l;
};
TEST_F(LinkedListTest, PushBack)
{
    ASSERT_EQ(l.size(), 0);
    l.push_back(0);
    ASSERT_EQ(l[0], 0);
    ASSERT_EQ(l.size(), 1);
}