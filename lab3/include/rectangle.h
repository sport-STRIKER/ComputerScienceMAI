#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include "rhomb.h"

class Rectangle : public Figure
{
public :
    Rectangle() : Figure() {};
    Rectangle(const std::initializer_list<double> &coords);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other);
    Rectangle(const Figure& other);
    Rectangle(Figure&& other);
    virtual ~Rectangle() = default;
    
public :
    virtual operator double() const override;
    virtual bool equal(const Figure& other) const override;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other);

	
protected :
    virtual bool check(point p1, point p2, point p3, point p4) override;
    virtual std::string getType() const override;
    virtual double * getParams() const override;
    virtual point * getArray() const override;
    void copy(const Rectangle& other);
    void move(Rectangle&& other);
    virtual void copy(const Figure& other) override;
    virtual void move(Figure&& other) override;

protected : 
    std::string typeOfFigure = "rect";
    double _side1;
    double _side2;
};

#endif
