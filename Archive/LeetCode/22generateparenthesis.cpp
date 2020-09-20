#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

void solve(int opening,int closing,int exp,string str,vector<string> &answer){
  if(opening == 0 && closing == 0) { answer.push_back(str); return; }
  if(opening > closing || exp < 0 ) return;

  if(opening > 0) solve(opening-1,closing,exp+1,str+"(",answer);
  if(closing > 0) solve(opening,closing-1,exp-1,str+")",answer);
}

// solution function
vector<string> generateParenthesis(int n) {
  vector<string> answer;
  if(n == 0) return answer;

  solve(n,n,0,"",answer);
  return answer;
}

int main(){
  int n;
  cin>>n;

  vector<string> answer = generateParenthesis(n);
  for(auto i:answer) cout<<i<<endl;

  return 0;
}
