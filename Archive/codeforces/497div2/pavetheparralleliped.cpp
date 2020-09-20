#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>

typedef long int li;
using namespace std;

void findfactors(vector<int> &arr,int n){
  int last = sqrt(n);
  for(int i = 1;i <= last;i++)
    if(n%i == 0){ arr.push_back(i); arr.push_back(n/i); }
}

int main(){
  li t,a,b,c,cur,temp1,temp2,storecur,finalans;
  cin>>t;

  while(t--){
    finalans = 0;
    map<int,vector<pair<int,int>>> answer;
    cin>>a>>b>>c;

    vector<int> A,B,C;
    vector<pair<int,int>> emp;
    findfactors(A,a);
    findfactors(B,b);
    findfactors(C,c);

    for(int i = 0;i < A.size();i++){
      answer[A[i]] = emp;
      for(int j = 0;j < B.size();j++){
        for(int k = 0;k < C.size();k++){
          pair<int,int> temp;
          if(B[j] < C[k]) { temp.first = B[j]; temp.second = C[k]; }
          else { temp.first = C[k]; temp.second = B[j]; }
          int l = 0,n = answer[A[i]].size();
          for(; l < n;l++)
            if(answer[A[i]][l].first == temp.first && answer[A[i]][l].second == temp.second) break;
          if(l == answer[A[i]].size()) answer[A[i]].push_back(temp);
        }
      }
    }

    for(auto i:answer) { for(auto j:i.second) cout<<"{"<<j.first<<":"<<j.second<<"}"; cout<<"\n"; }

    for(auto m = answer.begin();m != answer.end();m++) finalans += m->second.size();
    cout<<finalans<<"\n";
  }
  return 0;
}

/*
4
1 1 1
1 6 1
2 2 2
100 100 100
*/
