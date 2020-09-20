#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int longestValidParentheses(string s) {

  if(s.empty() || s.size() == 1)
    return 0;

  stack<int> stk;
  vector<int> arr(s.size(),-1);

  for(int i = 0;i < s.size();i++)
    if(s[i] == '(')
      stk.push(i);
    else if(s[i] == ')' && !stk.empty()){
      arr[stk.top()] = stk.top();
      arr[i] = stk.top();
      stk.pop();
    }

  while(!stk.empty()){
    arr[stk.top()] = stk.top();
    stk.pop();
  }

  for(int j = s.size()-1; j >= 0;j--)
    if(arr[j] != j && arr[j] != -1 && arr[j] != -2){
      arr[arr[j]] = -2;
      arr[j] = -2;
    }

  for(auto i:arr)
    cout<<i<<" ";
  cout<<endl;

  int answer = 0;
  int temp = 0;
  int i = 0;
  while(i < s.size())
    if(arr[i] == -2){
      temp = 0;
      while(i < s.size() && arr[i] == -2){
        temp++;
        i++;
      }
      answer = max(temp,answer);
    }
    else i++;

  return answer;
}

int main(){
  string s;
  cin>>s;

  cout<<longestValidParentheses(s)<<endl;

  return 0;
}
