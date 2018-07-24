#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>

typedef long int li;
using namespace std;

int binaryGap(int N){
  int oldpos = -1,pos = 1,maxdiff = 0;
  while(N){
    if(N & 1){
      if(oldpos != -1) maxdiff = max(maxdiff,pos - oldpos);
      oldpos = pos;
    }
    pos++;
    N >>= 1;
  }
  return maxdiff;
}

int main(){
  int N; cin>>N;
  cout<<binaryGap(N)<<endl;
  return 0;
}

/*
4
1 1 1
1 6 1
2 2 2
100 100 100
*/
