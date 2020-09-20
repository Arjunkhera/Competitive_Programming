#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int removeElement(vector<int>& nums, int val) {
  if(nums.empty()) return 0;

  int i = -1,j = 0;
  while(j < nums.size()){
    if(nums[j] != val)swap(nums[++i],nums[j]);
    j++;
  }
  return i+1;
}

int main(){
  int n,temp;
  vector<int> arr;
  cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }
  cin>>n;
  cout<<removeElement(arr,n)<<endl;
  for(auto i:arr) cout<<i<<" ";
  cout<<endl;
  return 0;
}
