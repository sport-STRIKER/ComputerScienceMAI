#pragma once

#include <figure.h>
#include <rectangle.h>
#include <rhomb.h>
#include <array.h>
#include <trapezium.h>

template<Numbers T>
double squareOfAllFigures(Array<Figure<T>*>& other) {
    if (other.size() == 0) {
        throw std::invalid_argument("No figures");
    }
    double sum = 0;
    for (int i = 0; i < other.size(); ++i) {
        sum += (double) *(other[i]);
    }
    return sum;
}

template<Numbers T>
void squareOfEachFigure(Array<Figure<T>*>& other) {
    if (other.size() == 0) {
        throw std::invalid_argument("No figures");
    }
    for (int i = 0; i < other.size(); ++i) {
        double s = (double) *(other[i]);
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}

template<Numbers T>
void center(Array<Figure<T>*>& other) {
    if (other.size() == 0) {
        throw std::invalid_argument("No figures");
    }
    for (int i = 0; i < other.size(); ++i) {
        std::cout << (other[i]->center()).first << ' ' << (other[i]->center()).second << std::endl;
    }
}