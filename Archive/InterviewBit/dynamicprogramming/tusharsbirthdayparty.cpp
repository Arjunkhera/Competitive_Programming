#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

// solution function
int solve(const vector<int> &capacity,const vector<int> &dishes,const vector<int> &costs){

  int n = dishes.size(),answer = 0,maxcap = 0;
  vector<pair<int,int>> capandcost(n);
  for(int i = 0;i < n;i++) { capandcost[i].first = dishes[i]; capandcost[i].second = costs[i]; }
  sort(capandcost.begin(),capandcost.end());

  for(int i = 0;i < capacity.size();i++) maxcap = max(maxcap,capacity[i]);

  vector<vector<long int>> dp(n+1,vector<long int>(maxcap+1,INT_MAX));
  for(int i = 0;i <= n;i++) dp[i][0] = 0;

  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= maxcap;j++)
      if(capandcost[i-1].first <= j) dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-capandcost[i-1].first]+capandcost[i-1].second,dp[i][j-capandcost[i-1].first]+capandcost[i-1].second));
      else dp[i][j] = dp[i-1][j];

  for(int i = 0;i <= n;i++){
    for(int j = 0;j <= maxcap;j++) cout<<dp[i][j]<<" ";
    cout<<endl;
  }

  for(int i = 0;i < capacity.size();i++) answer += dp[n][capacity[i]];
  return answer;
}

// driver function
int main(){
  vector<int> capacity,dishes,costs;
  int temp; cin>>temp;
  while(temp != -1){ capacity.push_back(temp); cin>>temp; }

  cin>>temp;
  while(temp != -1){ dishes.push_back(temp); cin>>temp; }

  cin>>temp;
  while(temp != -1){ costs.push_back(temp); cin>>temp; }

  cout<<solve(capacity,dishes,costs)<<endl;
  return 0;
}

/*
2 3 1 5 4 -1
3 2 4 1 -1
1 2 5 10 -1
*/
