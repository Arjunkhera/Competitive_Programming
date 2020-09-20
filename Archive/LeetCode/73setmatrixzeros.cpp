#include<iostream>
#include<vector>
#include<set>

using namespace std;

void setZeroes_notbest(vector<vector<int>>& matrix) {

  if(matrix.empty())
    return;

  int m = matrix.size();
  int n = matrix[0].size();
  set<int> rows;
  set<int> columns;

  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;j++)
      if(matrix[i][j] == 0){
        rows.insert(i);
        columns.insert(j);
      }

  int temp;
  for(auto i:rows){
    temp = i;
    for(int j = 0;j < n;j++)
      matrix[temp][j] = 0;
  }

  for(auto i:columns){
    temp = i;
    for(int j = 0;j < m;j++)
      matrix[j][temp] = 0;
  }

}

// O(1) space solution
void setZeroes(vector<vector<int>>& matrix) {

  if(matrix.empty())
    return;

  int m = matrix.size();
  int n = matrix[0].size();
  bool flag = false;

  for(int i = 0;i < m;i++){
    if(matrix[i][0] == 0)
      flag = true;

    for(int j = 1;j < n;j++)
      if(matrix[i][j] == 0){
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
  }

  for(int i = m-1;i >= 0;i--){
    for(int j = n-1;j > 0;j--)
      if(!matrix[i][0] || !matrix[0][j])
        matrix[i][j] = 0;
    if(flag)
      matrix[i][0] = 0;
  }

}

int main(){

  int m,n;
  cin>>m>>n;

  vector< vector<int> > matrix(m,vector<int>(n,0));

  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>matrix[i][j];

  setZeroes(matrix);
  cout<<endl;

  for(auto i:matrix){
    for(auto j:i)
      cout<<j<<" ";
    cout<<endl;
  }

  return 0;
}
