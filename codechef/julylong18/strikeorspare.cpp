#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main(){
  unsigned long long int t,n,p;
  cin>>t;
  while(t--){
    cin>>n;
    if(n == 1) { cout<<1<<" "<<1<<endl; continue; }
    p = 1; string q(n/2,'0');
    cout<<p<<" 1"<<q<<"\n";
  }
  return 0;
}
