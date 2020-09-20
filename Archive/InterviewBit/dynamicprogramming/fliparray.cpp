#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

// solution function
int solve(vector<int> &arr){
  if(arr.empty()) return 0;

  long int newsum,sum = 0,n = arr.size();
  for(int i = 0;i < n;i++) sum += arr[i];
  newsum = sum/2;

  vector<int> dp(newsum+1,INT_MAX);
  dp[0] = 0;

  // construct the dp array
  for(int i = 0;i < n;i++)
    for(int j = newsum;j >= arr[i];j--)
      if(dp[j-arr[i]] != INT_MAX) dp[j]= min(dp[j],dp[j-arr[i]]+1);

  int i = newsum;
  while(i >= 0 && dp[i] == INT_MAX) i--;
  return dp[i];
}

// driver function
int main(){
  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  cout<<solve(arr)<<endl;
  return 0;
}

/*
5 4 6 8 7 2 3 -1
---------------
1 10 8 6 8 11 1 10 2 3 8 3 8 12 11 1 7 5 5 12 9 4 10 3 3 3 8 8 8 6 7 7 7 6 4 2 5 8 11 10 10 10 12 9 2 3 9 12 7 6 11 8 9 9 10 3 3 5 2 10 10 9 4 9 6 11 10 2 6 1 4 7 10 3 4 3 9 4 3 8 1 1 3 -1
*/
