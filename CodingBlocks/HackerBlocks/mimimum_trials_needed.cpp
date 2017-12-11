#include<iostream>
#include<climits>

using namespace std;

int arr[15][5]={-1};

int calculate(int k,int n){

  if(k == 1){
    arr[n][k] = n;
    return n;
  }

  if(n==0 || n==1){
    arr[n][k] = n;
    return n;
  }

  int answer = INT_MAX,temp;
  for(int i=1;i<=n;i++){
      if(arr[i-1][k-1] == -1)
        arr[i-1][k-1] = calculate(k-1,i-1);

      if(arr[i-1][k-1] == -1)
        arr[n-i][k] = calculate(k,n-i);

      temp = max(arr[i-1][k-1],arr[n-i][k]);
      if(answer > temp)
        answer = temp;
  }
  return answer;
}

int main(){

  int t,n,k;
  cin>>t;

  while(t--){
    cin>>k>>n;
    cout<<calculate(k,n);
  }

  return 0;
}
