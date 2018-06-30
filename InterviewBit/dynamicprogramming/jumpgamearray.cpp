#include<iostream>
#include<vector>

using namespace std;

// taken from discussions
bool fastest(vector<int>& nums){
  int i = 0,distance = 0,n = nums.size()-1;
  while(i < n && i <= distance){ distance = max(distance,i+nums[i]); i++; }
  return (i == n);
}

bool fastestrighttoleft(vector<int>& nums){
  int lastPos = nums.size() - 1;
  for (int i = nums.size() - 1; i >= 0; i--) if (i + nums[i] >= lastPos) lastPos = i;
  return lastPos == 0;
}

// solution function
bool canJump(vector<int>& nums){

  if(nums.empty() || nums.size() == 1) return true;

  int n = nums.size();
  vector<bool> dp(n,false);

  for(int i = n-2;i >= 0;i--) for(int j = nums[i];j > 0;j--) if(i+j >= n-1 || dp[i+j]){ dp[i] = true; break; }
  return dp[0];
}

int main(){

  vector<int> arr;
  int temp;
  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  if(canJump(arr))
    cout<<"Yes"<<endl;
  else cout<<"No"  <<endl;

  return 0;
}
