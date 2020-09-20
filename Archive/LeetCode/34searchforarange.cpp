#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int search(vector<int>& nums, int target,bool direction){
  int n = nums.size(),start = 0,end = n-1,index = -1,mid;
  while(start <= end){ mid = (start+end)/2;
    if(nums[mid] == target) { index = mid; if(direction) end = mid-1; else start = mid+1;}
    else if(nums[mid] > target) end = mid-1; else start = mid+1;
  }
  return index;
}

// solution function
vector<int> searchRange(vector<int>& nums, int target){
  vector<int> arr(2,-1);
  if(nums.empty()) return arr;
  arr[0] = search(nums,target,true); arr[1] = search(nums,target,false);
  return arr;
}

int main(){
  int n,temp;
  vector<int> arr;
  cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }
  cin>>n;
  vector<int> answer = searchRange(arr,n);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;
  return 0;
}
