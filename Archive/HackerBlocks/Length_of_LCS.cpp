#include<iostream>
#include<string>

using namespace std;

int main(){

  string a,b;
  cin>>a>>b;

  int len_1 = a.length();
  int len_2 = b.length();
  int arr[len_1+1][len_2+1] = {0};

  /*
  for(int i=0;i<=len_1;i++){
    for(int j=0;j<=len_2;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  for(int i=0;i<=len_1;i++)
    for(int j=0;j<=len_2;j++)
      arr[i][j]=0;

  for(int i=1;i<=len_1;i++)
    for(int j=1;j<=len_2;j++)
      if(a[i-1] == b[j-1])
        arr[i][j] = arr[i-1][j-1] + 1;
      else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);

  /*
  for(int i=1;i<=len_1;i++){
    for(int j=1;j<=len_2;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  cout<<arr[len_1][len_2]<<endl;
  return 0;
}
