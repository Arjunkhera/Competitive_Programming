#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

  vector<int> arr(strs.size(),0);
  string answer;
  if(strs.empty())
    return answer;
  for(int i = 0;i < strs.size();i++)
    if(strs[i].empty())
      return answer;

  int index = 0;
  char cur = strs[0][0];
  bool flag = true;

  while(flag){
    for(int i = 0;i < strs.size();i++)
      if(index >= strs[i].size() || strs[i][index] != cur){
        flag = false;
        break;
      }
    if(flag){
      index++;
      cur = strs[0][index];
    }
  }

  answer = strs[0].substr(0,index);
  return answer;
}

int main(){

  vector<string> arr;
  string temp;
  cin>>temp;

  while(temp != "end"){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<longestCommonPrefix(arr)<<endl;

  return 0;
}
