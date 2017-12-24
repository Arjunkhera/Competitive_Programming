#include<iostream>

using namespace std;
typedef long long int ll;

int binarysearch(ll *arr,ll n,ll m){
  ll index = -1;
  ll start = 0;
  ll end = n-1;
  ll mid;

  while(start<=end){
    mid = (start+end)/2;

    if(arr[mid] == m){
      index = mid;
      break;
    }

    if(arr[mid]>m)
      end = mid-1;
    else start = mid+1;
  }

  return index;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n;
  ll *arr = new ll[n];
  for(ll i=0;i<n;i++)
    cin>>arr[i];
  cin>>m;

  cout<<binarysearch(arr,n,m);
  return 0;
}
