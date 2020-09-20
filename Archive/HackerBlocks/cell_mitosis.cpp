#include<iostream>

using namespace std;

typedef long long int ll;

int main(){

  ll n,x,y,z;
  cin>>n>>x>>y>>z;

  //ll *arr = new ll[n];
  ll arr[100010]={0};
  //arr[0]=0;
  for(ll i=2;i<=n;i++)
    if(i%2==0)
      arr[i] = min(arr[i/2]+x,arr[i-1]+y);
    else arr[i] =  min(arr[i-1]+y,arr[(i+1)/2]+x+z);

  /*
  cout<<"\n------------\n";
  for(ll i=0;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  */

  cout<<arr[n]<<endl;

  return 0;
}
