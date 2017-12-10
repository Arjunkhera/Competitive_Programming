#include<iostream>
#include<bitset>
#include<ctime>

using namespace std;

int main(){

  int arr[4] = {1,2,3,4};

  for(int& i:arr)
    cout<<i++<<' ';
  cout<<endl;
 
  for(int i:arr)
    cout<<i<<' ';
  cout<<endl;

  return 0;
}
