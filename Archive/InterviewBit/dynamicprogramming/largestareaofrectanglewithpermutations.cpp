#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// solution function
int maximalRectangle(vector<vector<int>>& matrix){
  if(matrix.empty()) return 0;
  int temparea,answer = 1,n = matrix[0].size(),r = matrix.size();
  vector<int> heights(matrix[0].size(),0);
  for(int i = 0;i < r;i++){
    for(int j = 0;j < n;j++) if(matrix[i][j] == 1) heights[j] += 1; else heights[j] = 0;
    vector<int> sorted(heights);
    sort(sorted.begin(),sorted.end(),greater<int>());
    for(int k = 0;k < n;k++){ temparea = sorted[k]*(k+1); answer = max(answer,temparea); }
  }
  return answer;
}

// driver function
int main(){

  int m,n;
  cin>>m>>n;

  vector<vector<int>> grid(m,vector<int>(n,0));
  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;j++)
      cin>>grid[i][j];

  cout<<maximalRectangle(grid)<<endl;

  return 0;
}
