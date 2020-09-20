#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// dynamic programming solution
int solve_dp(const vector<int>& arr){

  int n = arr.size();
  int temp,answer = 1;
  vector<int> left(n,1);
  vector<int> right(n,1);

  for(int i = 1;i < n; i++){
    temp = 1;
    for(int j = 0;j < i; j++) if(arr[j] < arr[i] && left[j]+1 > temp) temp = left[j]+1;
    left[i] = temp;
  }
  for(int i = n-2;i >= 0; i--){
    temp = 1;
    for(int j = i+1;j < n; j++) if(arr[j] < arr[i] && right[j]+1 > temp) temp = right[j]+1;
    right[i] = temp;
  }
  for(int i = 0;i < n;i++) answer = max(answer,left[i]+right[i]);

  return answer-1;
}

// solution function
int lengthOfLIS(const vector<int>& nums){

  // edge case
  if(nums.empty())
      return 0;
  return solve_dp(nums);
}

// driver function
int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while( temp != -1 ){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<lengthOfLIS(arr)<<endl;

  return 0;
}
