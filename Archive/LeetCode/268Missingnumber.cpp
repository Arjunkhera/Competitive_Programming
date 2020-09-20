#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) {

  if(nums.empty())
    return 0;

  int n = nums.size();
  int X1 = nums[0];
  int X2 = 1;

  for(int i=1;i<n;i++)
    X1 = X1^nums[i];

  for(int i=2;i<=n;i++)
    X2 = X2^i;

  return (X1^X2);

}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<missingNumber(arr)<<endl;

  return 0;
}
