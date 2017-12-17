#include<iostream>

using namespace std;
typedef long long int ll;

int main(){
  ll n;
  cin>>n;

  ll *values = new ll[n+1];
  ll *arr = new ll[n+1];

  for(ll i=1;i<=n;i++)
    cin>>values[i];

  arr[0]=0;
  arr[1]=values[1];
  for(ll i=2;i<=n;i++)
    arr[i] = max(arr[i-1],arr[i-2]+values[i]);

  cout<<arr[n]<<endl;
  return 0;
}
