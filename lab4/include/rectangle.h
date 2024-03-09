#pragma once

#include "figure.h"

template<Numbers T>
class Rectangle : public Figure<T>
{
public :
    Rectangle() = default;
    Rectangle(const std::initializer_list<T> &coords);
    Rectangle(const Rectangle<T>& other);
    Rectangle(Rectangle<T>&& other);
    Rectangle(const Figure<T>& other);
    Rectangle(Figure<T>&& other);
    virtual ~Rectangle() = default;
    
public :
    virtual operator double() const override;
    virtual bool equal(const Figure<T>& other) const override;
    Rectangle<T>& operator=(const Rectangle<T>& other);
    Rectangle<T>& operator=(Rectangle<T>&& other);

	
protected :
    virtual bool check(std::pair<T, T> coord1, std::pair<T, T> coord2, std::pair<T, T> coord3, std::pair<T, T> coord4) override;
    virtual std::string getType() const override;
    virtual Array<double> getParams() const override;
    virtual Array<std::pair<T, T>> getArray() const override;
    void copy(const Rectangle<T>& other);
    void move(Rectangle<T>&& other);
    virtual void copy(const Figure<T>& other) override;
    virtual void move(Figure<T>&& other) override;

protected : 
    std::string typeOfFigure = "rect";
    double _side1;
    double _side2;
};

template<Numbers T>
Rectangle<T>::Rectangle(const std::initializer_list<T> &coords) : Figure<T>(coords) {
    auto it = coords.begin();
    std::pair<T, T> coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
        throw std::invalid_argument("Fail to create rect");
    }
}

template<Numbers T>
Rectangle<T>::Rectangle(const Rectangle<T>& other) {
    copy(other);
}


template<Numbers T>
Rectangle<T>::Rectangle(Rectangle<T>&& other) {
    move(std::move(other));
}

template<Numbers T>
Rectangle<T>::Rectangle(const Figure<T>& other) {
    copy(other);
}

template<Numbers T>
Rectangle<T>::Rectangle(Figure<T>&& other) {
    move(std::move(other));
}

template<Numbers T>
Rectangle<T>::operator double() const {
    if (this->_array.size() == 0) {
        throw std::invalid_argument("No coords");
    }
    return (_side1 * _side2);
}

template<Numbers T>
bool Rectangle<T>::equal(const Figure<T>& other) const {
    Array<double> params1 = this->getParams();
    Array<double> params2 = other.getParams();
    if ((fabs(params1[0] - params2[0]) < EPS) && (fabs(params1[1] - params2[1]) < EPS))
    return true;
    return false;
}

template<Numbers T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& other) {
    copy(other);
    return *this;
}

template<Numbers T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle<T>&& other) {
    move(std::move(other));
    return *this;
}

template<Numbers T>
bool Rectangle<T>::check(std::pair<T, T> coord1, std::pair<T, T> coord2, std::pair<T, T> coord3, std::pair<T, T> coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double fi1, fi2;
    if (modul(coord1.first - coord2.first) < EPS) fi1 = 0;
    else fi1 = (coord1.second - coord2.second) / (coord1.first - coord2.first);
    if (modul(coord4.first - coord3.first) < EPS) fi2 = 0;
    else fi2 = (coord4.second - coord3.second) / (coord4.first - coord3.first);
    double side1 = sqrt(pow(coord1.first - coord2.first, 2) + pow(coord1.second - coord2.second, 2));
    double side2 = sqrt(pow(coord3.first - coord2.first, 2) + pow(coord3.second - coord2.second, 2));
    double side3 = sqrt(pow(coord3.first - coord4.first, 2) + pow(coord3.second - coord4.second, 2));
    double diag1 = sqrt(pow(coord1.first - coord3.first, 2) + pow(coord1.second - coord3.second, 2));
    double diag2 = sqrt(pow(coord2.first - coord4.first, 2) + pow(coord2.second - coord4.second, 2));
    if (fabs(fi1 - fi2) < EPS && fabs(side1 - side3) < EPS && fabs(diag1 - diag2) < EPS && side1 < diag1 && side2 < diag1) {
        if (side1 < side2) {
            _side1 = side1;
            _side2 = side2;
        } else {
            _side1 = side2;
            _side2 = side1;
        }
        this->_array_params = Array<double>(2);
        this->_array_params[0] = _side1;
        this->_array_params[1] = _side2;
        return true;
    }
    return false;
}

template<Numbers T>
std::string Rectangle<T>::getType() const {
    return typeOfFigure;
}

template<Numbers T>
Array<double> Rectangle<T>::getParams() const {
    return this->_array_params;
}

template<Numbers T>
Array<std::pair<T, T>> Rectangle<T>::getArray() const {
    return this->_array;
}

template<Numbers T>
void Rectangle<T>::copy(const Rectangle<T>& other) {
    this->_array = Array<std::pair<T, T>>(4);
    this->_array = other._array;

    this->_array_params = Array<double>(2);
    this->_array_params = other._array_params;

    typeOfFigure = other.typeOfFigure;
    _side1 = other._side1;
    _side2 = other._side2;
}

template<Numbers T>
void Rectangle<T>::move(Rectangle<T>&& other) {
    this->_array = Array<std::pair<T, T>>(4);
    this->_array = other._array;

    this->_array_params = Array<double>(2);
    this->_array_params = other._array_params;
    
    typeOfFigure = other.typeOfFigure;
    _side1 = other._side1;
    _side2 = other._side2;
}

template<Numbers T>
void Rectangle<T>::copy(const Figure<T>& other) {
    Array<std::pair<T, T>> array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rect");
    }
}

template<Numbers T>
void Rectangle<T>::move(Figure<T>&& other) {
    Array<std::pair<T, T>> array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rect");
    }
    delete(&other);
}
