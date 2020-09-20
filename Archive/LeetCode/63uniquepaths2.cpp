#include<iostream>
#include<vector>

using namespace std;

int bettersolution(vector<vector<int>>& obstacleGrid){

  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
  dp[0][1] = 1;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (!obstacleGrid[i - 1][j - 1])
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

  return dp[m][n];
}

// solution function
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

  if(obstacleGrid.empty())
    return 1;
  if(obstacleGrid[0][0] == 1)
    return 0;

  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  if(obstacleGrid[m-1][n-1] == 1)
    return 0;

  vector< vector<int> > arr(m,vector<int>(n,0));
  arr[0][0] = 1;

  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;j++){
      if(i-1 >= 0 && obstacleGrid[i-1][j] != 1)
        arr[i][j] += arr[i-1][j];
      if(j-1 >= 0 && obstacleGrid[i][j-1] != 1)
        arr[i][j] += arr[i][j-1];
    }

  return arr[m-1][n-1];
}

int main(){

  int m,n;
  cin>>m>>n;

  vector<vector<int>> grid(m,vector<int>(n,0));
  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;i++)
      cin>>grid[i][j];

  cout<<uniquePathsWithObstacles(grid)<<endl;

  return 0;
}
