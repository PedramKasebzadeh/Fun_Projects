#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <string>
#include "geometric_object.h"

class Rectangle : public GeometricObject, public Plane {
public :
  Rectangle() : width_(1), height_(2) {}
  Rectangle(double width, double height) : width_(width), height_(height) {}

  double getWidth() const { return width_; }
  double getHeight() const { return height_; }
  double getPerimeter() const { return width_ + height_; }
  double getArea() const { return width_*height_; }

protected :
  virtual std::string toString() const; 
private :
  double width_;
  double height_;
};

#endif
