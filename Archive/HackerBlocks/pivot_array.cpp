#include<iostream>
#include<climits>

using namespace std;

int main(){
  int n,answer,largest=INT_MIN;
  cin>>n;

  int *arr = new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];

    if(arr[i]>largest){
      largest = arr[i];
      answer = i;
    }
  }
  /*
  int answer=-1;
  for(int i=0;i<n-1;i++){
    if(arr[i+1]-arr[i]>=0)
      answer = i;
  }
  */
  cout<<answer<<endl;
  return 0;
}
