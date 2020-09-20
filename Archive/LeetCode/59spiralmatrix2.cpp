#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> spiralOrder(int n){

  vector<int> arr;
  vector<vector<int>> matrix;

  if(n == 0)
      return matrix;

  matrix.resize(n);
  for(int i=0;i<n;i++)
      matrix[i].resize(n);

  for(int j=1;j<=(n*n);j++)
      arr.push_back(j);

  int i,j=0;
  int start_row = 0;
  int end_row = n-1;
  int start_column = 0;
  int end_column = n-1;

  while(start_row <= end_row && start_column <= end_column){

    for(i=start_column;i<=end_column;i++)
      matrix[start_row][i] = arr[j++];
    start_row++;

    for(i=start_row;i<=end_row;i++)
      matrix[i][end_column] = arr[j++];
    end_column--;

    if(start_row <= end_row){
      for(i=end_column;i>=start_column;i--)
        matrix[end_row][i] = arr[j++];
      end_row--;
    }

    if(start_column <= end_column){
      for(i=end_row;i>=start_row;i--)
        matrix[i][start_column] = arr[j++];
      start_column++;
    }
  }

  return matrix;

}

int main(){

  int n;
  cin>>n;

  vector< vector<int> > answer = spiralOrder(n);

  for(int i = 0; i < answer.size();i++){
    for(int j = 0; j < answer[i].size();j++)
      cout<<answer[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;

  return 0;
}
