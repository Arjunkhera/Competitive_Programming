#include<iostream>
#include<vector>

using namespace std;

// solution function
vector<vector<int>> transpose(vector<vector<int>>& A){
  vector<vector<int>> answer(A[0].size(),vector<int>(A.size(),0));
  if(answer.empty()) return answer;

  int rows = A.size(),columns = A[0].size();
  for(int i = 0;i < rows;i++) for(int j = 0;j < columns;j++) answer[j][i] = A[i][j];
  return answer;
}

// driver function
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> arr(m,vector<int>(n,0));
  for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin>>arr[i][j];

  vector<vector<int>> answer = transpose(arr);
  for(auto i:answer) { for(auto j:i) cout<<j<<" "; cout<<endl; }

  return 0;
}
