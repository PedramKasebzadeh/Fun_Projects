#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "plane.h"
#include "geometric_object.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <typeinfo>

using namespace std;

template<typename T>
T *delete_obj(T *o)
{
  delete o;
  return 0;
}

int main() {
  vector<GeometricObject *> obj;

  obj.push_back(new Point());
  obj.push_back(new Line());
  obj.push_back(new Circle());
  obj.push_back(new Rectangle());
  obj.push_back(new Triangle());

  for(vector<GeometricObject *>::const_iterator it = obj.begin() ;
      it != obj.end() ; it++) {

    cout << "TYPE : " << typeid(**it).name() << endl;
    cout << (*it)->str() << endl;
    
    Plane *p = dynamic_cast<Plane *> (*it);
    if(p)
      cout << "Area : " << p->getArea() << endl;
    cout << endl;
  }

  cout << "VectorSize : " << obj.size() << endl;
  transform(obj.begin(), obj.end(), obj.begin(), delete_obj<GeometricObject>); 

  return 0;
}

