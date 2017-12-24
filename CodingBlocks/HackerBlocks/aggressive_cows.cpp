#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;

bool issafe(vector<ll> &arr,ll distance,ll cows,ll n){
  ll last=0,temp,i=1;
  cows--;
  while(i<n && cows){
    temp = arr[i]-arr[last];
    if(temp < distance){
      i++;
      continue;
    }
    cows--;
    last = i;
    i++;
  }

  if(cows)
    return false;
  return true;
}

ll binarysearch(vector<ll> &arr,ll smallest,ll largest,ll cows,ll n){
  ll index = -1;
  ll start = smallest;
  ll end = largest;
  ll mid;

  while(start<=end){
    mid = (start+end)/2;

    if(issafe(arr,mid,cows,n)){
      index = mid;
      start = mid+1;
    }
    else end = mid-1;
  }
  return index;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t,temp,n,c,largest,smallest;
  vector<ll> arr;
  cin>>t;

  while(t--){

  largest = INT_MIN;
  smallest = INT_MAX;
  cin>>n>>c;
  for(ll i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
  }
  sort(arr.begin(),arr.end());
  for(ll i=0;i<n-1;i++){
    temp = arr[i+1]-arr[i];
    if(temp>largest)
      largest = temp;
    if(temp<smallest)
      smallest = temp;
  }

  cout<<binarysearch(arr,smallest,largest,c,n)<<"\n";
  arr.clear();
  }

  return 0;
}
