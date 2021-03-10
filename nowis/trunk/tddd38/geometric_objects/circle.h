#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <string>
#include "geometric_object.h"
#include "plane.h"
#include "point.h"

const float PI = 3.1415926f;

class Circle : public GeometricObject, public Plane {
public :
  Circle() : center_(0, 0), radius_(1) {}
  Circle(double x, double y, double r) : center_(x, y), radius_(r) {}
  Circle(const Point center, double r) : center_(center), radius_(r) {}

  double getRadius() const { return radius_; }
  double getPerimeter() const { return 2*PI*radius_; }
  double getArea() const { return PI*radius_*radius_; }

protected :
  virtual std::string toString() const;

private:
  Point center_;
  double radius_;
};

#endif
