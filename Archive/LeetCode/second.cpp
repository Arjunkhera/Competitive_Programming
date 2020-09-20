#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long int li;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles){

}

int main(){

  int temp,tempy;
  vector<int> arr;
  vector<vector<int>> obstacles;

  cin>> temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  cin>> temp;
  while(temp != -1){ obstacles.push_back(temp); cin>>temp; cin>>tempy; }

  cout<<robotSim(arr,obstacles)<<endl;
  return 0;
}
