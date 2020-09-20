// leetcode question 7

#include<iostream>
#include<climits>

using namespace std;

// solution function
int reverse(int x){
  int temp,answer = 0;
  while(x){
    temp = answer*10 + x%10;
    // overflow detection
    if( temp/10 != answer) return 0;
    answer = temp; x /= 10;
  }
  return answer;
}

// driver function
int main(){

  int x;
  cin>>x;
  x = reverse(x);
  cout<<"\n"<<x<<"\n";

  return 0;
}
