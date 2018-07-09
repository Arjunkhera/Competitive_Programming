#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>

using namespace std;

// check if given number is a palindrome
bool isPalindrome(int x){
  // case 1
  if( x < 0 || (x%10 == 0 && x != 0)) return false;

  // case 2
  int reverse = 0;
  while(x > reverse){ reverse = reverse*10 + x%10; x /= 10; }
  if(reverse == x || (reverse/10 == x)) return true;
  return false;
}

// brute force : not to good, but will pass
int primePalindromebrute(int N){
  if(N <= 2) return 2; if(N <= 3) return 3; if(N <= 5) return 5; if(N <= 7) return 7;

  bool flag = false;
  long int i = N;
  while(1){
    // skip even number and not multiple of 6n+1 or 6n-1
    long int mod = i%6;
    if(!(i & 1) || (mod != 5 && mod != 1)) { i++; continue; }

    // check if number is palindrome
    if(!isPalindrome(i)) { i++; continue; }

    // check if prime
    long int last = sqrt(i),l = 2;
    for(l = 2;l <= last;l++) if(i%l == 0) break;
    if(l > last) break;
    i++;
  }
  return i;
}

// solution function : using construction of palindromes
int primePalindromebrute(int N){

}

// driver function
int main(){
  int n; cin>>n;

  cout<<primePalindrome(n)<<endl;
  return 0;
}
