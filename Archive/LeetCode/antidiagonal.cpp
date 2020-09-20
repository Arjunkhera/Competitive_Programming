#include<iostream>
#include<vector>

using namespace std;

vector<int> antidiagonal(vector< vector<int> >matrix){

  vector<int> answer;
  if(matrix.empty())
    return answer;
    
  int m = matrix.size();
  int n = matrix[0].size();
  int r,col;

  for(int l=0;l<n;l++){
    r = 0;
    col = l;
    while(r < m && col >= 0)
      answer.push_back(matrix[r++][col--]);
  }

  for(int l=1;l<m;l++){
    r = l;
    col = n-1;
    while(r < m && col >= 0)
      answer.push_back(matrix[r++][col--]);
  }

  return answer;
}

int main(){

  int m,n;
  cin>>m>>n;

  vector< vector<int> > matrix(m,vector<int>(n,0));

  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>matrix[i][j];

  vector<int> answer = antidiagonal(matrix);
  cout<<endl;

  for(auto i:answer)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
