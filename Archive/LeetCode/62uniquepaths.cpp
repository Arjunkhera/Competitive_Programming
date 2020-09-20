#include<iostream>
#include<vector>

using namespace std;

// taken from the discussions --> space optimized
int uniquePaths_spaceoptmized(int m, int n) {
   if (m > n) return uniquePaths_spaceoptmized(n, m);
   vector<int> cur(m, 1);
   for (int j = 1; j < n; j++)
       for (int i = 1; i < m; i++)
         cur[i] += cur[i - 1];
   return cur[m - 1];
}

// solution function
int uniquePaths(int m, int n){

  vector< vector<int> > arr(m,vector<int>(n,0));
  arr[0][0] = 1;

  for(int i = 0;i < m;i++)
    for(int j = 0;j < n;j++){
      if(i-1 >= 0)
        arr[i][j] += arr[i-1][j];
      if(j-1 >= 0)
        arr[i][j] += arr[i][j-1];
    }

  return arr[m-1][n-1];
}

int main(){

  int m,n;
  cin>>m>>n;

  cout<<uniquePaths(m,n)<<endl;

  return 0;
}
