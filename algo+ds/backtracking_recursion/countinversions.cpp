#include<iostream>

using namespace std;

int crossinversions(int arr[],int start,int mid,int end){

  int temp[1000];
  int i = start;
  int k = start;
  int j = mid+1;
  int inversions = 0;

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

int countinversions(int arr[],int start,int end){

  if(start >= end)
   return 0;

  int mid = (start+end)/2;
  return countinversions(arr,start,mid) + countinversions(arr,mid+1,end) + crossinversions(arr,start,mid,end);

}

int main(){

  int n = 4;
  int arr[4] = {5,3,1,2};

  cout<<"The number of inversions are : "<<countinversions(arr,0,n-1)<<endl;

  return 0;
}
