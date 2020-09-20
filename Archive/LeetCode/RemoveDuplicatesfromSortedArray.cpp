#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
  if(nums.empty())
    return 0;
  int i = 0;
  for(int j=1;j<nums.size();j++)
    if(nums[j]>nums[i])
      nums[++i] = nums[j];
  return i+1;
}

int main(){
  vector<int> arr;
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
  }
  //solve
  cout<<removeDuplicates(arr)<<endl;
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}
