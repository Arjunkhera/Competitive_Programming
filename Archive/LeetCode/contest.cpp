#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string shiftingLetters(string S, vector<int>& shifts) {

  if(S.empty())
    return "";

  string answer = S;
  long int sum = 0,temp;
  long int n = S.size();


  for(int i = n-1;i >= 0; i--){
      sum = (sum+shifts[i])%26;
      temp = (int(S[i]) - 97 + sum)%26;
      answer[i] = char(temp + 97);
  }

  return answer;
}

int main(){

  string str;
  cin>>str;

  vector<int> arr;
  int temp;
  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<shiftingLetters(str,arr)<<endl;

  return 0;
}
