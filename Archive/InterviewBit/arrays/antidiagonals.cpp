vector<vector<int> > Solution::diagonal(vector<vector<int> > &matrix) {

  vector< vector<int> > answer;
  if(matrix.empty())
    return answer;

  int m = matrix.size();
  int n = matrix[0].size();
  int r,col;
  vector<int> temp;


  for(int l=0;l<n;l++){
    r = 0;
    col = l;
    while(r < m && col >= 0)
      temp.push_back(matrix[r++][col--]);

    answer.push_back(temp);
    temp.clear();
  }

  for(int l=1;l<m;l++){
    r = l;
    col = n-1;
    while(r < m && col >= 0)
      temp.push_back(matrix[r++][col--]);

    answer.push_back(temp);
    temp.clear();
  }

  return answer;
}
