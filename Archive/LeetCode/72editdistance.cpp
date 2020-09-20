#include<iostream>
#include<string>
#include<vector>

using namespace std;

int minDistance(string word1, string word2) {

  if(word1.empty() && word2.empty())
    return 0;
  else if(word1.empty())
    return word2.size();
  else if(word2.empty())
    return word1.size();

  int m = word1.size();
  int n = word2.size();

  vector< vector<int> > dp(m+1,vector<int>(n+1,0));

  int answer = 0;
  for(int i = 0;i <= m;i++)
    for(int j = 0;j <= n;j++)
      if(i == 0)
        dp[i][j] = j;
      else if(j == 0)
        dp[i][j] = i;
      else if(word1[i-1] == word2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;

  return dp[m][n];
}

int main(){

  string a,b;
  cin>>a>>b;

  cout<<minDistance(a,b)<<endl;

  return 0;
}
