#include "gtest/gtest.h"
#include "list.h"

TEST(ListTest, Constructor)
{
    List<int> l = List<int>();
    ASSERT_EQ(l.size(), 0);
    ASSERT_EQ(l.max(), 10);
}

class ListTest : public testing::Test
{
protected:
    void SetUp() override
    {
        q.push_back(1);
    }
    List<int> q = List<int>();
    List<int> q1 = List<int>(1);
};