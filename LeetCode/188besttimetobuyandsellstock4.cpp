#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<deque>

using namespace std;

int maxProfit(int k,vector<int>& prices){

  if(prices.size() == 0 || prices.size() == 1)
    return 0;

  int n = prices.size();
  deque<pair<int,int>> arr;

  int i = 0;
  while(i < n-1){
    while(i < n-1 && prices[i] >= prices[i+1])
      i++;
    if(i == n-1)
      break;
    arr.push_back(make_pair(i,i+1));
    i++;
  }

  for(auto i:arr)
    cout<<i.first<<" "<<i.second<<endl;

  priority_queue< int,vector<int>,greater<int> > final;
  pair<int,int> first,second;
  while(!arr.empty()){
    first = arr.front();
    arr.pop_front();

    if(arr.empty()){
      cout<<"adding : "<<prices[first.second]-prices[first.first]<<endl;
      final.push(prices[first.second]-prices[first.first]);
      break;
    }

    second = arr.front();
    arr.pop_front();

    if(prices[second.first] >= prices[first.first]){
      if(second.second >= prices[first.second])
        prices[first.second] = prices[second.second];
      arr.push_front(first);
    }
    else {
      cout<<"adding : "<<prices[first.second]-prices[first.first]<<endl;
      final.push(prices[first.second]-prices[first.first]);
      arr.push_front(second);
    }
  }

  while(final.size() > k)
    final.pop();
  int answer = 0;
  while(!final.empty()){
    answer = answer + final.top();
    final.pop();
  }

  return answer;
}

int main(){

  vector<int> arr;
  int temp,k;
  cin>>k>>temp;

  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<maxProfit(k,arr)<<endl;

  return 0;
}

/*
for(auto i:arr)
  cout<<i.first<<" "<<i.second<<endl;
*/
