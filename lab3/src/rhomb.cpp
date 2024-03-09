#include "../include/rhomb.h"

bool Rhomb::check(point coord1, point coord2, point coord3, point coord4) {
    if (coord1 == coord2 || coord1 == coord3 || coord1 == coord4 ||
        coord2 == coord3 || coord2 == coord4 || coord3 == coord4) {
            return false;
    }
    double fi1, fi2;
    if (fabs(coord1.x - coord2.x) < EPS) fi1 = 0;
    else fi1 = (coord1.y - coord2.y) / (coord1.x - coord2.x);
    if (fabs(coord4.x - coord3.x) < EPS) fi2 = 0;
    else fi2 = (coord4.y - coord3.y) / (coord4.x - coord3.x);
    _diag1 = sqrt(pow(coord1.x - coord3.x, 2) + pow(coord1.y - coord3.y, 2));
    _diag2 = sqrt(pow(coord2.x - coord4.x, 2) + pow(coord2.y - coord4.y, 2));
    if (_diag1 > _diag2) {
        std::swap(_diag1, _diag2);
    }
    double side1 = sqrt(pow(coord1.x - coord2.x, 2) + pow(coord1.y - coord2.y, 2));
    double side2 = sqrt(pow(coord2.x - coord3.x, 2) + pow(coord2.y - coord3.y, 2));
    double side3 = sqrt(pow(coord4.x - coord3.x, 2) + pow(coord4.y - coord3.y, 2));
    double side4 = sqrt(pow(coord1.x - coord4.x, 2) + pow(coord1.y - coord4.y, 2));
    if (fabs(fi1 - fi2) < EPS && fabs(side1 - side3) < EPS && fabs(side1 - side2) < EPS && fabs(side1 - side4) < EPS && side1 < _diag2) {
        _side = side1;
        _array_params = new double[3];
        _array_params[0] = _diag1;
        _array_params[1] = _diag2;
        _array_params[2] = side1;
        return true;
    }
    return false;
}

Rhomb::Rhomb(const std::initializer_list<double> &coords) : Figure(coords) {
    auto it = coords.begin();
    point coord1{*it, *(++it)}, coord2{*(++it), *(++it)}, coord3{*(++it), *(++it)}, coord4{*(++it), *(++it)};
    if (!check(coord1, coord2, coord3, coord4)) {
        throw std::invalid_argument("Fail to create rhomb");
    }
}

Rhomb::Rhomb(const Rhomb& other) {
    copy(other);
}

Rhomb::Rhomb(Rhomb&& other) {
    move(std::move(other));
}

Rhomb::Rhomb(const Figure& other) {
    copy(other);
}

Rhomb::Rhomb(Figure&& other) {
    move(std::move(other));
}

void Rhomb::copy(const Figure& other) {
    point * array = new point[4];
    array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rhomb");
    }
}

void Rhomb::move(Figure&& other) {
    point * array = new point[4];
    array = other.getArray();
    if (!check(array[0], array[1], array[2], array[3])) {
        throw std::invalid_argument("Fail to create rhomb");
    }
    delete[] &other;
}

void Rhomb::copy(const Rhomb& other) {
    _array = new point[4];
    _array = other._array;

    _array_params = new double[3];
    _array_params = other._array_params;

    typeOfFigure = other.typeOfFigure;
    _diag1 = other._diag1;
    _diag2 = other._diag2;
    _side = other._side;
}

void Rhomb::move(Rhomb&& other) {
    _array = new point[4];
    _array = other._array;
    other._array = nullptr;

    _array_params = new double[3];
    _array_params = other._array_params;
    other._array_params = nullptr;

    typeOfFigure = other.typeOfFigure;
    _diag1 = other._diag1;
    _diag2 = other._diag2;
    _side = other._side;
}

Rhomb::operator double() const {
    if (_array == nullptr) throw std::invalid_argument("No coords");
    return (_diag1 * _diag2 / 2.0);
}

bool Rhomb::equal(const Figure& other) const {
    double * params1 = this->getParams();
    double * params2 = other.getParams();
    if ((fabs(params1[0] - params2[0]) < EPS) && (fabs(params1[1] - params2[1]) < EPS) 
        && (fabs(params1[2] - params2[2]) < EPS))  
    return true;
    return false;
}

Rhomb& Rhomb::operator=(const Rhomb& other) {
    copy(other);
    return *this;
}

Rhomb& Rhomb::operator=(Rhomb&& other) {
    move(std::move(other));
    return *this;
}

std::string Rhomb::getType() const {
    return typeOfFigure;
}

double * Rhomb::getParams() const {
    return _array_params;
}

point * Rhomb::getArray() const {
    return _array;
}
