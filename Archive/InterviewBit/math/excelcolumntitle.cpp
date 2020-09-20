// leetcode question 168

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// solution function
int titleToNumber(string s){
  int n = s.size(),answer = 0;
  for(int i = 0;i < n;i++) answer = answer*26 + (s[i]-64);
  return answer;
}

// driver function
int main(){
  string str; cin>>str;
  cout<<titleToNumber(str)<<endl;

  return 0;
}
