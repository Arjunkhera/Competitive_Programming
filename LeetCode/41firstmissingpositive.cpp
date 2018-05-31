#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums) {

  if(nums.empty())
    return 1;

  int temp;
  int i = nums.size();

  // shift the negative numbers including zero
  for(int j = nums.size()-1;j >= 0;j--)
    if(nums[j] <= 0){
        i--;
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

  for(int j = 0;j < i;j++)
    if((abs(nums[j]) - 1) < i && nums[abs(nums[j])-1] > 0)
      nums[abs(nums[j])-1] *= -1;

  for(int j = 0;j < i;j++)
    if(nums[j] > 0)
      return j+1;

  return i+1;
}

int main(){
  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -123){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<firstMissingPositive(arr)<<endl;

  return 0;
}
