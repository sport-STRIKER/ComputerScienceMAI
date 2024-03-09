#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
public :
    Rhomb() : Figure() {};
    Rhomb(const std::initializer_list<double> &coords);
    Rhomb(const Rhomb& other);
    Rhomb(Rhomb&& other);
    Rhomb(const Figure& other);
    Rhomb(Figure&& other);
    virtual ~Rhomb() = default;
    
public :
    virtual operator double() const override;
    virtual bool equal(const Figure& other) const override;
    Rhomb& operator=(const Rhomb& other);
    Rhomb& operator=(Rhomb&& other);

	
protected :
    virtual bool check(point p1, point p2, point p3, point p4) override;
    virtual std::string getType() const override;
    virtual double * getParams() const override;
    virtual point * getArray() const override;
    void copy(const Rhomb& other);
    void move(Rhomb&& other);
    virtual void copy(const Figure& other) override;
    virtual void move(Figure&& other) override;

protected : 
    std::string typeOfFigure = "rhomb";
    double _diag1;
    double _diag2;
    double _side;
};

#endif
