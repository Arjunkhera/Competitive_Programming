#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// solution function
int countPrimes(int n){
  if(n < 2) return 0;

  int count = 0,last = sqrt(n);
  vector<bool> visited(n,false);
  for(int i = 2;i <= last;i++)
    if(!visited[i]){ count++; for(int j = i+i;j < n; j+= i) visited[j] = true; }
  for(int i = last+1;i < n;i++) if(!visited[i]) count++;
  return count;
}

// driver function
int main(){
  int n; cin>>n;

  cout<<countPrimes(n)<<endl;
  return 0;
}
