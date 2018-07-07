#include<iostream>
#include<climits>

using namespace std;

// solution function
int reverse(int x){
  int mod,temp,answer=0;
  while(x){
    mod = x%10;
    temp = answer*10 + mod;
    // overflow detection
    if( temp/10 != answer)
      return 0;

    answer = temp;
    x /= 10;
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
