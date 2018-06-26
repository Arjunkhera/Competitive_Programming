#include<iostream>

using namespace std;

int recursion(int n){

  if(n==1 || n==0)
    return 1;

  return recursion(n-1)+recursion(n-2);
}

int dp(int n){
  int arr[100];

  // bottom up : tabulation
  arr[0] = 1;
  arr[1] = 1;
  for(int i=2;i<=n;i++)
    arr[i] = arr[i-1]+arr[i-2];

  return arr[n];
}

int main(){

  int n;
  cin>>n;

  //cout<<recursion(n);
  //cout<<dp(n);
}
