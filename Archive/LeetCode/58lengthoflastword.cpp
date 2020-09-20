#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int lengthOfLastWord(string s){

  if(s.empty())
    return 0;
  if(s.size() == 1 && s[0] != ' ')
    return 1;

  int i = s.size()-1;
  for(; i >= 0 && s[i] == ' ';i--);
  int last = i;
  for(; i >= 0 && s[i] != ' ';i--);
  return last-i;
}

int main(){

  string str;
  getline(cin,str);

  cout<<lengthOfLastWord(str)<<endl;

  return 0;
}
