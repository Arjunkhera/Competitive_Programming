#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// solution function
int triangleNumber(vector<int>& nums){
  if(nums.empty()) return 0;

  sort(nums.begin(),nums.end());
  int k,answer = 0,n = nums.size();
  for(int i = 0;i < n-2;i++)
    for(int j = i+1;j < n-1;j++){
      k = j+1;
      while(nums[i]+nums[j] > nums[k] && k < n) k++;
      answer += k-j-1;
    }
  return answer;
}

// approach similar to 3 closest : is faster
int triangleNumber2(vector<int>& nums){
  if(nums.size() < 3) return 0;

  sort(nums.begin(),nums.end());
  int l,r,answer = 0,n = nums.size();
  for(int i = 2;i < n;i++)
    for(l = 0,r = i-1;l < r;)
      if(nums[l]+nums[r] > nums[i]) { answer += (r-l); r--; }
      else l++;
  return answer;
}

int main(){
  int n,temp;
  cin>>temp;
  vector<int> arr;
  while(temp != -1) { arr.push_back(temp); cin>>temp;};
  cout<<triangleNumber2(arr)<<endl;
  return 0;
}
