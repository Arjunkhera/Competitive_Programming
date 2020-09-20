#include<iostream>
#include<string>

using namespace std;

int solve(int **arr,int *a,int *b,int x,int y,int k){

  if(k==0)
    return 0;

  if(x==0 || y==0)
    return 0;

  if(a[x-1] == b[y-1])
      return solve(arr,a,b,x-1,y-1,k);

  int temp = arr[x-1][y-1]+1;
  if(temp != arr[x-1][y] && temp != arr[x][y-1])
    return 1+solve(arr,a,b,x-1,y-1,k-1);

  int left=-1,up=-1;
  if(temp == arr[x][y-1])
    left = solve(arr,a,b,x,y-1,k);
  if(temp == arr[x-1][y])
    up = solve(arr,a,b,x-1,y,k);

  return max(left,up);
}

int main(){

  int len_1,len_2,k;
  cin>>len_1>>len_2>>k;

  int *a = new int[len_1];
  int *b = new int[len_2];
  // input
  for(int i=0;i<len_1;i++)
    cin>>a[i];
  for(int i=0;i<len_2;i++)
    cin>>b[i];

  int **arr = new int*[len_1+1];
  for(int i=0;i<=len_1;i++)
    arr[i] = new int[len_2+1];

  for(int i=0;i<=len_1;i++)
    for(int j=0;j<=len_2;j++)
      arr[i][j]=0;

  // lcs
  for(int i=1;i<=len_1;i++)
    for(int j=1;j<=len_2;j++)
      if(a[i-1] == b[j-1])
        arr[i][j] = arr[i-1][j-1] + 1;
      else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);

  /*
  for(int i=0;i<=len_1;i++){
    for(int j=0;j<=len_2;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<arr[len_1][len_2]<<endl;
  */

  cout<<arr[len_1][len_2]+solve(arr,a,b,len_1,len_2,k)<<endl;
  return 0;
}
