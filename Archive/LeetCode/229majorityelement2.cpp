#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> majorityElement(vector<int>& nums){

  vector<int> answer;
  if(nums.empty())
    return answer;
  if(nums.size() == 1){
    answer.push_back(nums[0]);
    return answer;
  }

  // works for n/k
  int k = 3;
  map<int,int> candidates;
  for(int l = 0;l < k;l++)
    candidates[l] = 0;

  // first pass
  for(int i = 1;i < nums.size();i++){

    if(candidates.find(nums[i]) != candidates.end()){
      candidates[nums[i]]++;
      continue;
    }

    auto j = candidates.begin();
    for(;j != candidates.end();j++)
      if(j->second == 0)
          break;

    if(j != candidates.end()){
      candidates.erase(j);
      candidates[nums[i]] = 1;
      continue;
    }

    j = candidates.begin();
    for(;j != candidates.end();j++)
      j->second--;

  }

  int freq;
  int val;
  // second pass
  for(auto i = candidates.begin();i != candidates.end();i++){
    val = i->first;
    freq = 0;
    for(int j = 0;j < nums.size();j++)
      if(nums[j] == val)
        freq++;

    if(freq > nums.size()/k)
      answer.push_back(val);
  }

  return answer;
}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  vector<int> answer = majorityElement(arr);

  for(auto i:answer)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
