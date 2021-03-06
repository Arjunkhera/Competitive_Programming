#include<iostream>

using namespace std;

string elegant(string str){

  string answer;
  if(str.empty())
    return answer;
  if(str.size() == 1)
    return str;
  int n = str.size();
  int length = 0;
  int start,end,i,j;

  for(int k = 0;k < n;k++){
    // odd length palindromes
    for(i = k,j = k;i >= 0 && j < n && str[i] == str[j];i--,j++)
      if(j-i+1 > length){
        length = j-i+1;
        start = i;
        end = j;
      }
    // even length palindromes
    for(i = k,j = k+1;i >= 0 && j < n && str[i] == str[j];i--,j++)
      if(j-i+1 > length){
        length = j-i+1;
        start = i;
        end = j;
      }
  }

  for(int k = start;k <= end;k++)
    answer.push_back(str[k]);
  return answer;
}

string longestPalindrome(string s){

  int n = s.length();
  int arr[n][n] = {0};
  int start=0,end=0;
  int length=0;

  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      // single length string
      if(j==i){
        arr[i][j] = 1;
        continue;
      }

      // double length string
      if(j+1 == i && s[i] == s[j] ){
        arr[j][i] = 1;
        if(i-j+1 > length){
          length = i-j+1;
          start = j;
          end = i;
        }
        continue;
      }

      // any remaining length string
      if(s[j] == s[i] && arr[j+1][i-1]){
        arr[j][i] = 1;
        if(i-j+1 > length){
          length = i-j+1;
          start = j;
          end = i;
        }
      }
    }
  }

  string answer;
  for(int k=start;k<=end;k++)
    answer.push_back(s[k]);

  return answer;
}

int main(){
  string str;
  cin>>str;

  cout<<longestPalindrome(str)<<endl;
  cout<<elegant(str)<<endl;

  return 0;
}
