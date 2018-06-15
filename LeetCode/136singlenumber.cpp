#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int singleNumber(vector<int>& nums) {
  if(nums.empty()) return 0;

  int answer = 0;
  for(auto i:nums) answer = answer^i;
  return answer;
}

int main(){
 int n,temp;
 vector<int> arr;
 cin>>temp;
 while(temp != -1) { arr.push_back(temp); cin>>temp; }
 cout<<singleNumber(arr)<<endl;
 return 0;
}
