#include<iostream>
#include<cmath>

using namespace std;

int main(){
  long long int t,n,m,answer,temp;
  cin>>t;
  while(t--){
    cin>>n>>m;
    answer = 1;
    for(long long int i = 0;i < n;i++){ cin>>temp; if(temp%m == 0) answer *= 2; }
    cout<<(answer-1)<<"\n";
  }
  return 0;
}
