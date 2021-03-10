#include "geometric_object.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

#include <string>
#include <sstream>
using namespace std;

int GeometricObject::nbObject_ = 0;

string GeometricObject::str() const {
  return toString();
}

string Point::toString() const {
  ostringstream serialized;
  serialized << "Point@" << id_ << "[x=" << x_ << ",y=" << y_ << "]"; 
  return serialized.str();
}

string Circle::toString() const {
  ostringstream serialized;
  serialized << "Circle@" << id_ << "[" << center_.str() << ",r=" << radius_ << "]";
  return serialized.str();
}

string Line::toString() const {
  ostringstream serialized;
  serialized << "Line@" << id_ << "[" << p1_.str() << "," << p2_.str() << "]"; 
  return serialized.str();
}

string Rectangle::toString() const { 
  ostringstream serialized;
  serialized << "Rect@" << id_ << "[w=" << width_ << ",h=" << height_ << "]"; 
  return serialized.str();
}

string Triangle::toString() const {
  ostringstream serialized;
  serialized << "Tri@" << id_ << "[1=" << length1_ << ",2=" << length2_;
  serialized << ",3=" << length3_ << "]";
  return serialized.str();
}

