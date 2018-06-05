#include<iostream>
#include<vector>

using namespace std;

int ceilingbinarysearch(vector<int> &arr,int val){

  int l = 0;
  int r = arr.size();
  int mid;

  while(r-l > 1){
    mid = l+(r-l)/2;
    if(arr[mid] > val)
      r = mid;
    else l = mid;
  }

  return r;
}

int floorsearch(vector<int> &arr,int val){

  int l = -1;
  int r = arr.size()-1;
  int mid;

  while(r-l > 1){
    mid = l+(r-l)/2;
    if(arr[mid] < val)
      l = mid;
    else r = mid;
  }

  return l;
}

int lessercomparison(vector<int> &arr,int val){

  int l = 0;
  int r = arr.size();
  int mid;

  while(r-l > 1){
    mid = l+(r-l)/2;
    if(arr[mid] <= val)
      l = mid;
    else r = mid;
  }

  if(arr[l] == val)
    return l;
  else return -1;
}

int binarysearch(vector<int> &arr,int val){

  int l = 0;
  int r = arr.size()-1;
  int mid;

  while(l <= r){
    mid = l+(r-l)/2;
    if(arr[mid] == val)
      return mid;
    else if(arr[mid] < val)
      l = mid+1;
    else r = mid-1;
  }

  return -1;
}

int main(){

  vector<int> arr = {1,2,4,5,6};
  int temp;
  cin>>temp;

  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cin>>temp;
  cout<<binarysearch(arr,temp)<<endl;
  cout<<lessercomparison(arr,temp)<<endl;
  cout<<floorsearch(arr,temp)<<endl;
  cout<<ceilingbinarysearch(arr,temp)<<endl;


  return 0;
}
