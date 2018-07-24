#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long int li;

int lenLongestFibSubseq(vector<int>& A){
  if(A.empty()) return 0;

  int n = A.size(),answer = 0;
  map<int,int> dp;

  for(int i = 2;i < n;i++){
    int j = 0,k = i-1;
    while(j < k){
      if(A[j]+A[k] < A[i]) { j++; continue; }
      else if(A[j]+A[k] > A[i]) { k--; continue; }

      dp[k*n + i] = dp[j*n + k] + 1;
      answer = max(answer,dp[k*n+i]+2);
      j++; k--;
    }
  }
  return ((answer >= 3)?answer:0);
}

int main(){
  int temp;
  vector<int>arr;

  cin>>temp;
  while(temp != -100){ arr.push_back(temp); cin>>temp; }
  cout<<lenLongestFibSubseq(arr)<<endl;

  return 0;
}

/*
2 4 7 8 9 10 14 15 18 23 32 50 -100
2 4 7 8 9 10 14 -100
*/
