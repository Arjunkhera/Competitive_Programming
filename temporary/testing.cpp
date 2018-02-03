#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;

void recursive(string str,ll left,ll right,ll** dp,vector<ll>& lengths){
  // length 1
  if(left == right){
    dp[left][right] = 1;
    lengths[1]++;
    return;
  }
  // length 2
  if(left+1 == right){
    if(str[left] == str[right]){
      dp[left][right] = 1;
      lengths[2]++;
    }
    else dp[left][right] = -1;
    return;
  }

  // greater lengths
  for(ll i=left;i<=right;i++){
    // not matching
    if(str[left] != str[i]){
      dp[left][i] = -1;
      continue;
    }

    // length 1
    if(left == i){
      dp[left][i] = 1;
      lengths[1]++;
      continue;
    }
    // length 2
    if(left+1 == i){
      if(str[left] == str[i]){
        dp[left][i] = 1;
        lengths[2]++;
      }
      else dp[left][i] = -1;
      continue;
    }

    // if substring not checked
    if(dp[left+1][i-1] == 0)
      recursive(str,left+1,i-1,dp,lengths);

    // check if substring satisfies palindromic property
    if(dp[left+1][i-1] == 1){
      dp[left][i] = 1;
      lengths[i-left+1]++;
      continue;
    }
    else dp[left][i] = -1;
  }

}

vector<ll> permutations(string str,vector<ll> left,vector<ll> right){

  ll len = str.length();
  ll** dp = new ll*[len];
  for(ll i=0;i<len;i++)
    dp[i] = new ll[len];
  for(ll i=0;i<len;i++)
    for(ll j=0;j<len;j++)
      dp[i][j]=0;
  vector<ll> lengths(len+1,0);

  for(ll i=0;i<len;i++)
    recursive(str,i,len-1,dp,lengths);

  long sum;
  vector<ll> results;
  for(ll i = 0;i<left.size();i++){
    sum = 0;
    for(ll j=left[i];j<=right[i];j++)
      sum += lengths[j];
    results.push_back(sum);
  }

  //return result;
  return lengths;
}

int main(){

  string str = "abaab";
  cin>>str;
  ll len = str.length();
  vector<ll> left = {1};
  vector<ll> right = {5};

  vector<ll> answer = permutations(str,left,right);
  for(auto i:answer)
    cout<<i<<" ";
  cout<<"\n";

  return 0;
}
