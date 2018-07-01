#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// to avoid TLE
int maxProfit2(vector<int>& prices){
  if(prices.size() == 0 || prices.size() == 1) return 0;

  int answer = 0;
  for(int i = 1;i < prices.size();i++) if(prices[i] > prices[i-1]) answer += prices[i]-prices[i-1];
  return answer;
}

// solution function
int maxProfit(int k,vector<int>& prices){
  if(prices.size() == 0 || prices.size() == 1) return 0;

  int n = prices.size();
  // special case, when there is no limit : same as buysandsellstock2
  if(k >= n/2) return maxProfit2(prices);

  int low,count = 1; vector<vector<int>> dp(2,vector<int>(n,0));
  for(int j = 1;j <= k;j++){
    low = prices[0];
    for(int i = 1;i < n;i++){
      low = min(low,prices[i]-dp[(count+1)%2][i-1]);
      dp[count][i] = max(dp[count][i-1],prices[i]-low);
    }
    count = (count+1)%2;
  }
  return dp[(count+1)%2][n-1];
}

// driver function
int main(){

  vector<int> arr;
  int temp;
  cin>>temp;

  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }
  cin>>temp;

  cout<<maxProfit(temp,arr)<<endl;

  return 0;
}
