#include<iostream>
#include<cmath>

using namespace std;

int n;

bool issafe(int **board,int i,int j,int num){

  for(int k=0;k<n;k++)
    if(board[i][k] == num || board[k][j] == num)
      return false;

  int cellx,celly;
  if(n==6){

    cellx = (i/2)*2;
    celly = (j/3)*3;

    for(int l=cellx;l<cellx+2;l++)
      for(int m=celly;m<celly+3;m++)
        if(board[l][m] == num){
          return false;
        }

    return true;
  }

  int root = sqrt(n);
  cellx = (i/(root))*root;
  celly = (j/(root))*root;

  for(int l=cellx;l<cellx+root;l++)
    for(int m=celly;m<celly+root;m++)
      if(board[l][m] == num)
        return false;

  return true;
}

bool solve(int **board,int i,int j){

  if(i == n)
    return true;

  if(j == n){
    return solve(board,i+1,0);
  }

  if(board[i][j] != 0)
    return solve(board,i,j+1);

  for(int k=1;k<n+1;k++)
    if(issafe(board,i,j,k)){
      board[i][j] = k;
      if(solve(board,i,j+1))
        return true;
      //backtrack
      board[i][j] = 0;
    }

  return false;
}

int main(){

  cin>>n;
  int **board;
  board = new int*[n];
  for(int i=0;i<n;i++)
    board[i] = new int[n];

  // input
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>board[i][j];

  if(solve(board,0,0))
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        cout<<board[i][j]<<" ";
      cout<<"\n";
    }
  return 0;
}
