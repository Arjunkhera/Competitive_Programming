#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solution function
vector<vector<int>> threeSum(vector<int>& nums){
  vector<vector<int>> answer;
  if(nums.empty()) return answer;

  sort(nums.begin(),nums.end());
  int n = nums.size(),temp,tempsum;
  for(int i = 0;i < n;i++){
    int tempsum = -nums[i],l = i+1,r = n-1;
    while(l < r){ temp = nums[l]+nums[r];
      if(tempsum == temp){
          answer.push_back({nums[i],nums[l],nums[r]});
          l++;
          while(l<r && nums[l] == nums[l-1]) l++;
      }
      else if(temp < tempsum) l++;
      else r--;
    } while(i+1 < n && nums[i+1] == nums[i]) i++;
  }
  return answer;
}

int main(){
  int n,temp;
  cin>>n; temp = n;
  vector<int> arr(n,0);
  while(temp--) { cin>>arr[temp]; }
  vector<vector<int>> answer = threeSum(arr);
  for(int j = 0;j < answer.size();j++){
    for(auto i:answer[j]) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
