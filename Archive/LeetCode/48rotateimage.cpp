#include<iostream>
#include<vector>

using namespace std;

// from discussion solutions : they are just too succint

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate_discussion(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

// my solution : using four pointers

void rotate(vector<vector<int>>& matrix) {

  int n = matrix.size();
  int temp;
  int a = 0;
  int b = n-1;
  int c = n-1;
  int d = 0;

  while(a < c){

    for(int j = a;j < b;j++){
      int i = j-a;
      temp = matrix[c-i][d];
      matrix[c-i][d] = matrix[c][b-i];
      matrix[c][b-i] = matrix[i+a][b];
      matrix[i+a][b] = matrix[a][i+d];
      matrix[a][i+d] = temp;
    }

    a++;
    b--;
    c--;
    d++;
  }

  if(a == c){
    temp = matrix[c][d];
    matrix[c][d] = matrix[c][b];
    matrix[c][b] = matrix[a][b];
    matrix[a][b] = matrix[a][d];
    matrix[a][d] = temp;
  }

}

int main(){

  int n;
  cin>>n;

  vector< vector<int> > matrix(n,vector<int>(n,0));

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>matrix[i][j];

  rotate(matrix);
  cout<<endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<matrix[i][j]<<" ";
    cout<<endl;
  }

  return 0;
}
