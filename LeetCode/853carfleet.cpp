#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

bool mycomp(pair<int,int> a,pair<int,int> b){
  if(a.first < b.first) return true;
  if(a.first == b.first && a.second < b.second) return true;
  return false;
}

// solution function
int carFleet(int target, vector<int>& position, vector<int>& speed){
  if(position.size() < 2) return position.size();

  vector<pair<int,int>> arr;
  for(int i = 0;i < position.size();i++) arr.push_back(make_pair(position[i],speed[i]));
  sort(arr.begin(),arr.end(),mycomp);

  int answer = 0; pair<float,float> mintime; float time_overtake,time_toreach;

  //cout<<"Hello\n";
  for(int j = 1;j < position.size();j++){
    // cout<<arr[j].first<<" "<<arr[j].second<<endl;
    mintime = make_pair(INT_MAX,-1);
    for(int i = 0; i < j;i++)
      if(arr[i].first != -1 && arr[j].second < arr[i].second){
        time_overtake = (float)(arr[j].first - arr[i].first)/(arr[i].second - arr[j].second);
        time_toreach = (float)(target - arr[j].first)/arr[j].second;
        if(time_overtake <= time_toreach && time_overtake < mintime.first) { mintime.first = time_overtake;mintime.second = i;}
      }
    if(mintime.second != -1){
      time_overtake = mintime.first;
      arr[j].first += ceil(time_overtake*arr[j].second);
      // cout<<"and :"<<arr[j].first<<" "<<time_overtake<<endl;
      arr[mintime.second].first = -1;
    }
  }
  // cout<<"----------\n";
  for(int i = 0;i < position.size();i++) if(arr[i].first != -1) answer++;
  //cout<<arr[i].first<<" "<<arr[i].second<<endl;
  return answer;
}

int main(){
  int n,temp;
  cin>>temp;
  vector<int> arr1;
  while(temp != -1) { arr1.push_back(temp); cin>>temp; }

  cin>>temp;
  vector<int> arr2;
  while(temp != -1) { arr2.push_back(temp); cin>>temp; }

  cin>>n;

  cout<<carFleet(n,arr1,arr2)<<endl;

  return 0;
}

/*
10 8 0 5 3 -1
2 4 1 1 3 -1
12
*/
