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

bool solve(int board[][20],int n,int row,bool column[],bool ld[],bool rd[]){

  if(row == n)
    {
      count++;
      display(board,n);
      return true;
    }

  for(int i=0;i<n;i++){

    if( !column[i] && !ld[row-i+n-1] && !rd[row+i]){
      board[row][i] = 1;
      column[i] = true;
      ld[row-i+n-1] = true;
      rd[row+i] = true;

      // make recursive call
      solve(board,n,row+1,column,ld,rd);

      column[i] = false;
      ld[row-i+n-1] = false;
      rd[row+i] = false;
    }

    board[row][i] = 0;
  }
  return false;
}

void solve_alternate(int board[][20],int n,int row,bool column[],bool ld[],bool rd[]){

  if(row == n)
    {
      count++;
      display(board,n);
      return;
    }

  for(int i=0;i<n;i++)
    if( !column[i] && !ld[row-i+n-1] && !rd[row+i]){
      board[row][i] = 1;
      column[i] = true;
      ld[row-i+n-1] = true;
      rd[row+i] = true;

      // make recursive call
      solve(board,n,row+1,column,ld,rd);

      board[row][i] = 0;
      column[i] = false;
      ld[row-i+n-1] = false;
      rd[row+i] = false;
    }
}

int main(){

  int n = 4;
  int board[20][20] = {0};
  bool column[20] = {false};
  bool ld[20] = {false};
  bool rd[20] = {false};

  // bool implementation
  solve(board,n,0,column,ld,rd);
  // void implementation
  solve_alternate(board,n,0,column,ld,rd);
  return 0;
}
