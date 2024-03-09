#include <gtest/gtest.h>
#include "include/figure.h"
#include "include/trapezium.h"
#include "include/rectangle.h"
#include "include/rhomb.h"
#include "include/array.h"

TEST(Test_01, PointEqual1)  
{
    point dot1{1,2};
    point dot2{1,2};

    EXPECT_TRUE(dot1 == dot2);
}

TEST(Test_01, PointEqual2)  
{
    point dot1{1,2};
    point dot2{1.00001,2.00001};

    EXPECT_TRUE(dot1 == dot2);
}

TEST(Test_01, PointNotEqual)  
{
    point dot1{1,2};
    point dot2{1.01,2.00001};

    EXPECT_FALSE(dot1 == dot2);
}

TEST(Test_02, RectListConstrExcept)
{
    EXPECT_THROW((Rectangle {1, 2, 5, 1, 5, 3, 1, 3}), std::invalid_argument);
}

TEST(Test_02, RectListConstrExcept2)
{
    EXPECT_THROW((Rectangle {1, 1, 5, 3, 5, 1, 1, 3}), std::invalid_argument);
}

TEST(Test_02, RectListConstrExcept3)
{
    EXPECT_THROW((Rectangle {1, 1, 1, 1, 5, 1, 1, 3}), std::invalid_argument);
}

TEST(Test_02, RectBaseConstrCenter)
{
    Rectangle r;

    EXPECT_THROW(r.center(), std::invalid_argument);
}

TEST(Test_02, RectListConstrCenter)
{
    Rectangle r{1, 1, 5, 1, 5, 3, 1, 3};
    point p{3, 2};

    EXPECT_TRUE(r.center() == p);
}

TEST(Test_02, RectBaseConstrSquare)
{
    Rectangle r;

    EXPECT_THROW(double s = double(r), std::invalid_argument);
}

TEST(Test_02, RectListConstrSquare)
{
    Rectangle r{1, 1, 5, 1, 5, 3, 1, 3};
    float square = 4 * 2;

    EXPECT_TRUE(abs(double(r) - square) < EPS);
}

TEST(Test_02, RectEqualRect)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2{1, 1, 5, 1, 5, 3, 1, 3};

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_02, RectEqualRect2)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2{2, 2, 6, 2, 6, 4, 2, 4};

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_02, RectEqualRect3)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2{5, 1, 5, 3, 1, 3, 1, 1};
    Rectangle r3{5, 3, 1, 3, 1, 1, 5, 1};
    Rectangle r4{1, 3, 1, 1, 5, 1, 5, 3};

    EXPECT_TRUE((r1 == r2) && (r2 == r3) && (r3 == r4));
}

TEST(Test_02, RectEqualRect4)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2{6, 1, 8.82842, 3.82842, 7.414214, 5.24264, 4.585786, 2.414214};

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_02, RectNotEqualRect)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2{1, 2, 6, 2, 6, 4, 1, 4};

    EXPECT_FALSE(r1 == r2);
}

TEST(Test_02, RectCopyConstr)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2(r1);

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_02, RectCopyRect)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2 = r1;

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_02, RectCopyRect2)
{
    Rectangle r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle r2{1, 1, 2, 1, 2, 2, 1, 2};
    r2 = r1;

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_03, RhombListConstrExcept)  // неверные значения сторон
{
    EXPECT_THROW((Rhomb {2, 1, 4, 2, 2, 3, 1, 2}), std::invalid_argument);
}

TEST(Test_03, RhombListConstrExcept2)  // обход в другом порядке
{
    EXPECT_THROW((Rhomb {2, 1, 2, 3, 3, 2, 1, 2}), std::invalid_argument);
}

TEST(Test_03, RhombBaseConstrCenter)
{
    Rhomb rh;

    EXPECT_THROW(rh.center(), std::invalid_argument);
}

TEST(Test_03, RhombListConstrCenter)
{
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    point p{2, 2};

    EXPECT_TRUE(rh.center() == p);
}

TEST(Test_03, RhombBaseConstrSquare)
{
    Rhomb rh;

    EXPECT_THROW(double s = double(rh), std::invalid_argument);
}

TEST(Test_03, RhombListConstrSquare)
{
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    float square = 2;

    EXPECT_TRUE(abs(double(rh) - square) < EPS);
}

TEST(Test_03, RhombEqualRhomb)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2{2, 1, 3, 2, 2, 3, 1, 2};

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_03, RhombEqualRhomb2)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2{3, 1, 4, 2, 3, 3, 2, 2};

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_03, RhombEqualRhomb3)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2{3, 2, 2, 3, 1, 2, 2, 1};
    Rhomb rh3{2, 3, 1, 2, 2, 1, 3, 2};
    Rhomb rh4{1, 2, 2, 1, 3, 2, 2, 3};

    EXPECT_TRUE((rh1 == rh2) && (rh2 == rh3) && (rh3 == rh4));
}

TEST(Test_03, RhombNotEqualRhomb)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2{2, 1, 3, 3, 2, 5, 1, 3};

    EXPECT_FALSE(rh1 == rh2);
}

TEST(Test_03, RhombCopyConstr)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2(rh1);

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_03, RhombCopyRhomb)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2 = rh1;

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_03, RhombCopyRhomb2)
{
    Rhomb rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb rh2{1, 0, 2, 1, 1, 2, 0, 1};
    rh2 = rh1;

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_04, RhombEqualRect)
{
    Rhomb rh{1, 1, 2, 1, 2, 2, 1, 2};
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};

    EXPECT_TRUE((rh == r) && (r == rh));
}

TEST(Test_04, RectNotEqualRhomb)
{
    Rectangle r{1, 1, 5, 1, 5, 3, 1, 3};
    Rhomb rh{1, 1, 2, 1, 2, 2, 1, 2};

    EXPECT_FALSE((r == rh) || (rh == r));
}

TEST(Test_04, RhombCopyRect)
{
    Rhomb rh{1, 1, 2, 1, 2, 2, 1, 2};
    Rectangle r = rh;

    EXPECT_TRUE(r == rh);
}

TEST(Test_04, RhombCopyRect2)
{
    Rhomb rh{1, 1, 2, 1, 2, 2, 1, 2};
    Rectangle r{1, 1, 4, 1, 4, 2, 1, 2};
    r = rh;

    EXPECT_TRUE(r == rh);
}

TEST(Test_04, RectCopyRhomb)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh = r;

    EXPECT_TRUE(r == rh);
}

TEST(Test_04, RectCopyRhomb2)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh{2, 1, 3, 5, 2, 9, 1, 5};
    rh = r;

    EXPECT_TRUE(r == rh);
}

TEST(Test_04, RhombNotCopyRect)
{
    Rhomb rh{2, 1, 3, 3, 2, 5, 1, 3};

    EXPECT_THROW(Rectangle r = rh, std::invalid_argument);
}

TEST(Test_04, RhombNotCopyRect2)
{
    Rhomb rh{2, 1, 3, 3, 2, 5, 1, 3};
    Rectangle r;

    EXPECT_THROW(r = rh, std::invalid_argument);
}

TEST(Test_04, RectNotCopyRhomb)
{
    Rectangle r{1, 1, 5, 1, 5, 3, 1, 3};

    EXPECT_THROW(Rhomb rh = r, std::invalid_argument);
}

TEST(Test_04, RectNotCopyRhomb2)
{
    Rectangle r{1, 1, 5, 1, 5, 3, 1, 3};
    Rhomb rh;

    EXPECT_THROW(rh = r, std::invalid_argument);
}

TEST(Test_05, TrapListConstrExcept)
{
    EXPECT_THROW((Trapezium {1, 1, 4, 3, 5, 1, 2, 3}), std::invalid_argument);
}

TEST(Test_05, TrapListConstrExcept2)
{
    EXPECT_THROW((Trapezium {1, 2, 5, 3, 5, 1, 1, 3}), std::invalid_argument);
}

TEST(Test_05, TrapBaseConstrCenter)
{
    Trapezium tr;

    EXPECT_THROW(tr.center(), std::invalid_argument);
}

TEST(Test_05, TrapListConstrCenter)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
    point p{3, 2};

    EXPECT_TRUE(tr.center() == p);
}

TEST(Test_05, TrapBaseConstrSquare)
{
    Trapezium tr;

    EXPECT_THROW(double s = double(tr), std::invalid_argument);
}

TEST(Test_05, TrapListConstrSquare)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
    float square = 6;

    EXPECT_TRUE(abs(double(tr) - square) < EPS);
}

TEST(Test_05, TrapEqualTrap)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2{1, 1, 5, 1, 4, 3, 2, 3};

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_05, TrapEqualTrap2)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2{2, 1, 6, 1, 5, 3, 3, 3};

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_05, TrapEqualTrap3)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2{5, 1, 4, 3, 2, 3, 1, 1};
    Trapezium tr3{4, 3, 2, 3, 1, 1, 5, 1};
    Trapezium tr4{2, 3, 1, 1, 5, 1, 4, 3};

    EXPECT_TRUE((tr1 == tr2) && (tr2 == tr3) && (tr3 == tr4));
}

TEST(Test_05, TrapNotEqualTrap)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2{1, 1, 6, 1, 5, 3, 2, 3};

    EXPECT_FALSE(tr1 == tr2);
}

TEST(Test_05, TrapCopyConstr)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2(tr1);

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_05, TrapCopyTrap)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2 = tr1;

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_05, TrapCopyTrap2)
{
    Trapezium tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium tr2;
    tr2 = tr1;

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_04, TrapNotEqualRect)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rectangle r{1, 1, 5, 1, 5, 3, 1, 3};

    EXPECT_FALSE((tr == r) || (r == tr));
}

TEST(Test_04, TrapNotEqualRhomb)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};

    EXPECT_FALSE((tr == rh) || (rh == tr));
}

TEST(Test_04, TrapNotCopyRect)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    EXPECT_THROW(Rectangle r = tr, std::invalid_argument);
}

TEST(Test_04, TrapNotCopyRect2)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rectangle r;

    EXPECT_THROW(r = tr, std::invalid_argument);
}

TEST(Test_04, TrapNotCopyRhomb)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    EXPECT_THROW(Rhomb rh = tr, std::invalid_argument);
}

TEST(Test_04, TrapNotCopyRhomb2)
{
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rhomb rh;

    EXPECT_THROW(rh = tr, std::invalid_argument);
}

TEST(Test_04, RectNotCopyTrap)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};

    EXPECT_THROW(Trapezium tr = r, std::invalid_argument);
}

TEST(Test_04, RectNotCopyTrap2)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Trapezium tr;

    EXPECT_THROW(tr = r, std::invalid_argument);
}

TEST(Test_04, RhombNotCopyTrap)
{
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};

    EXPECT_THROW(Trapezium tr = rh, std::invalid_argument);
}

TEST(Test_04, RhombNotCopyTrap2)
{
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium tr;

    EXPECT_THROW(tr = rh, std::invalid_argument);
}

TEST(Test_06, ArrayInitConstr)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array arr{&r, &rh, &tr};

    EXPECT_TRUE(arr.size() == 3);
}

TEST(Test_06, ArraySumExcept)
{
    Array arr;
    
    EXPECT_THROW(double s = double(arr), std::invalid_argument);
}

TEST(Test_06, ArrayInitConstrSum)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array arr{&r, &rh, &tr};
    double sum_arr = double(arr);
    double sum_figure = double(r) + double(rh) + double(tr);

    EXPECT_TRUE(sum_arr == sum_figure);
}

TEST(Test_06, ArrayInsertSum)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array arr;
    arr.insert(0, &r);
    arr.insert(0, &tr);
    arr.insert(0, &rh);
    double sum_arr = double(arr);
    double sum_figure = double(r) + double(rh) + double(tr);

    EXPECT_TRUE((sum_arr == sum_figure) && (arr.size() == 3));
}

TEST(Test_06, ArrayInsertExcept)
{
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Array arr;

    EXPECT_THROW(arr.insert(10, &rh), std::range_error);
}

TEST(Test_06, ArrayEraseSum)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array arr;
    arr.insert(0, &r);
    arr.insert(0, &tr);
    arr.insert(0, &rh);
    arr.erase(1);
    double sum_arr = double(arr);
    double sum_figure = double(r) + double(rh);

    EXPECT_TRUE((sum_arr == sum_figure) && (arr.size() == 2));
}

TEST(Test_06, ArrayEraseEXcept)
{
    Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array arr;
    arr.insert(0, &r);
    arr.insert(0, &tr);
    arr.insert(0, &rh);

    EXPECT_THROW(arr.erase(-1), std::range_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}