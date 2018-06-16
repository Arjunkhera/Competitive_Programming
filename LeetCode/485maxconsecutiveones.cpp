#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// solution function
int findMaxConsecutiveOnes(vector<int>& nums){
  if(nums.empty()) return 0;
  int count = 0,i = 0,answer = INT_MIN;
  for(;i < nums.size();i++) if(nums[i]) count++; else { answer = max(answer,count); count = 0;}
  return max(answer,count);
}

int main(){
  int n,temp;
  cin>>n; temp = n;
  vector<int> arr(n,0);
  while(temp--) { cin>>arr[temp]; }

  cout<<findMaxConsecutiveOnes(arr)<<endl;
  return 0;
}
