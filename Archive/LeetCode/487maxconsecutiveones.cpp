#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// solution function
vector<int> findMaxConsecutiveOnes(vector<int>& nums,int m){
  vector<int> result;
  if(nums.empty()) return result;
  int index = 0,length = 0,count = 0,i = 0,left = 0,right = 0;
  while(right < nums.size()){
    if(count <= m){ if(nums[right] == 0) count++; right++; }
    if(count > m){ if(nums[left] == 0) count--; left++; }
    if((right-left) > length){ length = right-left; index = left; }
  }
  for(i = 0;i < length;i++){ result.push_back(index+i); }
  return result;
}

int main(){
  int n,temp;
  cin>>temp;
  vector<int> arr;
  while(temp != -1) { arr.push_back(temp); cin>>temp;};
  cin>>n;
  vector<int> answer = findMaxConsecutiveOnes(arr,n);
  for(auto k:answer) cout<<k<<" ";
  cout<<endl;
  return 0;
}

/*
1 0 0 1 1 0 1 0 1 1 1 -1 1
1 1 0 1 1 0 0 1 1 1 -1 1
*/
