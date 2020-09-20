#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int search(vector<int>& nums, int target){
  if(nums.empty()) return -1;

  int n = nums.size(),start = 0,end = n-1,mid;
  while(start <= end){ mid = (start+end)/2;
    if(nums[mid] == target) return mid;
    if(nums[start] <= nums[mid])
      if(nums[start] > target || nums[mid] < target) start = mid+1; else end = mid-1;
    else
      if(nums[mid] > target || nums[end] < target) end = mid-1; else start = mid+1;
  }
  return -1;
}

int main(){
  int n,temp;
  vector<int> arr;
  cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }
  cin>>n;
  cout<<search(arr,n)<<endl;

  return 0;
}
