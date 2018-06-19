#include<iostream>
#include<vector>

using namespace std;

bool checkValid(const vector<string> &board,int row,int col){
  char key = board[row][col],i,j;
  if(key == '.') return true;
  if(key < '1' || key > '9') return false;
  for(i = 0; i < 9;i++){ if(i == row) continue; if(key == board[i][col]) return false; }
  for(i = 0; i < 9;i++){ if(i == col) continue; if(key == board[row][i]) return false; }
  int cr = row/3,cl = col/3,tr,tc;
  for(i = 0;i < 3;i++){
    tr = i+3*cr;
    if(tr == row) continue;
    for(j = 0;j < 3;j++){
        tc = j+3*cl;
        if(tc == col) continue;
        if(key == board[tr][tc]) return false;
    }
  }
  return true;
}

int isValidSudoku(const vector<string> &board){
   for(int i = 0;i < 9;i++)
     for(int j = 0;j < 9;j++)
       if(!checkValid(board,i,j)) return 0;
    return 1;
}

int main(){
  vector<string> board(9);
  for(int i = 0;i < 9;i++) cin>>board[i];

  if(isValidSudoku(board)) cout<<"yes\n"; else cout<<"No\n";
  return 0;
}
