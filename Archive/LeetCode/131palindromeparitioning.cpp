#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<string>> solve(string str,vector<vector<int>> &dp,int start,int end){

  vector<vector<string>> answer;
  if(start >= end)
    return answer;

  for(int i = end;i >= start;i--){

    vector<vector<string>> left = solve(str,dp,start,i);
    vector<vector<string>> right = solve(str,dp,i+1,end);

    for(int i = 0;i < left.size();i++){
      vector<int> temp;
      for(int j = 0;j < right.size()j++)
        temp.push_back(left[i]+right[j]);
      answer.push_back(temp);
    }
  }

  return answer;
}

vector<vector<string>> partition(string s){
  if(s.empty()) return 0;
  if(s.size() == 1) return 0;

  vector< vector<int> > dp(s.size(),vector<int>(s.size(),-1));
  return solve(s,dp,0,s.size()-1);
}

int main(){
  string str; cin>>str;

  vector<vector<string>> answer = partition(str);
  return 0;
}
