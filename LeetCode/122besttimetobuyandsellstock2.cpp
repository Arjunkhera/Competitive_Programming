#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int maxProfit(vector<int>& prices){
  if(prices.size() == 0 || prices.size() == 1) return 0;

  int answer = 0;
  for(int i = 1;i < prices.size();i++) if(prices[i] > prices[i-1]) answer += prices[i]-prices[i-1];
  return answer;
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
