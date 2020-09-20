#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool recursive(string s,string p){

  return true;
}

bool isMatch(string s, string p) {

  if(p.empty())
    return s.empty();

  int m = s.size();
  int n = p.size();

  vector< vector<bool> > arr(m+1,vector<bool>(n+1,0));
  arr[0][0] = true;

  for(int j = 1;j <= n;j++)
    if(p[j-1] == '*')
      arr[0][j] = arr[0][j-1];

  for(int i = 1;i <= m;i++)
    for(int j = 1;j <= n;j++){
      if(p[j-1] == '*')
        arr[i][j] = arr[i][j-1] || arr[i-1][j];
      else if(p[j-1] == '?' || p[j-1] == s[i-1])
        arr[i][j] = arr[i-1][j-1];
      else arr[i][j] = false;
    }

  return arr[m][n];
}

int main(){
  string s,p;
  cin>>s>>p;

  if(isMatch(s,p))
    cout<<"Found"<<endl;
  else cout<<"Not Found"<<endl;

  return 0;
}
