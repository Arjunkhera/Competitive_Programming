#include<iostream>
#include<vector>

using namespace std;

int recursive(int year,int start,int end,vector<int> &arr){

  if(start==end)
    return year*arr[start];

  int left = year*arr[start]+recursive(year+1,start+1,end,arr);
  int right = year*arr[end]+recursive(year+1,start,end-1,arr);
  return max(left,right);
}



int main(){

  int n,temp;
  cin>>n;

  vector<int>arr;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
  }

  cout<<recursive(1,0,n-1,arr)<<"\n";
  //cout<<memoization(n)<<"\n";

}
