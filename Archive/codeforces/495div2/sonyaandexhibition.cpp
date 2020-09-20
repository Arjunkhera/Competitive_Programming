#include<iostream>
#include<vector>

using namespace std;

int main(){
  long int n,m,a,b;
  cin>>n>>m;
  for(long int i = 0;i < m;i++) cin>>a>>b;

  string str(n,'0');
  for(long int i = 0;i < n;i += 2) str[i] = '1';
  cout<<str;
  return 0;
}

/*
5 3
1 3
2 4
2 5
-----------
6 3
5 6
1 4
4 6
*/
