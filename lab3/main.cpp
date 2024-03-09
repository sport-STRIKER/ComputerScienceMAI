#include <iostream>
#include "include/figure.h"
#include "include/rectangle.h"
#include "include/rhomb.h"
#include "include/trapezium.h"
#include "include/array.h"

int main() {
    try {
        // Rectangle r{1, 1, 2, 1, 2, 2, 1, 2};
        // Rhomb rh{2, 1, 3, 2, 2, 3, 1, 2};
        Trapezium tr{1, 1, 5, 1, 4, 3, 2, 3};
        Trapezium tr2{3, 1, 7, 1, 6, 3, 4, 3};

        std::cout << tr2 << std::endl;
        tr2 = tr;
        std::cout << tr2;
        // Array arr{&r, &rh, &tr};

        // std::cout << "Центры фигур:\n"; 
        // arr.center();

        // std::cout << "Общая сумма площадей фигур:\n"; 
        // double sum_arr = double(arr);
        // std::cout << sum_arr << std::endl;

        // std::cout << "Площади фигур по отдельности:\n";
        // arr.squareOfEachFigure();
    }
    catch (const std::invalid_argument &ex1) {
        std::cout << ex1.what() << "\n";
    }
    catch (const std::range_error &ex2) {
        std::cout << ex2.what() << "\n";
    }
}