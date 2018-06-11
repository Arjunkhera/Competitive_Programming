#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector< vector<int> > traceanswer(vector<vector<vector<bool>>> &dp,int k,int i,int j,vector<int> &arr){

  vector< vector<int> > answer(2);
  vector<bool> visited(arr.size(),false);

  while(j >= 0 && i >= 0 && k >= 0){
    //cout<<k<<"--"<<i<<"--"<<j<<endl;
    if(!dp[k][i-1][j]){
      answer[0].push_back(arr[i-1]);
      visited[i-1] = true;
      k -= 1;
      j -= arr[i-1];
      i -= 1;
    }
    else {
      i -= 1;
    }
  }

  for(int m = 0;m < arr.size();m++)
    if(!visited[m])
      answer[1].push_back(arr[m]);

  if(answer[0].size() > answer[1].size())
    reverse(answer.begin(),answer.end());

  sort(answer[0].begin(),answer[0].end());
  sort(answer[1].begin(),answer[1].end());

  return answer;
}

vector<vector<int>> equalaverage(vector<int> &arr){

  vector<vector<int>> answer;
  if(arr.empty() || arr.size() == 1)
    return answer;

  long int sum = 0;
  long int n = arr.size();
  for(int i = 0;i < n;i++)
    sum += arr[i];
  double ratio = sum/double(n);

  vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(n+1,vector<bool>(sum+1,false)));
  for(int k = 0;k < n;k++)
    for(int i = 0;i < n;i++)
      dp[k][i][0] = true;


  for(int k = 1;k < n;k++){
    for(int i = 1;i <= n;i++){
      for(int j = 1;j < sum;j++){
        if(dp[k][i-1][j])
          dp[k][i][j] = true;
        else if(j-arr[i-1] >= 0)
          dp[k][i][j] = dp[k-1][i-1][j-arr[i-1]];

        // cout<<dp[k][i][j]<<" ";

        if(dp[k][i][j] && (j/double(k)) == ratio){
          //cout<<(j/double(k))<<"--\n";
          return traceanswer(dp,k,i,j,arr);
        }
      }
      // cout<<endl;
    }
    // cout<<endl;
  }

  return answer;
}

int main(){

  vector<int> arr;
  int temp;
  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  vector<vector<int>> answer = equalaverage(arr);


  cout<<"--------"<<endl;
  for(int i = 0;i < 2;i++){
    for(auto j = answer[i].begin(); j != answer[i].end();j++)
      cout<<answer[i][j-answer[i].begin()]<<" ";
    cout<<endl;
  }
  

  return 0;
}
