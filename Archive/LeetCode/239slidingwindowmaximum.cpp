#include<iostream>
#include<vector>
#include<climits>
#include<deque>
#include<set>

using namespace std;

// solution function : taken from discussion : absolutely fantastic solution
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> dq; vector<int> answer;
  if(nums.empty()) return answer;

  for(int i = 0;i < nums.size();i++){
    // remove all smaller elements
    while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    // push current element
    dq.push_back(i);
    // print the output
    if(i >= k-1) answer.push_back(nums[dq.front()]);
    // remove front element if out of bounds
    if(dq.front() <= i-k+1) dq.pop_front();
  }
  return answer;
}

// using self balancing tree : slower than deque solution
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
  multiset<int> arr; vector<int> answer;
  if (nums.empty()) return answer;

  for(int i = 0, n = nums.size(); i < n; i++){
   if (i >= k) arr.erase(arr.find(nums[i-k]));
   arr.insert(nums[i]);
   if(i >= k-1) answer.push_back(*arr.rbegin());
  }
  return answer;
}

int main(){
  int n,temp;
  cin>>temp;
  vector<int> arr;
  while(temp != -100) { arr.push_back(temp); cin>>temp; }
  cin>>n;

  vector<int> answer = maxSlidingWindow(arr,n);
  for(auto k:answer) cout<<k<<" ";
  cout<<endl;
  return 0;
}
