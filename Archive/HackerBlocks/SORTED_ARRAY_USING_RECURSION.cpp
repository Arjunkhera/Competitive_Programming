#include<iostream>

using namespace std;

typedef long long int ll;

void crossinversions(ll arr[],ll start,ll mid,ll end){

  ll temp[510];
  ll i = start;
  ll k = start;
  ll j = mid+1;

  while(i<=mid && j<=end){
    if(arr[i]<=arr[j])
      temp[k++] = arr[i++];
    else{
      temp[k++] = arr[j++];
    }
  }

  while(i<=mid)
    temp[k++] = arr[i++];

  while(j<=end)
    temp[k++] = arr[j++];

  for(int l=start;l<=end;l++)
    arr[l] = temp[l];
}

void countinversions(ll arr[],ll start,ll end){

  if(start >= end)
   return;

  ll mid = (start+end)/2;
  countinversions(arr,start,mid);
  countinversions(arr,mid+1,end);
  crossinversions(arr,start,mid,end);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll arr[1010],barr[1010];

  for(ll i=0;i<n;i++){
    cin>>arr[i];
    barr[i] = arr[i];
  }

  countinversions(arr,0,n-1);
  bool flag = true;

  for(ll i=0;i<n;i++)
    if(arr[i]!=barr[i]){
      flag = false;
      break;
    }

  if(flag)
    cout<<"true";
  else cout<<"false";

  return 0;
}
