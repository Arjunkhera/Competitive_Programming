#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

void solve(string digits,string str,vector<string> &keypad,vector<string> &answer,int cur){
  if(cur == digits.size()){ answer.push_back(str); return; }

  if(digits[cur] == '0' || digits[cur] == '1'){ solve(digits,str+digits[cur],keypad,answer,cur+1); return; }

  int index = digits[cur]-50,n = keypad[index].size();
  for(int i = 0;i < n;i++)
    solve(digits,str+keypad[index][i],keypad,answer,cur+1);
}

// solution function
vector<string> letterCombinations(string digits){
  vector<string> answer;
  if(digits.empty()) return answer;

  vector<string> keypad = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  solve(digits,"",keypad,answer,0);
  return answer;
}

int main(){
  string str;
  cin>>str;

  vector<string> answer = letterCombinations(str);
  for(auto i:answer) cout<<i<<endl;

  return 0;
}
