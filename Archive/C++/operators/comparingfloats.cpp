// taken from learncpp.com

#include<iostream>
#include<vector>

using namespace std;

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon){
  // Check if the numbers are really close -- needed when comparing numbers near zero.
  double diff = fabs(a - b);
  if (diff <= absEpsilon) return true;

  // Otherwise fall back to Knuth's algorithm
  return diff <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

int main(){

  // a is really close to 1.0, but has rounding errors
  double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

  std::cout << approximatelyEqual(a, 1.0, 1e-8) << "\n";     // compare "almost 1.0" to 1.0
  std::cout << approximatelyEqual(a-1.0, 0.0, 1e-8) << "\n"; // compare "almost 0.0" to 0.0
  std::cout << approximatelyEqualAbsRel(a-1.0, 0.0, 1e-12, 1e-8) << "\n"; // compare "almost 0.0" to 0.0
  return 0;
}
