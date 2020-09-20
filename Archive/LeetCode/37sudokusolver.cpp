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

bool solve(vector<vector<char>>& board,int row,int col){
  // base case : solved
  if(row == 8 && col == 9) return true;
  // to keep indexes in range
  if(col == 9) {row++; col = 0;}
  // if already filled, ignore
  if(board[row][col] != '.') return solve(board,row,col+1);
  // test all values
  for(int i = 1;i < 10;i++){
    board[row][col] = 48+i;
    if(checkValid(board,row,col) && solve(board,row,col+1)) return true;
  }
  board[row][col] = '.';
  return false;
}

// solution function
void solveSudoku(vector<vector<char>>& board){
  solve(board,0,0);
}

int main(){

  /*
  vector<vector<char>> board(9,vector<char>(9));
  for(int i = 0;i < 9;i++) for(int j = 0;j < 9;j++) cin>>board[i][j];
  */
  vector<vector<char>> board(9,vector<char>(9));
  for(int i = 0;i < 9;i++) for(int j = 0;j < 9;j++) cin>>board[i][j];

  solveSudoku(board);
  for(auto i:board){ for(auto j:i) cout<<j<<" "; cout<<endl; }

  return 0;
}
