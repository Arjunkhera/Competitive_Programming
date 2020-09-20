#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool solve(string str,string s){

  // base case
  if(str == s)
    return true;

  // to check whether the character set is matching in the strings
  int n = str.size();
  int arr[26] = {0};

  for(int i = 0;i < n;i++){
    arr[str[i] - 'a']++;
    arr[s[i] - 'a']--;
  }
  for(int i = 0;i < 26;i++)
    if(arr[i] != 0)
      return false;

  // place parenthesis to compare the strings
  for(int i = 1;i < n;i++){
    if(solve(str.substr(0,i),s.substr(0,i)) && solve(str.substr(i),s.substr(i)))
      return true;
    if(solve(str.substr(0,i),s.substr(n-i)) && solve(str.substr(i),s.substr(0,n-i)))
      return true;
  }

  return false;
}

bool isScramble(string s1, string s2) {
  if(s2.empty())
    return s1.empty();
  if(s1.size() != s2.size())
    return false;
  return solve(s1,s2);
}

int main(){

  string a,b;
  cin>>a>>b;

  if(isScramble(a,b))
    cout<<"Match"<<endl;
  else cout<<"Mismatch"<<endl;

  return 0;
}
