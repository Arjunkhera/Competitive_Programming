#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

// solution function
int threeSumClosest(vector<int>& nums,int target){
  if(nums.empty()) return 0;

  sort(nums.begin(),nums.end());
  int n = nums.size(),answer = nums[0]+nums[1]+nums[2],tempsum,l,r;
  for(int i = 0;i < n;i++){
    l = i+1;r = n-1;
    while(l < r){ tempsum = nums[i] + nums[l]+nums[r];
      if(abs(tempsum - target) < abs(answer - target)) answer = tempsum;
      if(tempsum < target) l++; else r--;
    }
  }
  return answer;
}

int main(){
  int n,temp;
  cin>>n; temp = n;
  vector<int> arr(n,0);
  while(temp--) { cin>>arr[temp]; }
  cin>>n;
  cout<<threeSumClosest(arr,n)<<endl;
  return 0;
}
