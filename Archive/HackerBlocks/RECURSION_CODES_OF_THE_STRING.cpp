#include<iostream>
#include<vector>

using namespace std;

vector<string> answer;
int start = 0;

void calculate(string str,string temp){

  if(start == str.length()){
    answer.push_back(temp);
    start--;
    return;
  }

  int n = int(str[start])-48;
  temp.push_back(char(n+96));

  start++;
  calculate(str,temp);
  temp.pop_back();

  if(start == str.length()-1 || n>2){
    start--;
    return;
  }

  int m = int(str[start+1])-48;
  if(m>6 && n==2){
    start--;
    return;
  }

  n = m+10*n+96;
  temp.push_back(char(n));
  start+=2;
  calculate(str,temp);
  start-=2;
  temp.pop_back();

}

int main(){

  string str;
  string temp = "";
  cin>>str;

  calculate(str,temp);

  int i,length = answer.size()-1;
  cout<<"[";
  for(i=0;i<length;i++)
    cout<<answer[i]<<", ";
  cout<<answer[i]<<"]\n";
  return 0;
}
