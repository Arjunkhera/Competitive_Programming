#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<string> &board,int n,int row,int col){
  int i,j = row-1;
  while(j >= 0) { if(board[j][col] == 'Q') return false; j--;}
  i = row-1;j = col-1;
  while(i >= 0 && j >= 0){ if(board[i][j] == 'Q') return false; i--; j--; }
  i = row-1;j = col+1;
  while(i >= 0 && j < n){ if(board[i][j] == 'Q') return false; i--; j++; }
  return true;
}

void solvenormal(vector<string> &board,int n,vector<vector<string>> &answer,int row){
  if(row == n){ answer.push_back(board); return; }

  for(int i = 0;i < n;i++){
    board[row][i] = 'Q';
    if(isSafe(board,n,row,i)) solvenormal(board,n,answer,row+1);
    // backtrack
    board[row][i] = '.';
  }
}

void solveoptimized(vector<string> &board,int n,vector<vector<string>> &answer,int row,vector<bool> &col,vector<bool> &ld,vector<bool> &rd){
  if(row == n){ answer.push_back(board); return; }

  for(int i = 0;i < n;i++){
    board[row][i] = 'Q';
    if(!col[i] && !ld[row-i+n-1] && !rd[row+i]){
      col[i] = true; ld[row-i+n-1] = true; rd[row+i] = true;
      solveoptimized(board,n,answer,row+1,col,ld,rd);
      col[i] = false; ld[row-i+n-1] = false; rd[row+i] = false;
    }
    // backtrack
    board[row][i] = '.';
  }
}

vector<vector<string>> solveNQueens(int n){
  vector<vector<string>> answer;
  if(n == 0) return answer;

  vector<string> board(n);
  for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) board[i].push_back('.');

  // solvenormal(board,n,answer,0);
  vector<bool> col(n,false); vector<bool> ld(2*n+1,false); vector<bool> rd(2*n+1,false);
  solveoptimized(board,n,answer,0,col,ld,rd);

  return answer;
}

int main(){
  int n;
  cin>>n;

  vector<vector<string>> answer = solveNQueens(n);
  for(auto i:answer) { for(auto j:i) cout<<j<<endl; cout<<endl<<endl; }

  return 0;
}
