#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// solution function
int maximalRectangle(vector<vector<char>>& matrix) {
  if(matrix.empty()) return 0;
  int curheight,index,temparea,answer = 1,n = matrix[0].size(),r = matrix.size();
  vector<int> heights(matrix[0].size()+1,0);
  for(int i = 0;i < r;i++){
    for(int j = 0;j < n;j++) if(matrix[i][j] == '1') heights[j] += 1; else heights[j] = 0;
    stack<int> stk;
    for(int k = 0;k <= n;k++){
      while(!stk.empty() && heights[stk.top()] > heights[k]){
        curheight = heights[stk.top()]; stk.pop();
        index = (stk.empty()) ? -1 : stk.top();
        temparea = curheight*(k-1-index);
        answer = max(answer,temparea);
      }
      stk.push(k);
    }
  }
  return answer;
}

// solution function : if permutations are allowed
int maximalRectangle2(vector<vector<char>>& matrix) {
  if(matrix.empty()) return 0;
  int curheight,index,temparea,answer = 1,n = matrix[0].size(),r = matrix.size();
  vector<int> heights(matrix[0].size()+1,0);
  for(int i = 0;i < r;i++){
    for(int j = 0;j < n;j++) if(matrix[i][j] == '1') heights[j] += 1; else heights[j] = 0;
    vector<int> sorted(heights);
    sort(sorted.begin(),sorted.end()-1);
    stack<int> stk;
    for(int k = 0;k <= n;k++){
      while(!stk.empty() && sorted[stk.top()] > sorted[k]){
        curheight = sorted[stk.top()]; stk.pop();
        index = (stk.empty()) ? -1 : stk.top();
        temparea = curheight*(k-1-index);
        answer = max(answer,temparea);
      }
      stk.push(k);
    }
  }
  return answer;
}

int main(){

  int m,n;
  cin>>m>>n;

  vector<vector<char>> grid(m,vector<char>(n,0));
  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;j++)
      cin>>grid[i][j];

  cout<<maximalRectangle2(grid)<<endl;

  return 0;
}
