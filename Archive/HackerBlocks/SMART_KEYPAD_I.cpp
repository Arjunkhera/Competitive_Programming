#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maximum;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void calculate(string str,string temp,int start){

  int n = int(str[start])-48;
  for(string::iterator i=table[n].begin();i!= table[n].end();i++){
    temp.push_back(*i);

    if(start < maximum)
      calculate(str,temp,start+1);
    else
      cout<<temp<<"\n";

    temp.pop_back();
  }
}

int main(){
  string str;
  string temp = "";
  cin>>str;

  maximum = str.length()-1;
  calculate(str,temp,0);
  return 0;
}
