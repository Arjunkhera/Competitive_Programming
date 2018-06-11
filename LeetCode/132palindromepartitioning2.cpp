#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// O(n^2) bottom up
int bottomup(string str){

  int n = str.size();
  vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
  vector<int> cuts(n,0);

  for(int i = 0;i < n;i++)
    isPalindrome[i][i] = true;

  for(int l = 2;l <= n;l++){
    for(int i = 0;i < n-l+1;i++){
      int j = i+l-1;
      if(l == 2)
        isPalindrome[i][j] = (str[i] == str[j]);
      else isPalindrome[i][j] = ((str[i] == str[j]) && isPalindrome[i+1][j-1]);
    }
  }

  for(int i = 0;i < n;i++)
    if(isPalindrome[0][i])
      cuts[i] = 0;
    else {
      cuts[i] = INT_MAX;
      for(int j = 0;j < i;j++)
        if(isPalindrome[j+1][i])
          cuts[i] = min(cuts[i],cuts[j]+1);
    }

  return cuts[n-1];
}

// O(n^3) top down solution
int solve(string str,vector<vector<int>> &dp,int start,int end){

  if(start >= end)
    return 0;

  if(dp[start][end] != -1)
    return dp[start][end];

  if(str[start] == str[end] && !solve(str,dp,start+1,end-1)){
    dp[start][end] = 0;
    return 0;
  }

  int cuts = INT_MAX;
  for(int i = end-1;i >= start;i--)
    cuts = min(cuts,(solve(str,dp,start,i)+solve(str,dp,i+1,end)));
  dp[start][end] = cuts+1;

  return cuts+1;
}

int minCut(string s){

  if(s.empty())
    return 0;
  if(s.size() == 1)
    return 0;

  // vector< vector<int> > dp(s.size(),vector<int>(s.size(),-1));
  // return solve(s,dp,0,s.size()-1);
  return bottomup(s);
}

int main(){

  string str;
  cin>>str;

  cout<<minCut(str)<<endl;

  return 0;
}
