#include<iostream>

using namespace std;

int main(){
  string a,b;
  cin>>a>>b;

  int temp;
  int len_1 = a.length();
  int len_2 = b.length();

  int **arr = new int*[len_1+1];
  for(int i=0;i<=len_1;i++)
    arr[i] = new int[len_2+1];

  for(int i=0;i<=len_1;i++)
    arr[i][0]=i;
  for(int i=0;i<=len_2;i++)
    arr[0][i]=i;

  for(int i=1;i<=len_1;i++)
    for(int j=1;j<=len_2;j++){
      temp = min(min(arr[i][j-1],arr[i-1][j]),arr[i-1][j-1]);
      if(a[i-1]==b[j-1])
        arr[i][j] = arr[i-1][j-1];
      else arr[i][j] = temp+1;
    }

  cout<<arr[len_1][len_2]<<endl;
  return 0;
}
