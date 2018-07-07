// leetcode question 9

#include<iostream>

using namespace std;

// solution function
bool isPalindrome(int x){
  // case 1
  if( x<0 || (x%10 == 0 && x != 0)) return false;

  // case 2
  int reverse = 0;
  while(x > reverse){ reverse = reverse*10 + x%10; x /= 10; }
  if(reverse == x || (reverse/10 == x)) return true;
  return false;
}

// driver function
int main(){

  int x;
  cin>>x;
  if(isPalindrome(x))
    cout<<"Match\n";
  else cout<<"Mismatch\n";
  return 0;
}
