// leetcode 300

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// recursive solution : bottom up
int solve_recursive_1(vector<int>& arr,int max,int i){

  // base case
  if(i >= arr.size())
    return 0;

  int lengthExcluded = solve_recursive_1(arr,max,i+1);

  int lengthIncluded = 0;
  if(arr[i] > max)
    lengthIncluded = 1+solve_recursive_1(arr,arr[i],i+1);

  return std::max(lengthIncluded,lengthExcluded);
}

// recursive solution : top down
int solve_recursive_2(vector<int>& arr,int index,int* max){

  // base case
  if(index == 1)
    return 1;

  int localmaximum = 1,temp;
  for(int i = 1; i < index; i++){
    temp = solve_recursive_2(arr,i,max);

    if(arr[i-1] < arr[index-1] && temp+1 > localmaximum)
      localmaximum = temp+1;
  }

  if(localmaximum > *max)
    *max = localmaximum;

  return localmaximum;
}

// dynamic programming solution
int solve_dp(vector<int>& arr){

  int n = arr.size();
  int j,temp,max = 1;
  int* dp = new int[n];

  for(int i = 0;i < n;i++)
    dp[i] = 1;

  for(int i = 1;i < n; i++){
    temp = 1;
    j = 0;
    for(;j < i; j++)
        if(arr[j] < arr[i] && dp[j]+1 > temp)
          temp = dp[j]+1;

    dp[j] = temp;

    if(temp > max)
      max = temp;
  }

  return max;
}

// binary search for patience sort
int binary_search(vector<int>& tail,int dat){

  int first = 0;
  int last = tail.size()-1;
  int mid;

  while( last - first > 1 ){

    mid = first + (last-first)/2;

    if( tail[mid] >= dat)
        last = mid;
    else
        first = mid;
  }

  return last;
}

int solve_patience(vector<int>& arr){

  vector<int> tail(arr.size(),0);
  int length = 1;
  tail[0] = arr[0];

  for(int i = 1; i < arr.size(); i++)
    if(tail[0] > arr[i])
      tail[0] = arr[i];
    else if(tail[length-1] < arr[i])
      tail[length++] = arr[i];
    else tail[binary_search(arr,arr[i])] = arr[i];

  return length;
}

int lengthOfLIS(vector<int>& nums){

  // edge case
  if(nums.empty())
      return 0;

  int answer = 1;
  // solve_recursive_2(nums,nums.size(),&answer);
  // return solve_recursive_1(nums,0,0);

  // answer = solve_dp(nums);
  answer = solve_patience(nums);

  return answer;
}

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
