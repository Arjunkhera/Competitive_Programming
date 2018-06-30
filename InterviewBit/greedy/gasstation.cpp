#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// solution function : from discussion
int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
  int start(0),total(0),tank(0);
  for(int i = 0;i < gas.size();i++) if((tank=tank+gas[i]-cost[i])<0) {start=i+1;total+=tank;tank=0;}
  return (total+tank<0)? -1:start;
}

int main(){
  int n,temp;
  cin>>n;
  vector<int> gas(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];

  cin>>n;
  vector<int> cost(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];

  cout<<canCompleteCircuit(gas,cost)<<endl;

  return 0;
}
