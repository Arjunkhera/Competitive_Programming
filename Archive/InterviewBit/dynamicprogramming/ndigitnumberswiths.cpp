#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

#define modulo 1000000007;
typedef unsigned long long int lli;

// solution function
lli solve(lli n,lli sum){
  lli temp,k;
  vector<vector<lli>> dp(n+1,vector<lli>(sum+1,0));
  for(lli i = 0;i <= n;i++) dp[i][0] = 1;

  for(lli i = 1;i <= n;i++)
    for(lli j = 1;j <= sum;j++){
      temp = 0;
      if(j > 8) k = j-9; else k = 0;
      if(i == n) { for(;k < j;k++) temp = (temp+dp[i-1][k])%modulo; }
      else { for(;k <= j;k++) temp = (temp+dp[i-1][k])%modulo; } 
      dp[i][j] = (temp)%modulo;
    }

  return dp[n][sum];
}

// driver function
int main(){
  lli n,sum;
  cin>>n>>sum;

  cout<<solve(n,sum)<<endl;
  return 0;
}

/*
5 4 6 8 7 2 3 -1
---------------
1 10 8 6 8 11 1 10 2 3 8 3 8 12 11 1 7 5 5 12 9 4 10 3 3 3 8 8 8 6 7 7 7 6 4 2 5 8 11 10 10 10 12 9 2 3 9 12 7 6 11 8 9 9 10 3 3 5 2 10 10 9 4 9 6 11 10 2 6 1 4 7 10 3 4 3 9 4 3 8 1 1 3 -1
*/
