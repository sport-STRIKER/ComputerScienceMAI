#include "../include/rectangle.h"

bool Rectangle::check(point coord1, point coord2, point coord3, point coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double fi1, fi2;
    if (fabs(coord1.x - coord2.x) < EPS) fi1 = 0;
    else fi1 = (coord1.y - coord2.y) / (coord1.x - coord2.x);
    if (fabs(coord4.x - coord3.x) < EPS) fi2 = 0;
    else fi2 = (coord4.y - coord3.y) / (coord4.x - coord3.x);
    double side1 = sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2));
    double side2 = sqrt(pow(coord3.x - coord2.x, 2) + pow(coord3.y - coord2.y, 2));
    double side3 = sqrt(pow(coord3.x - coord4.x, 2) + pow(coord3.y - coord4.y, 2));
    double diag1 = sqrt(pow(coord1.x - coord3.x, 2) + pow(coord1.y - coord3.y, 2));
    double diag2 = sqrt(pow(coord2.x - coord4.x, 2) + pow(coord2.y - coord4.y, 2));
    if (fabs(fi1 - fi2) < EPS && fabs(side1 - side3) < EPS && fabs(diag1 - diag2) < EPS && side1 < diag1 && side2 < diag1) {
        if (side1 < side2) {
            _side1 = side1;
            _side2 = side2;
        } else {
            _side1 = side2;
            _side2 = side1;
        }
        _array_params = new double[2];
        _array_params[0] = _side1;
        _array_params[1] = _side2;
        return true;
    }
    return false;
}

Rectangle::Rectangle(const std::initializer_list<double> &coords) : Figure(coords) {
    auto it = coords.begin();
    point coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
        throw std::invalid_argument("Fail to create rect");
    }
}

Rectangle::Rectangle(const Rectangle& other) {
    copy(other);
}

Rectangle::Rectangle(Rectangle&& other) {
    move(std::move(other));
}

Rectangle::Rectangle(const Figure& other) {
    copy(other);
}

Rectangle::Rectangle(Figure&& other) {
    move(std::move(other));
}

void Rectangle::copy(const Rectangle& other) {
    _array = new point[4];
    _array = other._array;

    _array_params = new double[2];
    _array_params = other._array_params;

    typeOfFigure = other.typeOfFigure;
    _side1 = other._side1;
    _side2 = other._side2;
}

void Rectangle::move(Rectangle&& other) {
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;

    _array_params = new double[2];
    _array_params = other._array_params;
    other._array_params = nullptr;
    
    typeOfFigure = other.typeOfFigure;
    _side1 = other._side1;
    _side2 = other._side2;
}

void Rectangle::copy(const Figure& other) {
    point * array = new point[4];
    array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rect");
    }
}

void Rectangle::move(Figure&& other) {
    point * array = new point[4];
    array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rect");
    }
    // other.~Figure();
    delete(&other);
}

Rectangle::operator double() const {
    if (_array == nullptr) {
        throw std::invalid_argument("No coords");
    }
    return (double(_side1 * _side2));
}

bool Rectangle::equal(const Figure& other) const {
    double * params1 = this->getParams();
    double * params2 = other.getParams();
    if ((fabs(params1[0] - params2[0]) < EPS) && (fabs(params1[1] - params2[1]) < EPS))
    return true;
    return false;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    copy(other);
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) {
    move(std::move(other));
    return *this;
}

std::string Rectangle::getType() const {
    return typeOfFigure;
}

double * Rectangle::getParams() const {
    return _array_params;
}

point * Rectangle::getArray() const {
    return _array;
}
