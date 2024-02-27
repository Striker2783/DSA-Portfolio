#include "gtest/gtest.h"
#include "stack.hpp"
using namespace DataStructures;

class StackTest : public testing::Test
{
protected:
    Stack<int> s;
};
TEST_F(StackTest, Integration)
{
    EXPECT_THROW(s.pop(), std::exception);
    s.push(0);
    s.push(1);
    s.push(2);
    ASSERT_EQ(s.peek(), 2);
    ASSERT_EQ(s.pop(), 2);
    ASSERT_EQ(s.pop(), 1);
    ASSERT_EQ(s.pop(), 0);
    EXPECT_THROW(s.pop(), std::exception);
    EXPECT_THROW(s.peek(), std::exception);
}