#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfit(vector<int>& prices){

  if(prices.size() == 0 || prices.size() == 1)
    return 0;

  int answer = 0;
  int tempsum = 0;
  int buyprice = INT_MAX;
  int i = 0;

  for(;i < prices.size()-1;i++)
    if(prices[i] > prices[i+1]){
      answer = answer + max(0,prices[i]-buyprice);
      buyprice = prices[i+1];
      cout<<buyprice<<endl;
    }

  if(buyprice == INT_MAX)
    answer = prices[i-1] - prices[0];
  else if(buyprice != prices[i-1])
    answer = answer + max(0,prices[i-1]-buyprice);

  return answer;
}

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
