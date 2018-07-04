#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

// solution function
bool isPower(int n){
  if(n == 1) return true;

  int maxpower;
  for(int power = 2;power < 32;power++){
    maxpower = pow(INT_MAX,1.0/power);
    for(int base = 2;base <= maxpower;base++) if(pow(base,power) == n) {cout<<base<<" : "<<power<<endl; return true;}
  }
  return false;
}

// another : much faster method
bool isPower2(int n){
  if(n == 1) return true;

  double base,maxpower = ceil(log2(n));
  // cout<<maxpower<<endl;
  int low,high;
  for(double power = 2;power <= maxpower;power++){
    base = pow(n,1/power);
    low = floor(base); if(pow(low,power) == n) {cout<<low<<" : "<<power<<endl; return true;}
    high = ceil(base); if(pow(high,power) == n) {cout<<high<<" : "<<power<<endl; return true;}
    // cout<<base<<":"<<low<<":"<<high<<endl;
  }
  return false;
}

// driver function
int main(){
  int n;
  cin>>n;

  cout<<isPower(n)<<endl;
  cout<<isPower2(n)<<endl;
  return 0;
}
