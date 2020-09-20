#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
bool search(vector<int>& nums, int target){
  if(nums.empty()) return false;

  int n = nums.size(),start = 0,end = n-1,mid;
  while(start <= end){ mid = (start+end)/2;
    if(nums[mid] == target) return true;
    if( (nums[start] == nums[mid]) && (nums[end] == nums[mid]) ) {++start; --end;}
    else if(nums[start] <= nums[mid])
      if(nums[start] > target || nums[mid] < target) start = mid+1; else end = mid-1;
    else
      if(nums[mid] > target || nums[end] < target) end = mid-1; else start = mid+1;
  }
  return false;
}

int main(){
  int n,temp;
  vector<int> arr;
  cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }
  cin>>n;
  if(search(arr,n)) cout<<"Present\n"; else cout<<"Not Present\n";

  return 0;
}
