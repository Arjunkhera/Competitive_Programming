#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int rob(vector<int>& nums){
  if(nums.empty()) return 0;

  int temp,excl = 0,incl = nums[0],answer = nums[0];
  for(int i = 1;i < nums.size();i++){
    temp = excl + nums[i];
    excl = max(excl,incl);
    incl = temp;
    answer = max(incl,excl);
  }
  return answer;
}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<rob(arr)<<endl;
  return 0;
}
