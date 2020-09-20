#include<iostream>
#include<map>
#include<vector>

using namespace std;

// discussion solution
int lengthOfLongestSubstring_optimised(string s){
  vector<int> dict(256, -1);
  int maxLen = 0, start = -1;
  for (int i = 0; i != s.length(); i++) {
    if (dict[s[i]] > start){
      start = dict[s[i]];
      dict[s[i]] = i;
      maxLen = max(maxLen, i - start);
    }
  }
  return maxLen;
}

int lengthOfLongestSubstring(string s){
  int answer=0,len=0;
  map<char,int> substr;
  map<char,int>::iterator j;

  for(int i=0;i<s.length();){
    // if match, increase length
    j = substr.find(s[i]);
    if(j == substr.end()){
      substr[s[i]] = i;
      len++;
      i++;
      continue;
    }

    // reset progress
    if(answer < len)
      answer = len;
    i = j->second+1;
    substr.clear();
    len = 0;
  }
  if(answer < len)
    answer = len;

  return answer;
}

int main(){
  string str;
  cin>>str;
  cout<<lengthOfLongestSubstring(str)<<endl;
  return 0;
}
