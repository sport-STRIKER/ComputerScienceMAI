#include <gtest/gtest.h>
#include "CheckStr.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(CheckStr("()"));
}

TEST(test_02, basic_test_set)
{
    ASSERT_FALSE(CheckStr("()))))"));
}

TEST(test_03, basic_test_set)
{
    ASSERT_FALSE(CheckStr("(0"));
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(CheckStr(""));
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(CheckStr("(())()()(())"));
}

TEST(test_06, basic_test_set)
{
    ASSERT_FALSE(CheckStr("))(())"));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
