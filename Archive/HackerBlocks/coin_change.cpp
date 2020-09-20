#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

  int value,n,temp;
  int arr[300][300]={0};
  cin>>value>>n;

  vector<int>coins;
  for(int i=0;i<n;i++){
    cin>>temp;
    coins.push_back(temp);
    arr[i+1][0]=1;
  }

  sort(coins.begin(),coins.end());

  for(int i=1;i<=n;i++)
    for(int j=1;j<=value;j++)
      if(coins[i-1]>j)
        arr[i][j]=arr[i-1][j];
      else arr[i][j]=arr[i-1][j]+arr[i][j-coins[i-1]];

  /*
  cout<<"\n-----------\n";
  for(int i=0;i<=n;i++){
    for(int j=0;j<=value;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  */

  cout<<arr[n][value]<<endl;
  return 0;
}
