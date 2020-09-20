#include<iostream>
#include<vector>

using namespace std;

// space optimized -> from discussions
int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<int> cur(m, grid[0][0]);
       for (int i = 1; i < m; i++)
           cur[i] = cur[i - 1] + grid[i][0];
       for (int j = 1; j < n; j++) {
           cur[0] += grid[0][j];
           for (int i = 1; i < m; i++)
               cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
       }
       return cur[m - 1];
}

// solution function
int minPathSum(vector<vector<int>>& grid) {

  if(grid.empty())
    return 0;

  int m = grid.size();
  int n = grid[0].size();

  vector< vector<long int> > arr(m,vector<long int>(n,0));
  arr[0][0] = grid[0][0];
  for(int i = 1;i < m;i++)
    arr[i][0] = grid[i][0] + arr[i-1][0];
  for(int i = 1;i < n;i++)
    arr[0][i] = grid[0][i] + arr[0][i-1];

  for(int i = 1;i < m;i++)
    for(int j = 1;j < n;j++)
      arr[i][j] = grid[i][j] + min(arr[i-1][j],arr[i][j-1]);

  return arr[m-1][n-1];
}

int main(){

  int m,n;
  cin>>m>>n;

  vector<vector<int>> grid(m,vector<int>(n,0));
  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;i++)
      cin>>grid[i][j];

  cout<<minPathSum(grid)<<endl;

  return 0;
}
