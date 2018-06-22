#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>

using namespace std;

void solve(int bitpos,int n,bool flag,int num,vector<int> answer){
  if(bitpos == n) { answer.push_back(num); return; }

  int temp = 1<<bitpos;
  if(flag) solve(bitpos+1,n,!flag,num,answer);
  else solve(bitpos+1,n,!flag,num+temp,answer);
}

void iterative(int n,vector<int> &answer){
  answer.push_back(0); answer.push_back(1);
  int add,j,i = 1;
  while(i < n){
    j = answer.size()-1;
    add = 1<<i; i++;
    while(j >= 0){ answer.push_back(answer[j]+add); j--; }
  }
}

// solution function
vector<int> grayCode(int n) {
  vector<int> answer;
  if(n == 0) return answer;

  // solve(1,n,false,0,answer);
  // solve(1,n,true,1,answer);
  iterative(n,answer);
  return answer;
}

int main(){
  int n;
  cin>>n;

  vector<int> answer = grayCode(n);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;

  return 0;
}
