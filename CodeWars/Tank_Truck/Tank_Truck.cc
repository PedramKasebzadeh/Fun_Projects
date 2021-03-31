#include<iostream>
#include <math.h>
#define PI 3.14159265


class VolTank
{
public:
    static int tankVol(int h, int d, int vt){
    double r = (double )d/2; // to get the right value make the divition a double. 
    double cylinder_height = 4 * vt/(PI* d*d);
    double A = abs(r - h); //  adjasent 
    double w = 2 *sqrt((r*r)-(A*A)); // opposite
    double theta = 2 * asin(w/(2*r))* (180/PI); // the angle 
    double segment_area = (theta/360 * PI * r * r) -  (w*A/2); 
    if(h > r){
        return floor(vt-(segment_area*cylinder_height));
      }
    return floor(segment_area*cylinder_height);
    };
};

int main(){
    int h=2,d=7,vt=3848;
    std::cout <<  VolTank::tankVol(h,d,vt)<<std::endl;
    return 0;
}


/* cool short answer 

#include <cmath>
class VolTank
{
public:
    static int tankVol(int h, int d, int vt)
    {
      double phi = 2*acos((d-h*2.0)/d);
      return (phi-sin(phi))/8.0/atan(1.0) * vt;
    }
};

*/






