#include<iostream>

using namespace std;

void spiralprint(int **arr,int startrow,int startcol,int endrow,int endcol){
  int i;
  while(startrow<=endrow && startcol<=endcol){
      for(i=startcol;i<=endcol;i++)
        cout<<arr[startrow][i]<<", ";
      startrow++;

      for(i=startrow;i<=endrow;i++)
        cout<<arr[i][endcol]<<", ";
      endcol--;

      if(startrow <= endrow){
        for(i=endcol;i>=startcol;i--)
          cout<<arr[endrow][i]<<", ";
        endrow--;
      }

      if(startcol <= endcol){
        for(i=endrow;i>=startrow;i--)
          cout<<arr[i][startcol]<<", ";
        startcol++;
      }
  }
}

int main(){
  int row,col;
  cin>>row>>col;

  int **arr = new int*[row];
  for(int i=0;i<col;i++)
    arr[i] = new int[col];

  //input
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin>>arr[i][j];

  //cout<<endl;
  spiralprint(arr,0,0,row-1,col-1);
  cout<<"END\n";
  return 0;
}
