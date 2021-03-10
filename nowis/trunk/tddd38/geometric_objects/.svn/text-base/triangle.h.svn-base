#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

class Triangle : public GeometricObject, public Plane {
public :
  Triangle() : length1_(1), length2_(1), length3_(1) {}

  Triangle(double length1, double length2, double length3)
    : length1_(length1), length2_(length2), length3_(length3) {}

  double getLength1() const { return length1_; }
  double getLength2() const { return length2_; }
  double getLength3() const { return length3_; }

  double getPerimeter() const { return length1_ + length2_ + length3_; }
  double getArea() const { return length1_; }

protected :
  virtual std::string toString() const;

private :
  double length1_;
  double length2_;
  double length3_;
};

#endif
