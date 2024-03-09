#pragma once

#include "figure.h"

template<Numbers T>
class Rhomb : public Figure<T>
{
public :
    Rhomb() : Figure<T>() {};
    Rhomb(const std::initializer_list<T> &coords);
    Rhomb(const Rhomb<T>& other);
    Rhomb(Rhomb<T>&& other);
    Rhomb(const Figure<T>& other);
    Rhomb(Figure<T>&& other);
    virtual ~Rhomb() = default;
    
public :
    virtual operator double() const override;
    virtual bool equal(const Figure<T>& other) const override;
    Rhomb<T>& operator=(const Rhomb<T>& other);
    Rhomb<T>& operator=(Rhomb<T>&& other);

	
protected :
    virtual bool check(std::pair<T, T> p1, std::pair<T, T> p2, std::pair<T, T> p3, std::pair<T, T> p4) override;
    virtual std::string getType() const override;
    virtual Array<double> getParams() const override;
    virtual Array<std::pair<T, T>> getArray() const override;
    void copy(const Rhomb<T>& other);
    void move(Rhomb<T>&& other);
    virtual void copy(const Figure<T>& other) override;
    virtual void move(Figure<T>&& other) override;

protected : 
    std::string typeOfFigure = "rhomb";
    double _diag1;
    double _diag2;
    double _side;
};

template<Numbers T>
bool Rhomb<T>::check(std::pair<T, T> coord1, std::pair<T, T> coord2, std::pair<T, T> coord3, std::pair<T, T> coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double fi1, fi2;
    if (modul(coord1.first - coord2.first) < EPS) fi1 = 0;
    else fi1 = (coord1.second - coord2.second) / (coord1.first - coord2.first);
    if (modul(coord4.first - coord3.first) < EPS) fi2 = 0;
    else fi2 = (coord4.second - coord3.second) / (coord4.first - coord3.first);
    _diag1 = sqrt(pow(coord1.first - coord3.first, 2) + pow(coord1.second - coord3.second, 2));
    _diag2 = sqrt(pow(coord2.first - coord4.first, 2) + pow(coord2.second - coord4.second, 2));
    if (_diag1 > _diag2) {
        std::swap(_diag1, _diag2);
    }
    double side1 = sqrt(pow(coord1.first - coord2.first, 2) + pow(coord1.second - coord2.second, 2));
    double side2 = sqrt(pow(coord2.first - coord3.first, 2) + pow(coord2.second - coord3.second, 2));
    double side3 = sqrt(pow(coord4.first - coord3.first, 2) + pow(coord4.second - coord3.second, 2));
    double side4 = sqrt(pow(coord1.first - coord4.first, 2) + pow(coord1.second - coord4.second, 2));
    if (fabs(fi1 - fi2) < EPS && fabs(side1 - side3) < EPS && fabs(side1 - side2) < EPS && fabs(side1 - side4) < EPS && side1 < _diag2) {
        _side = side1;
        this->_array_params = Array<double>(3);
        this->_array_params[0] = _diag1;
        this->_array_params[1] = _diag2;
        this->_array_params[2] = side1;
        return true;
    }
    return false;
}

template<Numbers T>
Rhomb<T>::Rhomb(const std::initializer_list<T> &coords) : Figure<T>(coords) {
    auto it = coords.begin();
    std::pair<T, T> coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
        throw std::invalid_argument("Fail to create rhomb");
    }
}

template<Numbers T>
Rhomb<T>::Rhomb(const Rhomb<T>& other) {
    copy(other);
}

template<Numbers T>
Rhomb<T>::Rhomb(Rhomb<T>&& other) {
    move(std::move(other));
}

template<Numbers T>
Rhomb<T>::Rhomb(const Figure<T>& other) {
    copy(other);
}

template<Numbers T>
Rhomb<T>::Rhomb(Figure<T>&& other) {
    move(std::move(other));
}

template<Numbers T>
void Rhomb<T>::copy(const Figure<T>& other) {
    Array<std::pair<T, T>> array = Array<std::pair<T, T>>(4);
    array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rhomb");
    }
}

template<Numbers T>
void Rhomb<T>::move(Figure<T>&& other) {
    Array<std::pair<T, T>> array = Array<std::pair<T, T>>(4);
    array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rhomb");
    }
    delete[] &other;
}

template<Numbers T>
void Rhomb<T>::copy(const Rhomb<T>& other) {
    this->_array = Array<std::pair<T, T>>(4);
    this->_array = other._array;

    this->_array_params = Array<double>(3);
    this->_array_params = other._array_params;

    typeOfFigure = other.typeOfFigure;
    _diag1 = other._diag1;
    _diag2 = other._diag2;
    _side = other._side;
}

template<Numbers T>
void Rhomb<T>::move(Rhomb<T>&& other) {
    this->_array = Array<std::pair<T, T>>(4);
    this->_array = other._array;

    this->_array_params = Array<double>(3);
    this->_array_params = other._array_params;

    typeOfFigure = other.typeOfFigure;
    _diag1 = other._diag1;
    _diag2 = other._diag2;
    _side = other._side;
}

template<Numbers T>
Rhomb<T>::operator double() const {
    if (this->_array.size() == 0) throw std::invalid_argument("No coords");
    return (_diag1 * _diag2 / 2.0);
}

template<Numbers T>
bool Rhomb<T>::equal(const Figure<T>& other) const {
    Array<double> params1 = this->getParams();
    Array<double> params2 = other.getParams();
    if ((fabs(params1[0] - params2[0]) < EPS) && (fabs(params1[1] - params2[1]) < EPS) 
        && (fabs(params1[2] - params2[2]) < EPS))  
    return true;
    return false;
}

template<Numbers T>
Rhomb<T>& Rhomb<T>::operator=(const Rhomb<T>& other) {
    copy(other);
    return *this;
}

template<Numbers T>
Rhomb<T>& Rhomb<T>::operator=(Rhomb<T>&& other) {
    move(std::move(other));
    return *this;
}

template<Numbers T>
std::string Rhomb<T>::getType() const {
    return typeOfFigure;
}

template<Numbers T>
Array<double> Rhomb<T>::getParams() const {
    return this->_array_params;
}

template<Numbers T>
Array<std::pair<T, T>> Rhomb<T>::getArray() const {
    return this->_array;
}
