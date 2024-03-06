#include "include/octal.h"

#include <gtest/gtest.h>

TEST(test_01, defaultConstructor)
{
    Octal o;
    std::string s;
    o.convertToString(s);
    EXPECT_TRUE(s == "0");
}

TEST(test_01, fillConstructor)
{
    Octal o(3);
    std::string s;
    o.convertToString(s);
    EXPECT_TRUE(s == "0");
}

TEST(test_01, fillConstructor2)
{
    Octal o(3, '2');
    std::string s;
    o.convertToString(s);
    EXPECT_TRUE(s == "222");
}

TEST(test_01, initializerListConstructor)
{
    Octal o{'2', '0', '1'};
    std::string s;
    o.convertToString(s);
    EXPECT_TRUE(s == "201");
}

TEST(test_01, copyStringConstructor)
{
    Octal o("201");
    std::string s;
    o.convertToString(s);
    EXPECT_TRUE(s == "201");
}

TEST(test_01, copyConstructor)
{
    Octal o{'2', '0', '1'};
    Octal o2(o);
    std::string s;
    o2.convertToString(s);
    EXPECT_TRUE(s == "201");
}

TEST(test_01, moveConstructor)
{
    Octal o1{'2', '0', '1'};
    Octal o2{'1', '1'};
    Octal o3(o1.sum(o2));
    std::string s;
    o3.convertToString(s);
    EXPECT_TRUE(s == "212");
}

TEST(test_02, thorwFillConstructor)
{
    ASSERT_THROW(Octal t(1, '8'), std::underflow_error);
}

TEST(test_02, throwInitializerListConstructor)
{
    
    ASSERT_THROW(Octal t{'8'}, std::underflow_error);
}

TEST(test_02, throwCopyStringConstructor)
{    
    EXPECT_THROW(Octal t("8"), std::underflow_error);
}

TEST(test_03, equal)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '0', '1'};

    ASSERT_TRUE(o1.equals(o2) == true);
}

TEST(test_03, equalDifferentLength)
{
    Octal o1 {'1', '0'};
    Octal o2 {'1', '0', '1'};

    ASSERT_TRUE(o1.equals(o2) == false);
}

TEST(test_03, equalDifferentValues)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '0', '0'};

    ASSERT_TRUE(o1.equals(o2) == false);
}

TEST(test_04, moreForEquals)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '0', '1'};

    ASSERT_TRUE(o1.more(o2) == false);
}

TEST(test_04, more)
{
    Octal o1 {'1', '1', '0'};
    Octal o2 {'1', '0', '1'};

    ASSERT_TRUE(o1.more(o2) == true);
}

TEST(test_04, moreDifferentLength)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '0'};

    ASSERT_TRUE(o1.more(o2) == true);
}

TEST(test_05, lessForEquals)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '0', '1'};

    ASSERT_TRUE(o1.less(o2) == false);
}

TEST(test_05, less)
{
    Octal o1 {'1', '1', '0'};
    Octal o2 {'1', '0', '1'};

    ASSERT_TRUE(o1.less(o2) == false);
}

TEST(test_05, lessDifferentLength)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '0'};

    ASSERT_TRUE(o1.less(o2) == false);
}

TEST(test_06, sum)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '1', '0'};
    Octal o3 {'2', '1', '1'};

    ASSERT_TRUE(o1.sum(o2).equals(o3));
}

TEST(test_06, sumZeros)
{
    Octal o1 {'0'};
    Octal o2 {'0'};
    Octal o3 {'0'};

    ASSERT_TRUE(o1.sum(o2).equals(o3));
}

TEST(test_06, sum2)
{
    Octal o2 {'1', '0', '1'};
    Octal o1 {'1', '1', '0'};
    Octal o3 {'2', '1', '1'};

    ASSERT_TRUE(o1.sum(o2).equals(o3));
}

TEST(test_06, sumDifferentLength)
{
    Octal o1 {'1', '0', '1', '1'};
    Octal o2 {'1', '1', '0'};
    Octal o3 {'1', '1', '2', '1'};

    ASSERT_TRUE(o1.sum(o2).equals(o3));
}

TEST(test_06, sumDifferentLength2)
{
    Octal o2 {'1', '0', '1', '1'};
    Octal o1 {'1', '1', '0'};
    Octal o3 {'1', '1', '2', '1'};

    ASSERT_TRUE(o1.sum(o2).equals(o3));
}

// TEST(test_06, sumOver)
// {
//     Octal o1 {'5'};
//     Octal o2 {'6'};
//     Octal o3 {'1', '3'};

//     ASSERT_TRUE(o1.sum(o2).equals(o3));
// }

TEST(test_06, sumOver2)
{
    Octal o1 {'2', '6', '5'};
    Octal o2 {'7'};
    Octal o3 {'2', '7', '4'};

    ASSERT_TRUE(o1.sum(o2).equals(o3));
}

TEST(test_06, sumZero)
{
    Octal o1 {'2', '1', '1'};
    Octal o2 {'0'};

    ASSERT_TRUE(o1.sum(o2).equals(o1));
}

TEST(test_06, sumZero2)
{
    Octal o2 {'2', '1', '1'};
    Octal o1 {'0'};

    ASSERT_TRUE(o1.sum(o2).equals(o2));
}

TEST(test_07, add)
{
    Octal o1 {'1', '0', '1'};
    Octal o2 {'1', '1', '0'};
    Octal o3 {'2', '1', '1'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, addZeros)
{
    Octal o1 {'0'};
    Octal o2 {'0'};
    Octal o3 {'0'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, add2)
{
    Octal o2 {'1', '0', '1'};
    Octal o1 {'1', '1', '0'};
    Octal o3 {'2', '1', '1'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, addDifferentLength)
{
    Octal o1 {'1', '0', '1', '1'};
    Octal o2 {'1', '1', '0'};
    Octal o3 {'1', '1', '2', '1'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, addDifferentLength2)
{
    Octal o2 {'1', '0', '1', '1'};
    Octal o1 {'1', '1', '0'};
    Octal o3 {'1', '1', '2', '1'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, addOver)
{
    Octal o1 {'5'};
    Octal o2 {'6'};
    Octal o3 {'1', '3'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, addZero)
{
    Octal o1 {'2', '1', '1'};
    Octal o2 {'0'};
    Octal o3 {'2', '1', '1'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_07, addZero2)
{
    Octal o2 {'2', '1', '1'};
    Octal o1 {'0'};
    Octal o3 {'2', '1', '1'};

    o1.add(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_08, subtractionError)
{
    Octal o1 {'2', '1', '1'};
    Octal o2 {'1', '1', '1', '1'};

    EXPECT_THROW(o1.subtraction(o2), std::underflow_error);
}

TEST(test_08, subtractionError2)
{
    Octal o1 {'1', '1', '1'};
    Octal o2 {'2', '1', '1'};

    EXPECT_THROW(o1.subtraction(o2), std::underflow_error);
}

TEST(test_08, subtraction)
{
    Octal o1 {'2', '1', '1'};
    Octal o2 {'1', '1', '1'};
    Octal o3 {'1', '0', '0'};

    ASSERT_TRUE(o1.subtraction(o2).equals(o3));
}

TEST(test_08, subtractionZeros)
{
    Octal o1 {'0'};
    Octal o2 {'0'};
    Octal o3 {'0'};

    ASSERT_TRUE(o1.subtraction(o2).equals(o3));
}

TEST(test_08, subtractionExtra)
{
    Octal o1 {'5', '6', '7'};
    Octal o2 {'5', '0', '1'};
    Octal o3 {'6', '6'};

    ASSERT_TRUE(o1.subtraction(o2).equals(o3));
}

TEST(test_08, subtractionExtra2)
{
    Octal o1 {'1', '7', '4'};
    Octal o2 {'4'};
    Octal o3 {'1', '7', '0'};

    ASSERT_TRUE(o1.subtraction(o2).equals(o3));
}

TEST(test_08, subtractionZero)
{
    Octal o1 {'1', '0', '0'};
    Octal o2 {'0'};

    ASSERT_TRUE(o1.subtraction(o2).equals(o1));
}

TEST(test_08, subtractionAll)
{
    Octal o1 {'1', '0', '0'};
    Octal o2 {'0'};

    ASSERT_TRUE(o1.subtraction(o1).equals(o2));
}

TEST(test_09, removeError)
{
    Octal o1 {'2', '1', '1'};
    Octal o2 {'1', '1', '1', '1'};

    EXPECT_THROW(o1.remove(o2), std::underflow_error);
}

TEST(test_09, removeError2)
{
    Octal o1 {'1', '1', '1'};
    Octal o2 {'2', '1', '1'};

    EXPECT_THROW(o1.remove(o2), std::underflow_error);
}

TEST(test_09, remove)
{
    Octal o1 {'2', '1', '1'};
    Octal o2 {'1', '1', '1'};
    Octal o3 {'1', '0', '0'};

    o1.remove(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_09, removeZeros)
{
    Octal o1 {'0'};
    Octal o2 {'0'};
    Octal o3 {'0'};

    o1.remove(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_09, removeExtra)
{
    Octal o1 {'5', '7', '3'};
    Octal o2 {'5', '1', '6'};
    Octal o3 {'5', '5'};

    o1.remove(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_09, removeExtra2)
{
    Octal o1 {'1', '7', '4'};
    Octal o2 {'4'};
    Octal o3 {'1', '7', '0'};

    o1.remove(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_09, removeZero)
{
    Octal o1 {'1', '0', '0'};
    Octal o2 {'0'};
    Octal o3 {'1', '0', '0'};

    o1.remove(o2);

    ASSERT_TRUE(o1.equals(o3));
}

TEST(test_09, removeAll)
{
    Octal o1 {'1', '0', '0'};
    Octal o2 {'0'};

    o1.remove(o1);

    ASSERT_TRUE(o1.equals(o2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
