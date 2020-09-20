#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
  return a.second < b.second;
}

ll solve(vector<pair<ll,ll>> &arr){
  sort(arr.begin(),arr.end(),compare);
  ll last,answer=1;

  last = arr[0].second;
  vector<pair<ll,ll>>::iterator i = arr.begin();
  while(i!=arr.end()){
    if((*i).first >= last){
      last = (*i).second;
      answer++;
    }
    i++;
  }
  return answer;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t,n,start,end;
  cin>>t;
  vector<pair<ll,ll>> arr;

  while(t--){
    cin>>n;
    for(ll i=0;i<n;i++){
      cin>>start>>end;
      arr.push_back(make_pair(start,end));
    }

    cout<<solve(arr)<<"\n";
    arr.clear();
  }

  return 0;
}
