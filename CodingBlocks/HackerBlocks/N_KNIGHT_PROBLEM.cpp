#include<iostream>

using namespace std;

int board[15][15] = {0};
bool ld[15] = {false};
bool rd[15] = {false};

void display(){

  
}

void solve(int n,int row){

  if( row == n ){
    display();
    return;
  }

  for(int i=0;i<n;i++)
    if( !ld[row-i+n-1] && !rd[row+i] ){
        board[row][i] = 1;
        ld[row-i+n-1] = 1;
        rd[row+i] = 1;

        solve(n,row+1);

        board[row][i] = 0;
        ld[row-i+n-1] = 0;
        rd[row+i] = 0;
    }
}

int main(){

  int n;
  cin>>n;

  solve(n,0);
  return 0;
}
