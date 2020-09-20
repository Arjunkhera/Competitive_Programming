#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// not optimized
string shortestPalindrome_temp(string s){
  if(s.empty()) return s;

  int k,i,j,last = 0,n = s.size();
  for(k=0;k<n;k++){
    for(i=k,j=k;(s[i]==s[j]) && i>=0 && j<n;i--,j++);
    if(i < 0 && j > last) last = j-1;
    for(i=k,j=k+1;(s[i]==s[j]) && i>=0 && j<n;i--,j++);
    if(i < 0 && j > last) last = j-1;
  }
  string answer = "";
  for(k = n-1;k > last;k--) answer.push_back(s[k]);
  return answer+s;
}

// using kmp
string shortestPalindrome(string s){
  if(s.empty()) return s;

  string str = s; reverse(str.begin(),str.end());
  str = s + "#" + str;
  int m = str.size(),i = 0,j = 1;
  vector<int> preprocess(m,0);
  while(j < m)
    if(str[i] == str[j]){ preprocess[j] = i+1; i++; j++; }
    else {
      while(i != 0 && str[i] != str[j]) i = preprocess[i-1];
      if(str[i] == str[j]){ preprocess[j] = i+1; i++; }
      j++; }
  str = s.substr(preprocess[m-1]); reverse(str.begin(),str.end());
  return str + s;
}

int main(){
  string str;
  getline(cin,str);

  cout<<shortestPalindrome(str)<<endl;
  return 0;
}
