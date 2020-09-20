#include<iostream>

using namespace std;

typedef long long int ll;

ll crossinversions(ll arr[],ll start,ll mid,ll end){

  ll temp[51000];
  ll i = start;
  ll k = start;
  ll j = mid+1;
  ll inversions = 0;

  while(i<=mid && j<=end){
    if(arr[i]<=arr[j])
      temp[k++] = arr[i++];
    else{
      inversions += mid-i+1;
      temp[k++] = arr[j++];
    }
  }

  while(i<=mid)
    temp[k++] = arr[i++];

  while(j<=end)
    temp[k++] = arr[j++];

  for(int l=start;l<=end;l++)
    arr[l] = temp[l];

  return inversions;
}

ll countinversions(ll arr[],ll start,ll end){

  if(start >= end)
   return 0;

  ll mid = (start+end)/2;
  return countinversions(arr,start,mid) + countinversions(arr,mid+1,end) + crossinversions(arr,start,mid,end);

}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  ll n;
  ll arr[100001];

  cin>>t;

  while(t--){
    cin>>n;

    for(ll i=0;i<n;i++)
      cin>>arr[i];

    cout<<countinversions(arr,0,n-1)<<"\n";
  }
  return 0;
}
