#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<stack>

using namespace std;

// solution function : taken from discussion : absolutely fantastic solution
int evalRPN(vector<string>& tokens){
  if(tokens.empty()) return 0;

  int res,a,b; set<string> operators = {"+","-","/","*"}; stack<int> stk;
  for(int i = 0;i < tokens.size();i++){
    if(operators.find(tokens[i]) != operators.end()){
      if(stk.empty()) return 0; a = stk.top(); stk.pop();
      if(stk.empty()) return 0; b = stk.top(); stk.pop();
      switch(tokens[i][0]){
        case '+' : res = b+a; break;
        case '-' : res = b-a; break;
        case '*' : res = b*a; break;
        case '/' : res = b/a; break;
      }
      stk.push(res);
    }
    else stk.push(stoi(tokens[i]));
  }
  int answer = stk.top(); stk.pop();
  if(stk.empty()) return answer else return 0;
}

int main(){
  string temp;
  cin>>temp;
  vector<string> arr;
  while(temp != "end") { arr.push_back(temp); cin>>temp; }

  cout<<evalRPN(arr)<<endl;
  return 0;
}
