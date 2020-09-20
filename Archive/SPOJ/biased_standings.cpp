#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef long long int ll;

bool compare(ll a,ll b){
  return a < b;
}

ll solve(vector<ll> &arr){
  sort(arr.begin(),arr.end(),compare);
  ll rank=1,badness=0;

  vector<ll>::iterator i = arr.begin();
  while(i!=arr.end()){
    badness += abs(rank - *i);
    rank++;
    i++;
  }
  return badness;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t,n,temp;
  string str;
  cin>>t;
  vector<ll> arr;

  while(t--){
    cin>>n;
    for(ll i=0;i<n;i++){
      cin>>str>>temp;
      arr.push_back(temp);
    }

    cout<<solve(arr)<<"\n";
    arr.clear();
  }

  return 0;
}
