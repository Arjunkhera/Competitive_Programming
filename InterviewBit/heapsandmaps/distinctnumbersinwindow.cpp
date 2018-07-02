#include<iostream>
#include<vector>
#include<climits>
#include<map>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums,int k){
  vector<int> answer;
  if(nums.empty() || k > nums.size()) return answer;

  map<int,int> counts; int temp,distinct = 0;
  for(int i = 0;i < k;i++){
    if(counts.find(nums[i]) == counts.end()){ distinct++; counts[nums[i]] = 1; }
    else counts[nums[i]]++;
  }
  answer.push_back(distinct);
  for(int i = k;i < nums.size();i++) {
    if(counts[nums[i-k]] == 1){ counts.erase(nums[i-k]); distinct--; }
    else counts[nums[i-k]]--;
    if(counts.find(nums[i]) == counts.end()){ distinct++; counts[nums[i]] = 1; }
    else counts[nums[i]]++;
    answer.push_back(distinct);
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
