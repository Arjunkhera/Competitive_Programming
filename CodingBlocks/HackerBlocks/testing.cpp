#include<iostream>
#include<string>

using namespace std;

int main(){
  int arr[10][10] = {0};

  int len_1=3;
  int len_2=3;

  for(int i=0;i<len_1;i++){
    for(int j=0;j<len_2;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
/*
11
1 3 5 8 9 2 6 7 6 8 9
*/
