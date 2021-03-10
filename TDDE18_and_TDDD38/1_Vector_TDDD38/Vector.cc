//#include "Vector.h"
#include <vector>
#include <cmath>
#include <iostream>

// implement all the functions declared in Vector.h here
using namespace std

void fun(int const&) { cout << 1; };
void fun(int&) { cout << 2; };
void fun(int&&) { cout << 3; };
int main()
{
int a;
int const c{};
fun(23);
fun(a);
return 0; 
}