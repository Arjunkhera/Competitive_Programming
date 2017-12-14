#include<iostream>

using namespace std;

int count = 0;

void display(int board[][20],int n){
  cout<<"Solution number : "<<count<<endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<board[i][j]<<" ";
    cout<<endl;
  }
  cout<<"------------\n";
}

bool issafe(int board[][20],int row,int col,int n){

  for(int i=0;i<row;i++)
    if(board[i][col] == 1)
      return false;

  int r = row;
  int c = col;
  while(r>=0 && c>=0){
    if(board[r][c]==1)
      return false;
    r--;
    c--;
  }

  r = row;
  c = col;
  while(r>=0 && c<n){
    if(board[r][c]==1)
      return false;
    r--;
    c++;
  }

  return true;
}

bool solve(int board[][20],int n,int row){

    if(row == n)
      {
        count++;
        display(board,n);
        return true;
      }

    for(int i=0;i<n;i++){

      if(issafe(board,row,i,n)){
          board[row][i] = 1;
          solve(board,n,row+1);

          /*
          use this to find one solution
          if(solve(board,n,row+1))
            return true;
          */
      }
      board[row][i] = 0;
    }
    return false;
}

int main(){

  int n = 4;
  int board[20][20] = {0};

  solve(board,n,0);
  return 0;
}
