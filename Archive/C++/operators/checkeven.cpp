#include<iostream>
#include<vector>

using namespace std;

bool isEven(int n){
  return !(n&1);
}

int main(){

  int n; cin>>n;
  if(isEven(n)) cout<<"Even\n"; else cout<<"Odd\n";

  return 0;
}
