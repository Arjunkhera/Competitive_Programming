#include<iostream>

using namespace std;

int main(){
  int t;
  long long int n,count,p;
  cin>>t;

  while(t--){
      cin>>n;
      count=0;

      while(n){
        count++;
        p = n&(-n);
        n = n-p;
      }
      cout<<count<<"\n";
  }
  return 0;
}
