#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// for calculating modulo by a number
int pow(int x, int n, int d){

  long long int answer = 1; bool flag = false;

  if(x == 0) return 0; if(n == 0) return 1;
  // to check whether the final number is negative or not
  if(x < 0){ x = abs(x); if(n%2 != 0) flag = true; }

  x = x%d;
  while(n != 0){
   if(n & 1) answer = (answer*x)%d;
   x = (x*x)%d; n = n>>1;
   if(answer > d) answer = answer%d;
  }
  if(flag) return (d - (int)answer);
  return (int)answer;

}

// solution function
double myPow(double x, int n){
  if(x == 0 || x == 1 || n == 1) return x; // not neccessary, just a force of habit
  if(n == 0) return 1;

  double temp = myPow(x,n/2);
  if(n%2 == 0) return temp*temp;
  if(n > 0) return x*temp*temp;
  return (temp*temp)/x;
}

// itertaive version
double myPowiterative(double x, int n){
  if(x == 0 || x == 1 || n == 1) return x;
  if(n == 0) return 1;

  double answer = 1;
  if(n < 0) { n = abs(n); x = 1/x; }
  while(n > 0){
    if(n & 1) answer = answer*x;
    x = x*x; n = n>>1;
  } return x;
}

int main(){
  double x;
  int n;
  //cin>>x>>n;

  //cout<<myPow(x,n)<<endl;

  int check = -7;
  cout<<check%5<<"\n";
  return 0;
}
