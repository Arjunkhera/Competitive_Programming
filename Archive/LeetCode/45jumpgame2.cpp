#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int Jump(vector<int>& nums){
  if(nums.size() == 1) return 1;

  int i = 0,n = nums.size(),jump = 0,curend = 0,newend = 0;
  while(curend-i+1 > 0){
    jump++;
    for(;i <= curend;i++){
      newend = max(newend,nums[i]+i);
      if(newend >= n-1) return jump;
    }
    curend = newend;
  }
  return 0;
}

int Jumpdp(vector<int>& nums){

  if(nums.empty()) return 0;
  if(nums.size() == 1) return 0;

  long int n = nums.size();
  vector<long int> dp(n,INT_MAX);

  for(long int i = n-2;i >= 0;i--)
    for(long int j = nums[i];j > 0;j--)
      if(i+j >= n-1){
        dp[i] = 1;
        break;
      }
      else dp[i] = min(dp[i],1+dp[i+j]);

  /*
  for(long int i = 0;i < dp.size();i++)
    cout<<dp[i]<<" ";
  cout<<endl;
  */

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

  cout<<Jump(arr)<<endl;

  return 0;
}
