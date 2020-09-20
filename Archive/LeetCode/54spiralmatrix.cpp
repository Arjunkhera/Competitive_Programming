#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& board){

  vector<int> answer;
  if(board.size() == 0)
      return answer;

  if(board.size() == 1)
     return board[0];

  int i;
  int start_row = 0;
  int end_row = board.size()-1;
  int start_column = 0;
  int end_column = board[0].size()-1;

  while(start_row <= end_row && start_column <= end_column){

    for(i=start_column;i<=end_column;i++)
      answer.push_back(board[start_row][i]);
    start_row++;

    for(i=start_row;i<=end_row;i++)
      answer.push_back(board[i][end_column]);
    end_column--;

    if(start_row <= end_row){
      for(i=end_column;i>=start_column;i--)
        answer.push_back(board[end_row][i]);
      end_row--;
    }

    if(start_column <= end_column){
      for(i=end_row;i>=start_row;i--)
        answer.push_back(board[i][start_column]);
      start_column++;
    }
  }

  return answer;
}

int main(){

  int m,n;
  cin>>m>>n;
  vector< vector<int> >arr(m,vector<int>(n,0));

  for(int i = 0;i<m;i++)
    for(int j = 0;j<n;j++)
      cin>>arr[i][j];

  vector<int> answer = spiralOrder(arr);
  cout<<endl;

  for(auto i:answer)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
