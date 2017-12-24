#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

/*
// recursive
int solve(int **arr,int *boys,int *girls,int n,int m){
  if(n==0)
    return 0;

  int temp,value = INT_MAX;
  for(int i=m;i>=n;i--){
    arr[n][i] = abs(boys[n] - girls[i]) + solve(arr,boys,girls,n-1,i-1);
    value = min(value,arr[n][i]);
  }
  return value;
}
*/

// dp
int solve(int **arr,vector<int> &boys,vector<int> &girls,int n,int m){

  int temp;
  for(int i=1;i<=n;i++){
    for(int j=i;j<=m;j++){
      temp = abs(boys[i]-girls[j])+arr[i-1][j-1];
      if(j==i)
        arr[i][j] = temp;
      else arr[i][j] = min(temp,arr[i][j-1]);
    }
  }

  return arr[n][m];
}

int main(){
  int n,m;
  cin>>n>>m;

  vector<int> boys(n+1,0);
  vector<int> girls(m+1,0);

  int **arr = new int*[n+1];
  for(int i=0;i<=n;i++)
    arr[i] = new int[m+1];

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      arr[i][j] = 0;

  for(int i=1;i<=n;i++)
    cin>>boys[i];
  for(int i=1;i<=m;i++)
    cin>>girls[i];

  sort(boys.begin(),boys.end());
  sort(girls.begin(),girls.end());

  cout<<solve(arr,boys,girls,n,m)<<"\n";

  /*
  // display
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++)
      cout<<arr[i][j]<<" ";
  cout<<endl;
  }
  */
  
  return 0;
}
