#include "../include/trapezium.h"

bool Trapezium::check(point coord1, point coord2, point coord3, point coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double fi1, fi2, fi3, fi4;
    if (fabs(coord1.x - coord2.x) < EPS) fi1 = 0;
    else fi1 = (coord1.y - coord2.y) / (coord1.x - coord2.x);
    if (fabs(coord2.x - coord3.x) < EPS) fi2 = 0;
    else fi2 = (coord2.y - coord3.y) / (coord2.x - coord3.x);
    if (fabs(coord4.x - coord3.x) < EPS) fi3 = 0;
    else fi3 = (coord4.y - coord3.y) / (coord4.x - coord3.x);
    if (fabs(coord1.x - coord4.x) < EPS) fi4 = 0;
    else fi4 = (coord1.y - coord4.y) / (coord1.x - coord4.x);
    double diag1 = sqrt(pow(coord1.x - coord3.x, 2) + pow(coord1.y - coord3.y, 2));
    double side1 = sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2));
    double side2 = sqrt(pow(coord2.x - coord3.x, 2) + pow(coord2.y - coord3.y, 2));
    double side3 = sqrt(pow(coord4.x - coord3.x, 2) + pow(coord4.y - coord3.y, 2));
    double side4 = sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2));
    double c;
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
    _array_params = new double[3];
    _array_params[0] = _a;
    _array_params[1] = _b;
    _array_params[2] = _height;
    return true;
}

Trapezium::Trapezium(const std::initializer_list<double> &coords) : Figure(coords) {
    auto it = coords.begin();
    point coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
            throw std::invalid_argument("Fail to create trap");
    }
}

Trapezium::Trapezium(const Trapezium& other) {
    copy(other);
}

Trapezium::Trapezium(Trapezium&& other) {
    move(std::move(other));
}

Trapezium::Trapezium(const Figure& other) {
    copy(other);
}

Trapezium::Trapezium(Figure&& other) {
    move(std::move(other));
}

void Trapezium::copy(const Trapezium& other) {
    _array = new point[4];
    _array = other._array;
    _array_params = new double[3];
    _array_params = other._array_params;
    typeOfFigure = other.typeOfFigure;
    _a = other._a;
    _b = other._b;
    _height = other._height;
}

void Trapezium::move(Trapezium&& other) {
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;
    _array_params = new double[3];
    _array_params = other._array_params;
    other._array_params = nullptr;
    _a = other._a;
    _b = other._b;
    _height = other._height;
}

void Trapezium::copy(const Figure& other) {
    throw std::invalid_argument("Fail to create trap");
}

void Trapezium::move(Figure&& other) {
    throw std::invalid_argument("Fail to create trap");
}

Trapezium::operator double() const {
    if (_array == nullptr) throw std::invalid_argument("No coords");
    return ((_a + _b) / 2.0 * _height);
}

bool Trapezium::equal(const Figure& other) const {
    double * params1 = this->getParams();
    double * params2 = other.getParams();
    if ((fabs(params1[0] - params2[0]) < EPS) && (fabs(params1[1] - params2[1]) < EPS) 
        && (fabs(params1[2] - params2[2]) < EPS))  
    return true;
    return false;
}

Trapezium& Trapezium::operator=(const Trapezium& other) {
    copy(other);
    return *this;
}

Trapezium& Trapezium::operator=(Trapezium&& other) {
    move(std::move(other));
    return *this;
}

std::string Trapezium::getType() const {
    return typeOfFigure;
}

double * Trapezium::getParams() const {
    return _array_params;
}

point * Trapezium::getArray() const {
    return _array;
}
