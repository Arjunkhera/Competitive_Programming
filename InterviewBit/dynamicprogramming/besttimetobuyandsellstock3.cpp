// Leetcode question 123 

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int maxProfit(vector<int>& prices){
  if(prices.size() == 0 || prices.size() == 1) return 0;

  int buy1 = INT_MAX,buy2 = INT_MAX,sell1 = 0,sell2 = 0;
  for(int i = 0;i < prices.size();i++){
    buy1 = min(buy1,prices[i]);
    sell1 = max(sell1,prices[i]-buy1);
    buy2 = min(buy2,prices[i]-sell1);
    sell2 = max(sell2,prices[i]-buy2);
  }
  return sell2;
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

  cout<<maxProfit(arr)<<endl;

  return 0;
}
