#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int mySqrt(int x){
  if(x == 0 || x == 1) return x;

  long long int start = -1,end = x,mid;
  while(end - start > 1){
    mid = start+(end-start)/2;
    if(mid*mid <= x) start = mid;
    else end = mid;
  }
  return (int)start;
}

int main(){
  int n;
  cin>>n;

  cout<<mySqrt(n)<<endl;

  return 0;
}
