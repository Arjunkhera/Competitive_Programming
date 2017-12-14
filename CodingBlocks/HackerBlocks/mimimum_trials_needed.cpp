#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int solve_DP(int eggs,int floors){

  int arr[eggs+1][floors+1];
  int temp;

  for(int i=0;i<=eggs;i++){
    arr[i][0] = 0;
    arr[i][1] = 1;
  }

  for(int i=0;i<=floors;i++){
    arr[0][i] = 0;
    arr[1][i] = i;
  }

  for(int i=2;i<=eggs;i++)
    for(int j=2;j<=floors;j++){
      arr[i][j]=INT_MAX;
      for(int k=1;k<=j;k++){
        temp = 1+max(arr[i-1][k-1],arr[i][j-k]);

        if(temp < arr[i][j])
          arr[i][j] = temp;
      }
    }
  return arr[eggs][floors];
}

int solve(int eggs,int floors){

  if(floors==0 || floors==1)
    return floors;

  if(eggs == 1)
    return floors;

  int fl,temp,minimum = INT_MAX;
  for(int i=1;i<=floors;i++){
    temp =  max(solve(eggs-1,i-1),solve(eggs,floors-i));
    if(temp < minimum){
      minimum = temp;
      fl = i;
    }
  }
  return minimum+1;
}

int main(){
  int t,n,k;
  cin>>t;

  while(t--){
    // eggs,floors
    cin>>k>>n;
    //cout<<solve(k,n)<<endl;
    cout<<solve_DP(k,n)<<endl;
  }
  return 0;
}
