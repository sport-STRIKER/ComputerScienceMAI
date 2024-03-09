#include "../include/figure.h"

Figure::Figure(const std::initializer_list<double> &coords) {
    int n = coords.size();
    if (n != 8) {
        throw std::invalid_argument("Too many or too few coords");
    }
    _array = new point[n / 2];
    int i = 0;
    for (double elem : coords) {
        if (i % 2 == 0) _array[i / 2].x = elem;
        else _array[i / 2].y = elem;
        ++i;
    }
}

point Figure::center() const {
    if (_array == nullptr) {
        throw std::invalid_argument("No coords");
    }
    double sumX = 0, sumY = 0;
    for (int i = 0; i < 4; ++i) {
        sumX += _array[i].x;
        sumY += _array[i].y;
    }
    return (point{sumX / 4.0, sumY / 4.0});
}

std::ostream& operator<<(std::ostream& out, const Figure& other) {
    if (other._array == nullptr) {
        throw std::invalid_argument("No coords");
    }
    for (int i = 0; i < 4; ++i) {
        out << other._array[i].x << ' ' << other._array[i].y << '\n';
    }
    return out;
}

std::istream& operator>>(std::istream& in, Figure& other) {
    if (other._array != nullptr) {
        throw std::invalid_argument("Figure also have coords");
    }
    other._array = new point[4];
    for (int i = 0; i < 4; ++i) {
        in >> other._array[i].x >> other._array[i].y;
    }
    point coord1 = {other._array[0].x, other._array[0].y};
    point coord2 = {other._array[1].x, other._array[1].y};
    point coord3 = {other._array[2].x, other._array[2].y};
    point coord4 = {other._array[3].x, other._array[3].y};
    other.check(coord1, coord2, coord3, coord4);
    return in;
}

bool operator==(const Figure& left, const Figure& right) {
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
        double * params1 = left.getParams();
        double * params2 = right.getParams();
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

Figure& Figure::operator=(const Figure& other) {
    copy(other);
    return *this;
}

Figure& Figure::operator=(Figure&& other) {
    move(std::move(other));
    return *this;
}
