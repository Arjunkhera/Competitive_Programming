#include<iostream>

using namespace std;

#define len 1010

int main(){

  int n,capacity;
  int weights[len];
  int price[len];
  int arr[len]={0};

  cin>>n>>capacity;

  for(int i=0;i<n;i++)
    cin>>weights[i];

  for(int i=0;i<n;i++)
    cin>>price[i];

  for(int i=1;i<=capacity;i++)
    for(int j=0;j<n;j++)
      if(weights[j]<=i)
        arr[i] = max(arr[i],arr[i-weights[j]]+price[j]);

  cout<<arr[capacity]<<endl;
  return 0;
}
