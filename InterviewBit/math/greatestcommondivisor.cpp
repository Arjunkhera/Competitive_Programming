#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// solution function
int gcd(int a,int b){

    int temp;
    while(a){
      temp = b%a;
      b = a; a = temp;
    }
    return b;
}

// driver function
int main(){
  int a,b; cin>>a>>b;
  cout<<gcd(a,b)<<endl;

  return 0;
}
