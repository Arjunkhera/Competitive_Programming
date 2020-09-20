#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void sortColors(vector<int>& nums){
  int i = -1,j = 0,k = nums.size(),l = 0;
  while(l < k){
    if(nums[l] == 0){ swap(nums[++i],nums[l]);j++;l++;}
    else if(nums[l] == 1){ j++;l++; }
    else swap(nums[l],nums[--k]);
  }
}

int main(){
  int temp;
  vector<int> arr;
  cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }
  sortColors(arr);
  for(auto i:arr) cout<<i<<" ";
  cout<<endl;
  return 0;
}
