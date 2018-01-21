#include<iostream>

using namespace std;
typedef long long int ll;

void merge(ll arr[],ll start,ll mid,ll end){
  ll k = start;
  ll i = start;
  ll j = mid+1;
  ll temp[200010];

  while(i<=mid && j<=end){
    if(arr[i]<arr[j])
      temp[k++] = arr[i++];
    else temp[k++] = arr[j++];
  }

  while(i<=mid)
    temp[k++] = arr[i++];
  while(j<=end)
    temp[k++] = arr[j++];

  //copy the array back
  for(ll m=start;m<=end;m++)
    arr[m] = temp[m];
}

void mergesort(ll arr[],ll start,ll end){

  if(start>=end)
    return;

  ll mid = (start+end)/2;
  mergesort(arr,start,mid);
  mergesort(arr,mid+1,end);
  merge(arr,start,mid,end);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll arr[200010];
  //input
  for(ll i=0;i<n;i++)
    scanf("%lld",&arr[i]);

  mergesort(arr,0,n-1);

  //input
  for(ll i=0;i<n;i++)
    printf("%lld ",arr[i]);
  return 0;
}
