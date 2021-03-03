

#include <iostream>
#include <cstdio>
using std::cout;

int main()
{
  string Greeting = "Hello World!";
  
  int * i;
  int a = 10;

  i = &a;

  a = 35;
  cout << "a: " << a << endl;
  *i = 40;
  cout << "a: " << a << endl;
  cout << "i: " << i << endl;

  int arr[5]= {1,2,3,4,5}; 
  // ai[0] =1; 
  //  *ai = 1 ;
  char s[] = {'s','t','r','i','n','g',0};

  cout << "C string: "<< s << endl;
  cout << "ai: "<< arr << endl;
  // printf(arr);

  i = 8; 
  int s = sqrt(factor[i]);
  cout << s <<endl;
  if ((s * s) == factor[i])){
    cout << factor[i]<< endl;
  };
  
  return 0;
}

