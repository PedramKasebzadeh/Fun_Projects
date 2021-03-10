#ifndef _POINTS_H_
#define _POINTS_H_

#include <string>
#include "geometric_object.h"

class Point : public GeometricObject {
public:
  double x_;
  double y_;

  Point() : x_(0), y_(0) {}
  Point(double x, double y) : x_(x), y_(y) {}
  Point(const Point &p) : x_(p.x_), y_(p.y_) {}

protected :
  virtual std::string toString() const;
};

#endif
