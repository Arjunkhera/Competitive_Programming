#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// solution function
vector<int> primesum(int n){
  vector<int> answer;
  if(n < 2) return answer;

  int last = sqrt(n);
  vector<bool> visited(n,false);
  for(int i = 2;i <= last;i++)
    if(!visited[i]) { for(int j = i+i;j < n; j += i) visited[j] = true; }
  for(int i = 2; i < n;i++) if(!visited[i] && !visited[n-i]) { answer.push_back(i); answer.push_back(n-i); break;}
  return answer;
}

// driver function
int main(){
  int n; cin>>n;

  vector<int> answer = primesum(n);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;
  return 0;
}
