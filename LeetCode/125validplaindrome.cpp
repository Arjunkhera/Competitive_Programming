#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solution function
bool isPalindrome(string s){
  if(s.empty()) return true;

  string str; int i,j;
  for(i = 0,j = s.size()-1;i < j;i++,j--){
    while(isalnum(s[i]) == false && i < j) i++;
    while(isalnum(s[j]) == false && i < j) j--;
    if (toupper(s[i]) != toupper(s[j])) return false;
  }
  return true;
}

int main(){
  string str;
  getline(cin,str);

  if(isPalindrome(str)) cout<<"Valid\n";
  else cout<<"Not Valid\n";

  return 0;
}
