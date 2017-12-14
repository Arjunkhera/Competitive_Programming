#include<iostream>

using namespace std;

void spiralprint(int **board,int rows,int columns){

  int i;
  int start_row = 0;
  int end_row = rows-1;
  int start_column = 0;
  int end_column = columns-1;

  while(start_row <= end_row && start_column <= end_column){

    for(i=start_column;i<=end_column;i++)
      cout<<board[start_row][i]<<" ";
    start_row++;

    for(i=start_row;i<=end_row;i++)
      cout<<board[i][end_column]<<" ";
    end_column--;

    if(end_row > start_row){
      for(i=end_column;i>=start_column;i--)
        cout<<board[end_row][i]<<" ";
      end_row--;
    }

    if(end_column > start_column){
      for(i=end_row;i>=start_row;i--)
        cout<<board[i][start_column]<<" ";
      start_column++;
    }
  }
}

int main(){

  int rows,columns;
  cin>>rows>>columns;

  int **board = new int*[rows];
  for(int i=0;i<columns;i++)
    board[i] = new int[columns];

  //input
  for(int i=0;i<rows;i++)
    for(int j=0;j<columns;j++)
      cin>>board[i][j];

  spiralprint(board,rows,columns);
  return 0;
}
