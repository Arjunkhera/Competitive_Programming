#include<bits/stdc++.h>

using namespace std;
#define maxx 1000000000
typedef long long int lli;
typedef long int li;

// solution function
int minEatingSpeed(vector<int>& piles, int H){
  if(piles.empty()) return 0;

  li curtime,mid,n = piles.size(),start = 1,end = maxx;
  if(n > H) return 0;

  while(start < end){
    mid = start + (end - start)/2;
    curtime = 0;

    // calculate the time taken at current value of K
    for(auto i:piles) curtime += (i-1)/mid + 1;

    // if satisified, then look for even smaller K on lhs, else go to right for valid solution
    if(curtime <= H) end = mid; else start = mid + 1;
  }
  return start;
}

int main(){

  vector<int> arr;

  int temp; cin>> temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  cin>>temp;
  cout<<minEatingSpeed(arr,temp)<<endl;

  return 0;
}

// (i-1) is to ensure that divisible cases are not incremented, so 9/3 = 3 and not 4
