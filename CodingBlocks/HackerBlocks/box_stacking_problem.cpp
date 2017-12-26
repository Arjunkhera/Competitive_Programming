#include<iostream>
#include<vector>
#include<climits>

using namespace std;
typedef long long int ll;
ll capacity;

ll solve(vector<ll> &heights,vector<pair<ll,ll>> &arr,vector<bool> visited,ll l,ll b,ll boxes){
  if(boxes == capacity)
    return 0;

  ll answer = INT_MIN;
  for(ll i=0;i<3*capacity;i++){
    if(visited[i])
      continue;

    if((arr[i].first<l && arr[i].second<b)||(arr[i].first<b && arr[i].second<l)){
      visited[i] = true;
      answer = max(answer,heights[i]+solve(heights,arr,visited,arr[i].first,arr[i].second,boxes+1));
      //backtrack
      visited[i] = false;
    }
  }
  return answer;
}

int main(){

  ll t,n,l,b,h,i,j;
  vector<pair<ll,ll>> arr;
  vector<ll>heights;
  vector<bool>visited;
  cin>>t;

  while(t--){
    cin>>n;
    capacity = n;
    for(i=0;i<n;i++){
      cin>>l>>b>>h;

      heights.push_back(l);
      arr.push_back(make_pair(b,h));
      visited.push_back(false);

      heights.push_back(b);
      arr.push_back(make_pair(l,h));
      visited.push_back(false);

      heights.push_back(h);
      arr.push_back(make_pair(b,l));
      visited.push_back(false);
    }

    cout<<solve(heights,arr,visited,INT_MAX,INT_MAX,0)<<"\n";
    heights.clear();
    visited.clear();
    arr.clear();
  }
  return 0;
}
