#include<iostream>
#include<climits>
#include<vector>

using namespace std;

typedef long long int ll;

/*
ll solve(ll arr[],ll n,ll start){

  if(arr[start]==0)
    return INT_MAX;

  if(n-start <= arr[start])
    return 1;

  ll index,result=INT_MIN;
  for(ll i=1;i<=arr[start];i++)
    if(arr[i+start]>=result)
      index = i+start;

  return 1+solve(arr,n,index);
}
*/

int main(){
  ll n;
  ll temp;
  cin>>n;

  vector<ll>values;
  vector<ll>arr;
  for(ll i=0;i<n;i++){
    cin>>temp;
    values.push_back(temp);
    arr.push_back(INT_MAX);
  }
  arr[0]=0;

  for(ll i=0;i<n;i++){
    temp = arr[i];
    for(ll j=1+i;j<=(values[i]+i);j++){
      if(arr[j] > temp)
        arr[j] = temp+1;

      if(j==n){
        i=n;
        break;
      }
    }
  }

  //cout<<solve(arr,n,0)<<endl;
  cout<<arr[n-1]<<endl;

  return 0;
}
