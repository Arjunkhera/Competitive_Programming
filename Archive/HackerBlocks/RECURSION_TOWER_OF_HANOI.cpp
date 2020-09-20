#include<iostream>
#include<string>
#include<vector>

using namespace std;

int count = 0;
vector<string> str{"T1","T2","T3"};

void solve(int n,int src,int dest,int vac){

  if(n==1){
    count++;
    cout<<"Move "<<n<<"th disc from "<<str[src]<<" to "<<str[dest]<<"\n";
    return;
  }

  solve(n-1,src,vac,dest);

  count++;
  cout<<"Move "<<n<<"th disc from "<<str[src]<<" to "<<str[dest]<<"\n";

  solve(n-1,vac,dest,src);
}

int main(){

  int n;
  cin>>n;
  solve(n,0,1,2);
  cout<<count<<endl;
}
