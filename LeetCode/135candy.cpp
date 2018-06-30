#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int findsum(int n){
  return (n*(n+1))/2;
}

// solution functions
int candy(vector<int>& ratings){
  if(ratings.empty()) return 0; if(ratings.size() == 1) return 1;

  int inc = 0,dec = 0,answer = 0,prev = 0,cur = 0,n = ratings.size();
  for(int i = 1;i < n; i++){
    if(ratings[i] > ratings[i-1]) cur = 1; else if(ratings[i] < ratings[i-1]) cur = -1; else cur = 0;
    if((prev > 0 && cur == 0) || (prev < 0 && cur >= 0)){ answer += findsum(inc) + findsum(dec) + max(inc,dec); inc = 0;dec = 0; }
    if(cur > 0) inc++; if(cur < 0) dec++; if(cur == 0) answer++;
    prev = cur;
  }
  answer += findsum(inc) + findsum(dec) + max(inc,dec) + 1;
  return answer;
}

int main(){
  int n,temp;
  cin>>n;
  vector<int> arr(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];

  cout<<candy(arr)<<endl;

  return 0;
}
