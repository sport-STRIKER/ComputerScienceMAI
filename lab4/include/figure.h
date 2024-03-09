#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <concepts>

#include "array.h"

#define EPS 0.001

template<class T>
concept Numbers = (std::integral<T> || std::floating_point<T>) && !(std::same_as<T, bool> || std::same_as<T, char>);

template<Numbers T>
T modul(T arg) {
    return (arg > 0 ? arg : -arg);
}

template<Numbers T>
class Figure
{
public :
    Figure() = default;
    Figure(const std::initializer_list<T> &coords);
    virtual ~Figure() = default;

    std::pair<double, double> center() const;
    virtual operator double() const = 0;

    template<Numbers U>
    friend std::ostream& operator<<(std::ostream&, const Figure<U>&);
    template<Numbers U>
    friend std::istream& operator>>(std::istream&, Figure<U>&);
    template<Numbers U, Numbers V>
    friend bool operator==(const Figure<U>& left, const Figure<V>& right);
    
    Figure<T>& operator=(const Figure<T>& other);
    Figure<T>& operator=(Figure<T>&& other);
    virtual bool equal(const Figure<T>& other) const = 0;
    virtual bool check(std::pair<T, T> p1, std::pair<T, T> p2, std::pair<T, T> p3, std::pair<T, T> p4) = 0;
    virtual std::string getType() const = 0;
    virtual Array<double> getParams() const = 0;
    virtual Array<std::pair<T, T>> getArray() const = 0;
    virtual void copy(const Figure<T>& other) = 0;
    virtual void move(Figure<T>&& other) = 0;

protected :
    std::string typeOfFigure;
    Array<std::pair<T, T>> _array;
    Array<double> _array_params;
};

template<Numbers T>
std::ostream& operator<<(std::ostream& out, const Figure<T>& other) {
    if (other._array.size() == 0) {
        throw std::invalid_argument("No coords");
    }
    for (int i = 0; i < 4; ++i) {
        out << other._array[i].first << ' ' << other._array[i].second << '\n';
    }
    return out;
}

template<Numbers T>
std::istream& operator>>(std::istream& in, Figure<T>& other) {
    if (other._array.size() != 0) {
        throw std::invalid_argument("Figure also have coords");
    }
    other._array = Array<std::pair<T, T>>(4);
    for (int i = 0; i < 4; ++i) {
        in >> other._array[i].first >> other._array[i].second;
    }
    std::pair<T, T> coord1 = {other._array[0].first, other._array[0].second};
    std::pair<T, T> coord2 = {other._array[1].first, other._array[1].second};
    std::pair<T, T> coord3 = {other._array[2].first, other._array[2].second};
    std::pair<T, T> coord4 = {other._array[3].first, other._array[3].second};
    if (!other.check(coord1, coord2, coord3, coord4)) {
        throw std::invalid_argument("Fail to create figure");
    }
    return in;
}

template<Numbers T1, Numbers T2>
bool operator==(const Figure<T1>& left, const Figure<T2>& right) {
    if (left.getType() == right.getType() && right.getType() == "rect") {
        return left.equal(right);
    }
    if (left.getType() == right.getType() && right.getType() == "rhomb") {
        return left.equal(right);
    }
    if (left.getType() == right.getType() && right.getType() == "trap") {
        return left.equal(right);
    }
    if ((left.getType() == "rect" && right.getType() == "rhomb") || 
        (left.getType() == "rhomb" && right.getType() == "rect")) {
        Array<double> params1 = left.getParams();
        Array<double> params2 = right.getParams();
        if (left.getType() == "rhomb") {
            std::swap(params1, params2);
        }
        if (fabs(params1[0] - params1[1]) < EPS && fabs(params1[0] - params2[2]) < EPS 
        && fabs(params2[0] - params2[1]) < EPS) {
                return true;
        }
    }
    return false;
}

template<Numbers T>
Figure<T>::Figure(const std::initializer_list<T> &coords) {
    int n = coords.size();
    if (n != 8) {
        throw std::invalid_argument("Too many or too few coords");
    }
    _array = Array<std::pair<T, T>>(n / 2);
    int i = 0;
    for (T elem : coords) {
        if (i % 2 == 0) _array[i / 2].first = elem;
        else _array[i / 2].second = elem;
        ++i;
    }
}

template<Numbers T>
std::pair<double, double> Figure<T>::center() const {
    if (_array.size() == 0) {
        throw std::invalid_argument("No coords");
    }
    T sumX = 0, sumY = 0;
    for (int i = 0; i < 4; ++i) {
        sumX += _array[i].first;
        sumY += _array[i].second;
    }
    return (std::pair<double, double>{sumX / 4.0, sumY / 4.0});
}

template<Numbers T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
    copy(other);
    return *this;
}

template<Numbers T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) {
    move(std::move(other));
    return *this;
}
