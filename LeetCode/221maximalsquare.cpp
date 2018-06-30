#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// solution function
int maximalSquare(vector<vector<char>>& matrix){
  if(matrix.empty()) return 0;
  int curheight,index,temparea,answer = 1,n = matrix[0].size(),r = matrix.size();
  vector<vector<int>> areas(r,vector<int>(n,0));
  for(int i = 0;i < n;i++) if(matrix[0][i] == '1') areas[0][i] = 1;
  for(int i = 0;i < r;i++) if(matrix[i][0] == '1') areas[i][0] = 1;
  for(int i = 1;i < r;i++) for(int j = 1;j < n;j++) if(matrix[i][j] == '1') areas[i][j] = min(areas[i-1][j-1],min(areas[i][j-1],areas[i-1][j])) + 1;
  for(int i = 1;i < r;i++) for(int j = 1;j < n;j++) answer = max(answer,areas[i][j]);
  return answer*answer;
}

int main(){

  int m,n;
  cin>>m>>n;

  vector<vector<char>> grid(m,vector<char>(n,0));
  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;j++)
      cin>>grid[i][j];

  cout<<maximalSquare(grid)<<endl;

  return 0;
}
