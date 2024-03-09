#pragma once

#include "figure.h"

template<Numbers T>
class Trapezium : public Figure<T>
{
public :
    Trapezium() : Figure<T>() {};
    Trapezium(const std::initializer_list<T> &coords);
    Trapezium(const Trapezium<T>& other);
    Trapezium(Trapezium<T>&& other);
    Trapezium(const Figure<T>& other);
    Trapezium(Figure<T>&& other);
    virtual ~Trapezium() = default;
    
public :
    virtual operator double() const override;
    virtual bool equal(const Figure<T>& other) const override;
    Trapezium<T>& operator=(const Trapezium<T>& other);
    Trapezium<T>& operator=(Trapezium<T>&& other);

	
protected :
    virtual bool check(std::pair<T, T> p1, std::pair<T, T> p2, std::pair<T, T> p3, std::pair<T, T> p4) override;
    virtual std::string getType() const override;
    virtual Array<double> getParams() const override;
    virtual Array<std::pair<T, T>> getArray() const override;
    void copy(const Trapezium<T>& other);
    void move(Trapezium<T>&& other);
    virtual void copy(const Figure<T>& other) override;
    virtual void move(Figure<T>&& other) override;

protected : 
    std::string typeOfFigure = "trap";
    double _a;
    double _b;
    double _height;
};

template<Numbers T>
bool Trapezium<T>::check(std::pair<T, T> coord1, std::pair<T, T> coord2, std::pair<T, T> coord3, std::pair<T, T> coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double fi1, fi2, fi3, fi4;
    if (modul(coord1.first - coord2.first) < EPS) fi1 = 0;
    else fi1 = (coord1.second - coord2.second) / (coord1.first - coord2.first);
    if (modul(coord2.first - coord3.first) < EPS) fi2 = 0;
    else fi2 = (coord2.second - coord3.second) / (coord2.first - coord3.first);
    if (modul(coord4.first - coord3.first) < EPS) fi3 = 0;
    else fi3 = (coord4.second - coord3.second) / (coord4.first - coord3.first);
    if (modul(coord1.first - coord4.first) < EPS) fi4 = 0;
    else fi4 = (coord1.second - coord4.second) / (coord1.first - coord4.first);
    double diag1 = sqrt(pow(coord1.first - coord3.first, 2) + pow(coord1.second - coord3.second, 2));
    double side1 = sqrt(pow(coord1.first - coord2.first, 2) + pow(coord1.second - coord2.second, 2));
    double side2 = sqrt(pow(coord2.first - coord3.first, 2) + pow(coord2.second - coord3.second, 2));
    double side3 = sqrt(pow(coord4.first - coord3.first, 2) + pow(coord4.second - coord3.second, 2));
    double side4 = sqrt(pow(coord1.first - coord4.first, 2) + pow(coord1.second - coord4.second, 2));
    double c;
    if (fabs(side2 - side4) < EPS && fabs(side1 - side3) < EPS) {
        return false;
    }
    if (fabs(fi1 - fi3) < EPS && fabs(fi2 - fi4) >= EPS && fabs(side2 - side4) < EPS) {
        c = side2;
        if (side1 > side3) {
            _a = side3;
            _b = side1;
        } else {
            _a = side1;
            _b = side3;
        }
    } else if (fabs(fi2 - fi4) < EPS && fabs(fi1 - fi3) >= EPS && fabs(side1 - side3) < EPS) {
        c = side1;
        if (side2 > side4) {
            _a = side4;
            _b = side2;
        } else {
            _a = side2;
            _b = side4;
        }
    } else {
        return false;
    }
    if (diag1 < _a) {
        return false;
    }
    _height = sqrt(pow(c, 2) - pow((_b - _a) / 2, 2));
    this->_array_params = Array<double>(3);
    this->_array_params[0] = _a;
    this->_array_params[1] = _b;
    this->_array_params[2] = _height;
    return true;
}

template<Numbers T>
Trapezium<T>::Trapezium(const std::initializer_list<T> &coords) : Figure<T>(coords) {
    auto it = coords.begin();
    std::pair<T, T> coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
        throw std::invalid_argument("Fail to create trap");
    }
}

template<Numbers T>
Trapezium<T>::Trapezium(const Trapezium<T>& other) {
    copy(other);
}

template<Numbers T>
Trapezium<T>::Trapezium(Trapezium<T>&& other) {
    move(std::move(other));
}

template<Numbers T>
Trapezium<T>::Trapezium(const Figure<T>& other) {
    copy(other);
}

template<Numbers T>
Trapezium<T>::Trapezium(Figure<T>&& other) {
    move(std::move(other));
}

template<Numbers T>
void Trapezium<T>::copy(const Trapezium<T>& other) {
    this->_array = Array<std::pair<T, T>>(4);
    this->_array = other._array;
    this->_array_params = Array<double>(3);
    this->_array_params = other._array_params;
    typeOfFigure = other.typeOfFigure;
    _a = other._a;
    _b = other._b;
    _height = other._height;
}

template<Numbers T>
void Trapezium<T>::move(Trapezium<T>&& other) {
    this->_array = Array<std::pair<T, T>>(4);
    this->_array = other._array;
    this->_array_params = Array<double>(3);
    this->_array_params = other._array_params;
    _a = other._a;
    _b = other._b;
    _height = other._height;
}

template<Numbers T>
void Trapezium<T>::copy(const Figure<T>& other) {
    throw std::invalid_argument("Fail to create trap");
}

template<Numbers T>
void Trapezium<T>::move(Figure<T>&& other) {
    throw std::invalid_argument("Fail to create trap");
}

template<Numbers T>
Trapezium<T>::operator double() const {
    if (this->_array.size() == 0) throw std::invalid_argument("No coords");
    return ((_a + _b) / 2.0 * _height);
}

template<Numbers T>
bool Trapezium<T>::equal(const Figure<T>& other) const {
    Array<double> params1 = this->getParams();
    Array<double> params2 = other.getParams();
    if ((fabs(params1[0] - params2[0]) < EPS) && (fabs(params1[1] - params2[1]) < EPS) 
        && (fabs(params1[2] - params2[2]) < EPS))  
    return true;
    return false;
}

template<Numbers T>
Trapezium<T>& Trapezium<T>::operator=(const Trapezium<T>& other) {
    copy(other);
    return *this;
}

template<Numbers T>
Trapezium<T>& Trapezium<T>::operator=(Trapezium<T>&& other) {
    move(std::move(other));
    return *this;
}

template<Numbers T>
std::string Trapezium<T>::getType() const {
    return typeOfFigure;
}

template<Numbers T>
Array<double> Trapezium<T>::getParams() const {
    return this->_array_params;
}

template<Numbers T>
Array<std::pair<T, T>> Trapezium<T>::getArray() const {
    return this->_array;
}
