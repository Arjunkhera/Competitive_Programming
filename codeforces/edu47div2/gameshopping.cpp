#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>

typedef long int li;
using namespace std;

int main(){
  int n,m,answer = 0;
  cin>>n>>m;

  vector<int> costs(n),bills(m);
  for(int i = 0;i < n;i++) cin>>costs[i];
  for(int i = 0;i < m;i++) cin>>bills[i];

  int j = 0;
  for(int i = 0;i < n && j < m;i++){
    if(costs[i] > bills[j]) continue;
    j++; answer++;
  }
  cout<<answer;
  return 0;
}

/*
4
1 1 1
1 6 1
2 2 2
100 100 100
*/
