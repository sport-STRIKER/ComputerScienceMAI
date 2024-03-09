#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "figure.h"

class Trapezium : public Figure
{
public :
    Trapezium() : Figure() {};
    Trapezium(const std::initializer_list<double> &coords);
    Trapezium(const Trapezium& other);
    Trapezium(Trapezium&& other);
    Trapezium(const Figure& other);
    Trapezium(Figure&& other);
    virtual ~Trapezium() = default;
    
public :
    virtual operator double() const override;
    virtual bool equal(const Figure& other) const override;
    Trapezium& operator=(const Trapezium& other);
    Trapezium& operator=(Trapezium&& other);

	
protected :
    virtual bool check(point p1, point p2, point p3, point p4) override;
    virtual std::string getType() const override;
    virtual double * getParams() const override;
    virtual point * getArray() const override;
    void copy(const Trapezium& other);
    void move(Trapezium&& other);
    virtual void copy(const Figure& other) override;
    virtual void move(Figure&& other) override;

protected : 
    std::string typeOfFigure = "trap";
    double _a;
    double _b;
    double _height;
};

#endif
