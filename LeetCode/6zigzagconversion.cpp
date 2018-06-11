#include<iostream>
#include<vector>
#include<string>

using namespace std;

string convert(string s, int numRows) {

  string answer;
  if(numRows == 0)
    return answer;

  int j = 0;
  int n = s.size();
  //vector<int> arr(n,0);
  vector<string> arr(numRows);
  int i = 1;

  while(j < n){
    for(i = 1;i <= numRows && j < n;i++,j++)
      arr[i-1].push_back(s[j]);
      //arr[j] = i;
    for(i = numRows-1;i > 1 && j < n;i--,j++)
      arr[i-1].push_back(s[j]);
      //arr[j] = i;
  }

  for(i = 0;i < numRows;i++)
    answer = answer + arr[i];
  return answer;
}

int main(){
  string str = "PAYPALISHIRING";
  // cin>>str;
  int rows;
  cin>>rows;

  cout<<convert(str,rows)<<endl;

  return 0;
}
