#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solution function
bool validPalindrome(string s){
  if(s.empty()) return true;

  int error1 = 0,error2 = 0,i = 0,j = s.size()-1;
  for(;i < j;i++,j--) if(s[i] != s[j]) { error1++; j++; }
  for(i = 0,j = s.size()-1;i < j;i++,j--) if(s[i] != s[j]) { error2++; i--; }
  return (error1 <= 1 || error2 <= 1);
}

int main(){
  string str;
  getline(cin,str);

  if(validPalindrome(str)) cout<<"Valid\n";
  else cout<<"Not Valid\n";

  return 0;
}
