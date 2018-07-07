#include<iostream>
#include<vector>

using namespace std;

int main(){
  long int n,d;
  cin>>n>>d;
  long int next,cur,count = 2;
  cin>>next; cur = next + d;
  for(long int i = 1;i < n;i++){
    cin>>next;
    if(cur < next-d) count += 2;
    if(cur == next-d) count++;
    cur = next + d;
  }
  cout<<count;
  return 0;
}

/*
4 3
-3 2 9 16
5 2
4 8 11 18 19
*/
