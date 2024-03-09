#pragma once

#include <iostream>
#include <figure.h>
#include <rectangle.h>
#include <rhomb.h>
#include <trapezium.h>
#include <array.h>
#include <arrayFig.h>

int main() {
    Rectangle<int> r{1, 1, 2, 1, 2, 2, 1, 2};
    Rhomb<int> rh{2, 1, 3, 2, 2, 3, 1, 2};
    Trapezium<int> tr{1, 1, 5, 1, 4, 3, 2, 3};

    Array<Figure<int>*> arr{&r, &rh, &tr};

    std::cout << "Центры фигур:\n"; 
    center(arr);

    std::cout << "Общая сумма площадей фигур:\n"; 
    double sum_arr = squareOfAllFigures(arr);
    std::cout << sum_arr << std::endl;

    std::cout << "Площади фигур по отдельности:\n";
    squareOfEachFigure(arr);
    return 0;
}