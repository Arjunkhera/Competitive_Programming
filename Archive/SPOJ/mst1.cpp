#include<iostream>
#include<climits>

using namespace std;
typedef long long int ll;

int dp[20000002];

/*
ll recursion(ll n){
  if(n==1)
    return 0;

  ll temp1 = recursion(n-1);
  ll temp2 = INT_MAX,temp3 = INT_MAX;
  if(n%2==0)
    temp2 = recursion(n/2);
  if(n%3==0)
    temp3 = recursion(n/3);

  return 1+min(min(temp1,temp2),temp3);
}

ll dp_memoization(ll n,ll *dp){
  if(dp[n] != -1)
    return dp[n];

  if(n<=1){
    dp[n] = 0;
    return dp[n];
  }

  ll temp1 = dp_memoization(n-1,dp);
  ll temp2 = INT_MAX,temp3 = INT_MAX;
  if(n%2==0)
    temp2 = dp_memoization(n/2,dp);
  if(n%3==0)
    temp3 = dp_memoization(n/3,dp);

  dp[n] = 1+min(min(temp1,temp2),temp3);
  return dp[n];
}
*/
int dp_tabulation(ll n){

  //ll *dp = new ll[n+3];
  dp[0]=0;
  dp[1]=0;

  for(ll i=2;i<=n;i++){
    dp[i] = 1+dp[i-1];
    if(i%3==0)
      dp[i] = min(dp[i],dp[i/3]+1);
    if(i%2==0)
      dp[i] = min(dp[i],dp[i/2]+1);
  }

  return dp[n];
}

int main(){

  int t;
  int i=1;
  ll n;
  cin>>t;
  while(i<=t){
      cin>>n;
      // normal recursion
      //cout<<recursion(n)<<"\n";

      // dp memoization
      /*
      ll *dp = new ll[n+1];
      for(int i=0;i<=n;i++)
        dp[i]=-1;
      cout<<dp_memoization(n,dp)<<"\n";
      */

      // dp tabulation
      cout << "Case " << i++ <<": " << dp_tabulation(n) << '\n';
  }
  return 0;
}
