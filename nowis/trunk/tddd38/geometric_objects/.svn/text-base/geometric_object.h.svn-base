#ifndef _GEOMETRIC_OBJECT_H_
#define _GEOMETRIC_OBJECT_H_

#include <string>

class GeometricObject {
public :
  virtual ~GeometricObject() {}

  std::string str() const;

protected :
  int id_;

  GeometricObject() : id_(nbObject_++) {}
  
  virtual std::string toString() const = 0;

private :
  static int nbObject_;
};

#endif
