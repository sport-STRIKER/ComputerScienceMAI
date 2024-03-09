#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define EPS 0.001

struct point{
    double x;
    double y;
    bool operator==(point right) {
        if (fabs(x - right.x) < EPS && fabs(y - right.y) < EPS) {
            return true;
        }
        return false;
    }
};

class Figure
{
protected :
    Figure() = default;
    Figure(const std::initializer_list<double> &coords);
    Figure(const Figure& other);
    Figure(Figure&& other);

public :
    virtual ~Figure() = default;
    point center() const;
    virtual operator double() const = 0;
    friend std::ostream& operator<<(std::ostream&, const Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);
    friend bool operator==(const Figure& left, const Figure& right);
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other);
    virtual bool equal(const Figure& other) const = 0;
    virtual bool check(point p1, point p2, point p3, point p4) = 0;
    virtual std::string getType() const = 0;
    virtual double * getParams() const = 0;
    virtual point * getArray() const = 0;
    virtual void copy(const Figure& other) = 0;
    virtual void move(Figure&& other) = 0;

protected :
    std::string typeOfFigure;
    point *_array = nullptr;
    double *_array_params = nullptr;
};

#endif