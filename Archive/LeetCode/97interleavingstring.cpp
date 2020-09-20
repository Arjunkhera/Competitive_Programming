#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool solve(string s1, string s2, string s3,int i,int j,int k,int** dp){
  // cout<<i<<"--"<<j<<"--"<<k<<endl;
  if(dp[i+1][j+1] != -1)
    return dp[i+1][j+1];

  // base case : either of the string is empty
  if(i < 0 && j < 0)
    if(k < 0)
      return true;
    else return false;

  if(i < 0){
    if(k != j){
      dp[i+1][j+1] = 0;
      return false;
    }
    if(s3[k] != s2[j]){
      dp[i+1][j+1] = 0;
      return false;
    }
    dp[i+1][j+1] = solve(s1,s2,s3,i,j-1,k-1,dp);
    return dp[i+1][j+1];
  }

  if(j < 0){
    if(k != i){
      dp[i+1][j+1] = 0;
      return false;
    }
    if(s3[k] != s1[i]){
      dp[i+1][j+1] = 0;
      return false;
    }
    dp[i+1][j+1] = solve(s1,s2,s3,i-1,j,k-1,dp);
    return dp[i+1][j+1];
  }

  // none of the strings match
  if(s3[k] != s1[i] && s3[k] != s2[j]){
    dp[i+1][j+1] = 0;
    return false;
  }

  // single string match
  if(s3[k] == s1[i] && s3[k] != s2[j])
    dp[i+1][j+1] = solve(s1,s2,s3,i-1,j,k-1,dp);
  else if(s3[k] != s1[i] && s3[k] == s2[j])
    dp[i+1][j+1] = solve(s1,s2,s3,i,j-1,k-1,dp);

  if(dp[i+1][j+1] != -1)
    return dp[i+1][j+1];

  // both strings match
  dp[i+1][j+1] = solve(s1,s2,s3,i-1,j,k-1,dp);
  if(dp[i+1][j+1])
    return true;
  dp[i+1][j+1] = solve(s1,s2,s3,i,j-1,k-1,dp);
  return dp[i+1][j+1];
}

bool isInterleave(string s1, string s2, string s3){

  int m = s1.size();
  int n = s2.size();
  int k = s3.size();

  int** dp = new int*[m+1];
  for(int i = 0;i <= m;i++)
    dp[i] = new int[n+1];

  for(int i = 0;i <= m;i++)
    for(int j = 0;j <= n;j++)
      dp[i][j] = -1;

  if(s1.empty() && s2.empty())
    return s3.empty();
  if(s1.empty())
    return (s2 == s3);
  if(s2.empty())
    return (s1 == s3);

  return solve(s1,s2,s3,m-1,n-1,k-1,dp);
}

int main(){

  string a,b,c;
  cin>>a>>b>>c;

  if(isInterleave(a,b,c))
    cout<<"Match"<<endl;
  else cout<<"Mismatch"<<endl;

  return 0;
}
