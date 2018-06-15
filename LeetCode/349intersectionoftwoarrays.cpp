#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

// solution function
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  vector<int> answer; unordered_set<int> st;
  if(nums1.empty() || nums2.empty()) return answer;

  sort(nums1.begin(),nums1.end()); sort(nums2.begin(),nums2.end());
  int i = 0,j = 0,len1 = nums1.size(),len2 = nums2.size();
  while(i < len1 && j < len2){
    if(nums1[i] == nums2[j]) { st.insert(nums1[i]); i++;j++;}
    else if(nums1[i] < nums2[j]) i++; else j++;
  }
  for(auto i:st) answer.push_back(i);
  return answer;
}

// another solution
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
  vector<int> answer;
  if(nums1.empty() || nums2.empty()) return answer;

  unordered_set<int> st(nums1.begin(),nums1.end());
  for(auto i:nums2) if(st.find(i) != st.end()) {answer.push_back(i); st.erase(i);}
  return answer;
}

int main(){
  int n,temp;
  cin>>n; temp = n;
  vector<int> arr1(n,0);
  while(temp--) { cin>>arr1[temp]; }

  cin>>n; temp = n;
  vector<int> arr2(n,0);
  while(temp--) { cin>>arr2[temp]; }

  vector<int> answer = intersect2(arr1,arr2);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;
  return 0;
}
