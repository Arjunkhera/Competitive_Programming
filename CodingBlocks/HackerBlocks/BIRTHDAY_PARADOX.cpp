#include <cmath>
#include <iostream>

using namespace std;

int find(double p)
{
    return ceil(sqrt(2*365*log(1/(1-p))));
}

int main()
{
   double p;
   cin>>p;

   cout << find(p);
}
