#include <gtest/gtest.h>
#include "include/figure.h"
#include "include/trapezium.h"
#include "include/rectangle.h"
#include "include/rhomb.h"
#include "include/array.h"
#include "include/arrayFig.h"

TEST(Test_01, RectListConstrExcept)
{
    EXPECT_THROW((Rectangle<int> {1, 2, 5, 1, 5, 3, 1, 3}), std::invalid_argument);
}

TEST(Test_01, RectListConstrExcept2)
{
    EXPECT_THROW((Rectangle<int> {1, 1, 5, 3, 5, 1, 1, 3}), std::invalid_argument);
}

TEST(Test_01, RectListConstrExcept3)
{
    EXPECT_THROW((Rectangle<int> {1, 1, 1, 1, 5, 1, 1, 3}), std::invalid_argument);
}

TEST(Test_01, RectBaseConstrCenter)
{
    Rectangle<int> r;

    EXPECT_THROW(r.center(), std::invalid_argument);
}

TEST(Test_01, RectListConstrCenter)
{
    Rectangle<int> r{1, 1, 5, 1, 5, 3, 1, 3};
    std::pair<double, double> p{3, 2};

    EXPECT_TRUE(r.center() == p);
}

TEST(Test_01, RectListConstrCenter2)
{
    Rectangle<double> r{1, 1, 5, 1, 5, 3, 1, 3};
    std::pair<double, double> p{3, 2};

    EXPECT_TRUE(r.center() == p);
}

TEST(Test_01, RectBaseConstrSquare)
{
    Rectangle<int> r;

    EXPECT_THROW(double s = double(r), std::invalid_argument);
}

TEST(Test_01, RectListConstrSquare)
{
    Rectangle<int> r{1, 1, 5, 1, 5, 3, 1, 3};
    double square = 4 * 2;

    EXPECT_TRUE(abs(double(r) - square) < EPS);
}

TEST(Test_01, RectEqualRect)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2{1, 1, 5, 1, 5, 3, 1, 3};

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_01, RectEqualRect2)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2{2, 2, 6, 2, 6, 4, 2, 4};

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_01, RectEqualRect3)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2{5, 1, 5, 3, 1, 3, 1, 1};
    Rectangle<int> r3{5, 3, 1, 3, 1, 1, 5, 1};
    Rectangle<int> r4{1, 3, 1, 1, 5, 1, 5, 3};

    EXPECT_TRUE((r1 == r2) && (r2 == r3) && (r3 == r4));
}

TEST(Test_01, RectEqualRect4)
{
    Rectangle<double> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<double> r2{6, 1, 8.82842, 3.82842, 7.414214, 5.24264, 4.585786, 2.414214};

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_01, RectNotEqualRect)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2{1, 2, 6, 2, 6, 4, 1, 4};

    EXPECT_FALSE(r1 == r2);
}

TEST(Test_01, RectCopyConstr)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2(r1);

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_01, RectCopyRect)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2 = r1;

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_01, RectCopyRect2)
{
    Rectangle<int> r1{1, 1, 5, 1, 5, 3, 1, 3};
    Rectangle<int> r2{1, 1, 2, 1, 2, 2, 1, 2};
    r2 = r1;

    EXPECT_TRUE(r1 == r2);
}

TEST(Test_02, RhombListConstrExcept)  // неверные значения сторон
{
    EXPECT_THROW((Rhomb<int> {2, 1, 4, 2, 2, 3, 1, 2}), std::invalid_argument);
}

TEST(Test_02, RhombListConstrExcept2)  // обход в другом порядке
{
    EXPECT_THROW((Rhomb<int> {2, 1, 2, 3, 3, 2, 1, 2}), std::invalid_argument);
}

TEST(Test_02, RhombBaseConstrCenter)
{
    Rhomb<int> rh;

    EXPECT_THROW(rh.center().first, std::invalid_argument);
}

TEST(Test_02, RhombListConstrCenter)
{
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    std::pair<double, double> p{2, 2};

    EXPECT_TRUE(rh.center() == p);
}

TEST(Test_02, RhombBaseConstrSquare)
{
    Rhomb<int> rh;

    EXPECT_THROW(double s = double(rh), std::invalid_argument);
}

TEST(Test_02, RhombListConstrSquare)
{
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    double square = 2;

    EXPECT_TRUE(abs(double(rh) - square) < EPS);
}

TEST(Test_02, RhombListConstrSquare2)
{
    Rhomb<double> rh{2, 1, 3, 2, 2, 3, 1, 2};
    double square = 2;

    EXPECT_TRUE(abs(double(rh) - square) < EPS);
}

TEST(Test_02, RhombEqualRhomb)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2{2, 1, 3, 2, 2, 3, 1, 2};

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_02, RhombEqualRhomb2)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2{3, 1, 4, 2, 3, 3, 2, 2};

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_02, RhombEqualRhomb3)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2{3, 2, 2, 3, 1, 2, 2, 1};
    Rhomb<int> rh3{2, 3, 1, 2, 2, 1, 3, 2};
    Rhomb<int> rh4{1, 2, 2, 1, 3, 2, 2, 3};

    EXPECT_TRUE((rh1 == rh2) && (rh2 == rh3) && (rh3 == rh4));
}

TEST(Test_02, RhombNotEqualRhomb)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2{2, 1, 3, 3, 2, 5, 1, 3};

    EXPECT_FALSE(rh1 == rh2);
}

TEST(Test_02, RhombCopyConstr)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2(rh1);

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_02, RhombCopyRhomb)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2 = rh1;

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_02, RhombCopyRhomb2)
{
    Rhomb<int> rh1{2, 1, 3, 2, 2, 3, 1, 2};
    Rhomb<int> rh2{1, 0, 2, 1, 1, 2, 0, 1};
    rh2 = rh1;

    EXPECT_TRUE(rh1 == rh2);
}

TEST(Test_03, RhombEqualRect)
{
    Rhomb<int> rh{1, 1, 2, 1, 2, 2, 1, 2};
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};

    EXPECT_TRUE((rh == r) && (r == rh));
}

TEST(Test_03, RectNotEqualRhomb)
{
    Rectangle<int> r{1, 1, 5, 1, 5, 3, 1, 3};
    Rhomb<int> rh{1, 1, 2, 1, 2, 2, 1, 2};

    EXPECT_FALSE((r == rh) || (rh == r));
}

TEST(Test_03, RhombCopyRect)
{
    Rhomb<int> rh{1, 1, 2, 1, 2, 2, 1, 2};
    Rectangle<int> r = rh;

    EXPECT_TRUE(r == rh);
}

TEST(Test_03, RhombCopyRect2)
{
    Rhomb<int> rh{1, 1, 2, 1, 2, 2, 1, 2};
    Rectangle<int> r{1, 1, 4, 1, 4, 2, 1, 2};
    r = rh;

    EXPECT_TRUE(r == rh);
}

TEST(Test_03, RectCopyRhomb)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh = r;

    EXPECT_TRUE(r == rh);
}

TEST(Test_03, RectCopyRhomb2)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 5, 2, 9, 1, 5};
    rh = r;

    EXPECT_TRUE(r == rh);
}

TEST(Test_03, RhombNotCopyRect)
{
    Rhomb<int> rh{2, 1, 3, 3, 2, 5, 1, 3};

    EXPECT_THROW(Rectangle<int> r = rh, std::invalid_argument);
}

TEST(Test_03, RhombNotCopyRect2)
{
    Rhomb<int> rh{2, 1, 3, 3, 2, 5, 1, 3};
    Rectangle<int> r;

    EXPECT_THROW(r = rh, std::invalid_argument);
}

TEST(Test_03, RectNotCopyRhomb)
{
    Rectangle<int> r{1, 1, 5, 1, 5, 3, 1, 3};

    EXPECT_THROW(Rhomb<int> rh = r, std::invalid_argument);
}

TEST(Test_03, RectNotCopyRhomb2)
{
    Rectangle<int> r{1, 1, 5, 1, 5, 3, 1, 3};
    Rhomb<int> rh;

    EXPECT_THROW(rh = r, std::invalid_argument);
}

TEST(Test_04, TrapListConstrExcept)
{
    EXPECT_THROW((Trapezium<int> {1, 1, 4, 3, 5, 1, 2, 3}), std::invalid_argument);
}

TEST(Test_04, TrapListConstrExcept2)
{
    EXPECT_THROW((Trapezium<int> {1, 2, 5, 3, 5, 1, 1, 3}), std::invalid_argument);
}

TEST(Test_04, TrapBaseConstrCenter)
{
    Trapezium<int> tr;

    EXPECT_THROW(tr.center(), std::invalid_argument);
}

TEST(Test_04, TrapListConstrCenter)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};
    std::pair<double, double> p{3, 2};

    EXPECT_TRUE(tr.center() == p);
}

TEST(Test_04, TrapListConstrCenter2)
{
    Trapezium<double> tr{1, 1, 5, 1, 4, 3, 2, 3};
    std::pair<double, double> p{3, 2};

    EXPECT_TRUE(tr.center() == p);
}

TEST(Test_04, TrapBaseConstrSquare)
{
    Trapezium<int> tr;

    EXPECT_THROW(double s = double(tr), std::invalid_argument);
}

TEST(Test_04, TrapListConstrSquare)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};
    double square = 6;

    EXPECT_TRUE(abs(double(tr) - square) < EPS);
}

TEST(Test_04, TrapEqualTrap)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2{1, 1, 5, 1, 4, 3, 2, 3};

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_04, TrapEqualTrap2)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2{2, 1, 6, 1, 5, 3, 3, 3};

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_04, TrapEqualTrap3)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2{5, 1, 4, 3, 2, 3, 1, 1};
    Trapezium<int> tr3{4, 3, 2, 3, 1, 1, 5, 1};
    Trapezium<int> tr4{2, 3, 1, 1, 5, 1, 4, 3};

    EXPECT_TRUE((tr1 == tr2) && (tr2 == tr3) && (tr3 == tr4));
}

TEST(Test_04, TrapNotEqualTrap)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2{1, 1, 6, 1, 5, 3, 2, 3};

    EXPECT_FALSE(tr1 == tr2);
}

TEST(Test_04, TrapCopyConstr)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2(tr1);

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_04, TrapCopyTrap)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2 = tr1;

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_04, TrapCopyTrap2)
{
    Trapezium<int> tr1{1, 1, 5, 1, 4, 3, 2, 3};
    Trapezium<int> tr2;
    tr2 = tr1;

    EXPECT_TRUE(tr1 == tr2);
}

TEST(Test_03, TrapNotEqualRect)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rectangle<int> r{1, 1, 5, 1, 5, 3, 1, 3};

    EXPECT_FALSE((tr == r) || (r == tr));
}

TEST(Test_03, TrapNotEqualRhomb)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};

    EXPECT_FALSE((tr == rh) || (rh == tr));
}

TEST(Test_03, TrapNotCopyRect)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    EXPECT_THROW(Rectangle<int> r = tr, std::invalid_argument);
}

TEST(Test_03, TrapNotCopyRect2)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rectangle<int> r;

    EXPECT_THROW(r = tr, std::invalid_argument);
}

TEST(Test_03, TrapNotCopyRhomb)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    EXPECT_THROW(Rhomb<int> rh = tr, std::invalid_argument);
}

TEST(Test_03, TrapNotCopyRhomb2)
{
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};
    Rhomb<int> rh;

    EXPECT_THROW(rh = tr, std::invalid_argument);
}

TEST(Test_03, RectNotCopyTrap)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};

    EXPECT_THROW(Trapezium<int> tr = r, std::invalid_argument);
}

TEST(Test_03, RectNotCopyTrap2)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Trapezium<int> tr;

    EXPECT_THROW(tr = r, std::invalid_argument);
}

TEST(Test_03, RhombNotCopyTrap)
{
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};

    EXPECT_THROW(Trapezium<int> tr = rh, std::invalid_argument);
}

TEST(Test_03, RhombNotCopyTrap2)
{
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr;

    EXPECT_THROW(tr = rh, std::invalid_argument);
}

TEST(Test_05, ArrayInitConstr)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr{&r, &rh, &tr};

    EXPECT_TRUE(arr.size() == 3);
}

TEST(Test_05, ArraySumExcept)
{
    Array<Figure<int>*> arr;
    
    EXPECT_THROW(double s = squareOfAllFigures(arr), std::invalid_argument);
}

TEST(Test_05, ArrayInitConstrSum)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr{&r, &rh, &tr};
    double sum_arr = squareOfAllFigures(arr);
    double sum_figure = double(r) + double(rh) + double(tr);

    EXPECT_TRUE(sum_arr == sum_figure);
}

TEST(Test_05, ArrayInsertSum)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr;
    arr.insert(0, &r);
    arr.insert(0, &tr);
    arr.insert(0, &rh);
    double sum_arr = squareOfAllFigures(arr);
    double sum_figure = double(r) + double(rh) + double(tr);

    EXPECT_TRUE((sum_arr == sum_figure) && (arr.size() == 3));
}

TEST(Test_05, ArrayInsertExcept)
{
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Array<Figure<int>*> arr;

    EXPECT_THROW(arr.insert(10, &rh), std::range_error);
}

TEST(Test_05, ArrayEraseSum)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr;
    arr.insert(0, &r);
    arr.insert(0, &tr);
    arr.insert(0, &rh);
    arr.erase(1);
    double sum_arr = squareOfAllFigures(arr);
    double sum_figure = double(r) + double(rh);

    EXPECT_TRUE((sum_arr == sum_figure) && (arr.size() == 2));
}

TEST(Test_05, ArrayEraseIndex)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr {&r, &tr, &rh};

    EXPECT_TRUE(arr[0] == &r);
}

TEST(Test_05, ArrayEraseEXcept)
{
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr;
    arr.insert(0, &r);
    arr.insert(0, &tr);
    arr.insert(0, &rh);

    EXPECT_THROW(arr.erase(-1), std::range_error);
}

TEST(Test_06, ArrayOtherObjInd)
{
    Array<int> arr {1, 2, 3, 6};

    EXPECT_TRUE(arr[1] == 2);
}

TEST(Test_06, Test_06_ArrayOtherObjInsert)
{
    Array<int> arr {1, 2, 3, 6};
    arr.insert(0, 10);

    EXPECT_TRUE((arr[0] == 10) && (arr.size() == 5));
}

TEST(Test_06, Test_06_ArrayOtherObjErase)
{
    Array<std::string> arr {"asdf", "jfgh"};
    arr.erase(0);

    EXPECT_TRUE((arr[0] == "jfgh") && (arr.size() == 1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}