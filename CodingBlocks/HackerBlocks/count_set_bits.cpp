#include<iostream>

using namespace std;

int main(){
  int t,n,count;
  cin>>t;

  while(t--){
      cin>>n;
      count=0;

      while(n){
        count++;
        int p = n&(-n);
        n = n-p;
      }
      cout<<count<<"\n";
  }
  return 0;
}
