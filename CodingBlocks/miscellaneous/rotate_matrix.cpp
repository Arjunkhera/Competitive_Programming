#include<iostream>

using namespace std;

void display(int **board,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<board[i][j]<<" ";
    cout<<"\n";
  }
}

void Rotate(int **board,int n){
  // reverse the columns
  int start,end,temp;
  for(int i=0;i<n;i++){
    start=0;
    end=n-1;

    while(start<end){
      temp = board[start][i];
      board[start][i] = board[end][i];
      board[end][i] = temp;
      start++;
      end--;
    }
  }

  // transpose the matrix
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i<j){
        temp = board[i][j];
        board[i][j] = board[j][i];
        board[j][i] = temp;
      }
}

int main(){
  int n;
  cin>>n;

  int **board = new int*[n];
  for(int i=0;i<n;i++)
    board[i] = new int[n];

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>board[i][j];

  cout<<"----------\n";  
  Rotate(board,n);
  display(board,n);

  return 0;
}
