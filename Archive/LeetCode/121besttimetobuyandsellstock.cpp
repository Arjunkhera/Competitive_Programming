#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int method2(vector<int>& prices){

  if(prices.size() == 0 || prices.size() == 1)
    return 0;

  vector<int> ltor(prices.size(),-1);
  vector<int> rtol(prices.size(),-1);

  int temp = 0;
  ltor[0] = 0;
  for(int i = 1;i < prices.size();i++)
    if(prices[i] > prices[temp])
      ltor[i] = temp;
    else {
      ltor[i] = i;
      temp = i;
    }

  temp = prices.size()-1;
  rtol[prices.size()-1] = prices.size()-1;
  for(int i = prices.size()-2;i >= 0;i--)
    if(prices[i] < prices[temp])
      ltor[i] = temp;
    else {
      rtol[i] = i;
      temp = i;
    }

  int answer = 0;;
  for(int i = 0;i < prices.size();i++)
    if(ltor[i] != rtol[i])
      answer = max(answer,prices[rtol[i]] - prices[ltor[i]]);

  return answer;
}

// solution function
int maxProfit(vector<int>& prices){

  if(prices.size() == 0 || prices.size() == 1)
    return 0;

  int answer = 0;
  int minelement = INT_MAX;

  for(int i = 0;i < prices.size();i++)
    if(prices[i] < minelement)
      minelement = prices[i];
    else answer = max(answer,prices[i]-minelement);

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
