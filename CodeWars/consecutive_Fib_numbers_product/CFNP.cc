#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod){
      ull previous { 0 }, current { 1 }, temp;
  while (previous*current < prod) {
    temp = current;
    current = previous + current;
    previous = temp;
  }
  return { previous, current, prod == previous*current };
  };
};