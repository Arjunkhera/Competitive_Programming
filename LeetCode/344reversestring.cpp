#include<iostream>
#include<string>
#include<vector>

using namespace std;

string reverseString(string s) {

  if(s.empty() || s.size() == 1)
    return s;

  int i = 0;
  int j = s.size()-1;
  while(i < j){
    swap(s[i],s[j]);
    i++;
    j--;
  }
  return s;
}

int main(){

  string str;
  getline(cin,str);

  cout<<reverseString(str)<<endl;

  return 0;
}
