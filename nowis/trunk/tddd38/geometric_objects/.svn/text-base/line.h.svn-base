#ifndef _LINE_H_
#define _LINE_H_

#include <string>
#include <cmath>
#include "geometric_object.h"
#include "point.h"

class Line : public GeometricObject {
public:
  Point p1_;
  Point p2_;

  Line() : p1_(), p2_(1, 1) {}
  Line(double x1, double y1, double x2, double y2) : p1_(x1, y1), p2_(x2, y2) {}
  Line(const Point& p1, const Point& p2) : p1_(p1), p2_(p2) {}

  int getLength() { return sqrt((p1_.x_-p2_.x_)*(p1_.x_-p2_.x_) + 
                                (p1_.y_-p2_.y_)*(p1_.y_-p2_.y_)); }

protected :
  virtual std::string toString() const;
};

#endif

