#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

bool mycompare(vector<int> a,vector<int> b){
  for(int i = 0;i < a.size();i++) if(a[i] > b[i]) return false;
  return true;
}

vector<vector<int>> traceanswer(vector<vector<vector<bool>>> &dp,vector<int> &arr,int maink,vector<pair<int,int>> &possible){

  vector<vector<int>> leftsub(possible.size());
  for(int ll = 0;ll < possible.size();ll++){
    int i = possible[ll].first,j = possible[ll].second,k = maink;
    while(j > 0 && i > 0 && k > 0)
      if(!dp[k][i-1][j]){
        leftsub[ll].push_back(arr[i-1]);
        k -= 1; j -= arr[i-1]; i -= 1;
      }
      else i -= 1;
    sort(leftsub[ll].begin(),leftsub[ll].end());
    for(auto kk:leftsub[ll]) cout<<kk<<" "; cout<<endl;
  }
  sort(leftsub.begin(),leftsub.end(),mycompare);
  // sort(arr.begin(),arr.end());

  vector<vector<int>> answer(2);
  vector<bool> visited(arr.size(),false);
  for(int m = 0,n = 0;m < arr.size() && n < leftsub[0].size();m++)
    if(arr[m] == leftsub[0][n]){ answer[0].push_back(arr[m]); n++; visited[m] = true; }
  for(int m = 0;m < arr.size();m++) if(!visited[m]) answer[1].push_back(arr[m]);

  sort(answer[1].begin(),answer[1].end());
  if(answer[0].size() == answer[1].size() && answer[0][0] > answer[1][0]) reverse(answer.begin(),answer.end());
  return answer;
}

vector<vector<int>> equalaverage(vector<int> &arr){

  vector<vector<int>> answer;
  if(arr.empty() || arr.size() == 1) return answer;

  sort(arr.begin(),arr.end());
  for(auto kk:arr) cout<<kk<<" "; cout<<endl;

  long int sum = 0,n = arr.size();
  for(int i = 0;i < n;i++) sum += arr[i];
  double ratio = sum/double(n);

  vector<vector<vector<bool>>> dp(n/2+1,vector<vector<bool>>(n+1,vector<bool>(sum+1,false)));
  for(int k = 0;k <= n/2;k++) for(int i = 0;i <= n;i++) dp[k][i][0] = true;

  for(int k = 1;k <= n/2;k++){
    vector<pair<int,int>> possible;
    for(int i = 1;i <= n;i++){
      for(int j = 1;j < sum;j++){
        if(j-arr[i-1] >= 0 && dp[k-1][i-1][j-arr[i-1]]) dp[k][i][j] = true;
        else dp[k][i][j] = dp[k][i-1][j];
        if(dp[k][i][j] && abs((j/double(k))-ratio) < 0.001) possible.push_back(make_pair(i,j));
      }
    }
    if(!possible.empty()) return traceanswer(dp,arr,k,possible);
  }
  return answer;
}

int main(){
  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  vector<vector<int>> answer = equalaverage(arr);

  cout<<endl;
  for(auto i:answer) { for(auto j:i) cout<<j<<" "; cout<<endl;}
  return 0;
}

/*
47 14 30 19 30 4 32 32 15 2 6 24 -1
answer
[2 4 32 47 ] [6 14 15 19 24 30 30 32 ]
*/
