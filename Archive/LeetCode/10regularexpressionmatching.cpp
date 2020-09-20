#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool recursive(vector< vector<int> > &arr,int i,int j){

  if(i >= arr.size() || j >= arr[0].size())
    return false;

  if(i+1 == arr.size() && j+1 == arr[0].size())
    return true;

  if(arr[i][j+1] == 1)
    if(recursive(arr,i,j+1))
      return true;

  if(arr[i+1][j] == 1)
    if(recursive(arr,i+1,j))
      return true;

  if(arr[i+1][j+1] == 1)
    if(recursive(arr,i+1,j+1))
      return true;

  return false;
}

bool isMatchmytry(string s, string p){

  if(s.empty() || p.empty())
    return false;

  int m = p.size();
  int n = s.size();

  vector<int> wild;
  string newp;
  for(int i = 0;i < m;i++)
    if(p[i] == '*')
      wild.push_back(newp.size()-1);
    else newp.push_back(p[i]);

  /*
  for(auto i:wild)
    cout<<i<<"--";
  cout<<endl;
  cout<<newp<<endl;
  */

  int rows = newp.size();
  vector< vector<int> > arr(rows+1,vector<int>(n+1,0));

  wild.push_back(-1);
  int k = 0;
  arr[0][0] = 1;
  for(int i = 1;i <= rows;i++){

    if(i-1 == wild[k]){
      //cout<<"A "<<i<<"--"<<k<<endl;
      //cout<<newp[i-1]<<endl;
      arr[i][0] = 1;
      if(newp[i-1] == '.'){
        int j = 1;
        while(arr[i-1][j-1] != 1)
          j++;
        while(j <= n){
          arr[i][j] = 1;
          j++;
        }
      }
      else {
        for(int j = 1;j <= n;j++){
          if(arr[i-1][j-1] == 1 && newp[i-1] != s[j-1] ){
            arr[i][j-1] = 1;
            continue;
          }
          while(j <= n && newp[i-1] == s[j-1]){
            arr[i][j] = 1;
            j++;
          }
          j--;
        }
      }
      k++;
      continue;
    }

    //cout<<"B "<<i<<"--"<<k<<endl;
    for(int j = 1;j <= n;j++)
      if(newp[i-1] == '.' && arr[i-1][j-1] == 1)
        arr[i][j] = 1;
      else if(newp[i-1] == s[j-1] && arr[i-1][j-1] == 1)
        arr[i][j] = 1;
  }


  for(int i = 0;i <= rows;i++){
    for(int j = 0;j <= n;j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }


  return recursive(arr,0,0);
}

bool isMatch(string s, string p){

  if(p.empty())
    return s.empty();

  int m = s.size();
  int n = p.size();

  vector< vector<bool> > arr(m+1,vector<bool>(n+1,0));
  arr[0][0] = true;

  for(int j = 1;j <= n;j++)
    if(p[j-1] == '*')
      arr[0][j] = arr[0][j-2];

  for(int i = 1;i <= m;i++)
    for(int j = 1;j <= n;j++){

      if(p[j-1] == '.' || s[i-1] == p[j-1])
        arr[i][j] = arr[i-1][j-1];
      else if(p[j-1] == '*'){
        if(p[j-2] != '.' && s[i-1] != p[j-2])
          arr[i][j] = arr[i][j-2];
        else arr[i][j] = arr[i][j-1] || arr[i-1][j] || arr[i][j-2];
      }
      else arr[i][j] = false;
    }

  for(int i = 0;i <= m;i++){
    for(int j = 0;j <= n;j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }

  return arr[m][n];
}


int main(){

  string s,p;
  cin>>s>>p;

  if(isMatch(s,p))
    cout<<"Found"<<endl;
  else cout<<"Not Found"<<endl;

  return 0;
}

/*
mississippi
mis*is*p*.
mis*is*ip*.
*/
