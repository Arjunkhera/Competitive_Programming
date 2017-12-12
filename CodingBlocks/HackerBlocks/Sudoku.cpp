#include<iostream>

using namespace std;

int n;

bool issafe(){

}

bool calculate(int **board,int i,int j){


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

  calculate(board,0,0);

  return 0;
}
