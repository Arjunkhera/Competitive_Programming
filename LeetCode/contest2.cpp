#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxDistToClosest(vector<int>& seats) {

  if(seats.empty())
    return 0;

  int answer = 0;
  int n = seats.size();
  vector<int> dist;

  int i = 0;
  while(i < n){
    if(seats[i] == 1)
      dist.push_back(i);
    i++;
  }

  int maxdist = 0;
  int temp = 0;
  for(int j = 0;j < dist.size()-1;j++){
    temp = dist[j+1] - dist[j];
    if(temp%2 == 0)
      temp /=2;
    else temp = (temp-1)/2;
    maxdist = max(maxdist,temp);
  }

  int left = dist[0];
  int right = (n-1) - dist[dist.size()-1];

  maxdist = max(maxdist,max(left,right));
  return maxdist;
}

int main(){

  vector<int> arr;
  int temp;
  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<maxDistToClosest(arr)<<endl;

  return 0;
}
