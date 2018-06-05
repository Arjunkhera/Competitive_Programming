#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n){

  if(n == 0 || n == 1)
    return 1;

  vector<int> arr(n+1,0);
  arr[0] = 1;
  arr[1] = 1;

  for(int i = 2;i < arr.size();i++)
    arr[i] = arr[i-1]+arr[i-2];

  return arr[n];
}

int main(){

  int n;
  cin>>n;

  cout<<climbStairs(n)<<endl;

  return 0;
}
