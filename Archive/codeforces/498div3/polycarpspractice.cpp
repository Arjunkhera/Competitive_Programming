#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> solution;

void solve(vector<int> &arr,int n,int k,int curpos,vector<int> solved,vector<vector<int>> &dp,int maybe,int &maxans){
  int N = arr.size();
  // base case
  if(curpos >= N || n < k || k == 0) return;

  // already solved
  // if(dp[n][k] != -1) return;

  // single day
  if(k == 1){
    int temp = 0;
    for(int i = curpos;i < N;i++) temp = max(temp,arr[i]);
    maybe += temp;
    // cout<<n<<" : "<<k<<" : "<<maxans<<" \n ";
    // for(auto i:solved) cout<<i<<" ";
    // cout<<"---\n";

    if(maybe > maxans){ solved.push_back(n); solution = solved; maxans = maybe;}
    // dp[n][k] = temp;
  }

  int temp,finalcount = 0,finalanswer = 0,count = 0,curscore = 0,assign = n-k+1;
  for(int i = 0;i < assign;i++){
    curscore = max(curscore,arr[i+curpos]);
    count++;
    solved.push_back(count);
    solve(arr,n-i-1,k-1,curpos+i+1,solved,dp,maybe+curscore,maxans);
    solved.pop_back();
  }
  // dp[n][k] = finalanswer;
}

int main(){
  int n,k; cin>>n>>k;
  vector<int> arr(n);

  for(int i = 0;i < n;i++) cin>>arr[i];

  vector<int> solved;
  vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
  int score = 0;
  solve(arr,arr.size(),k,0,solved,dp,0,score);

  cout<<score<<"\n";
  // reverse(solution.begin(),solution.end());
  for(auto i:solution) cout<<i<<" ";
  cout<<"\n";

  return 0;
}

/*
4 3
5 4 2 6
-------------
8 3
5 4 2 6 5 1 9 2
*/
