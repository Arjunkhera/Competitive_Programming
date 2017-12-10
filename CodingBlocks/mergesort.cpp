#include<iostream>

using namespace std;

void merge(int arr[],int start,int mid,int end){

  int temp[1000];
  int i = start;
  int k = start;
  int j = mid+1;

  while(i<=mid && j<=end)
     if(arr[i]<=arr[j])
       temp[k++] = arr[i++];
     else temp[k++] = arr[j++];

  while(i<=mid)
   temp[k++] = arr[i++];

  while(j<=end)
   temp[k++] = arr[j++];

  for(int l=start;l<=end;l++)
    arr[l] = temp[l];

}

void mergesort(int arr[],int start,int end){

  if(start >= end)
    return;

  int mid = (start+end)/2;
  mergesort(arr,start,mid);
  mergesort(arr,mid+1,end);
  merge(arr,start,mid,end);
}

void display(int arr[],int n){
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

  cout<<endl;
}

int main(){

  int n = 4;
  int arr[4] = {5,3,1,2};

  mergesort(arr,0,n-1);
  display(arr,n);

  return 0;
}
