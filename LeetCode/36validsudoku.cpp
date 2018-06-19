#include<iostream>
#include<vector>

using namespace std;

bool checkValid(vector<vector<char>>& board,int row,int col){
  char key = board[row][col],i,j;
  if(key == '.') return true;
  if(key < '1' || key > '9') return false;
  board[row][col] = '0';
  for(i = 0; i < 9;i++) if(key == board[i][col]) return false;
  for(i = 0; i < 9;i++) if(key == board[row][i]) return false;
  int cr = row/3,cl = col/3;
  for(i = 0;i < 3;i++) for(j = 0;j < 3;j++) if(key == board[i+3*cr][j+3*cl]) return false;
  board[row][col] = key;
  return true;
}

bool isValidSudoku(vector<vector<char>>& board){
  for(int i = 0;i < 9;i++)
    for(int j = 0;j < 9;j++)
      if(!checkValid(board,i,j)) return false;
  return true;
}

int main(){

  vector<vector<char>> board(9,vector<char>(9));
  for(int i = 0;i < 9;i++) for(int j = 0;j < 9;j++) cin>>board[i][j];

  if(isValidSudoku(board)) cout<<"yes\n"; else cout<<"No\n";
  return 0;
}
