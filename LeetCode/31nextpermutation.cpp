#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int binarysearch(vector<int>& arr,int start,int end,int val){

  int index = -1;
  int mid;

  while(start <= end){
    mid = (start+end)/2;
    if(arr[mid] <= val)
      end = mid-1;
    else {
      index = mid;
      start = mid+1;
    }
  }

  return index;
}

void nextPermutation(vector<int>& nums) {

  int n = nums.size();

  if(n == 0 || n == 1)
    return;

  int i = n-2;
  while(i >= 0){
    if(nums[i] < nums[i+1])
      break;
    i--;
  }

  if(i == -1){
    for(int j = 0;j < n/2; j++)
      swap(nums[j],nums[n-j-1]);
      return;
  }

  int index = binarysearch(nums,i+1,n-1,nums[i]);
  swap(nums[i],nums[index]);
  reverse(nums.begin()+i+1,nums.end());

}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  nextPermutation(arr);

  for(auto i:arr)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
