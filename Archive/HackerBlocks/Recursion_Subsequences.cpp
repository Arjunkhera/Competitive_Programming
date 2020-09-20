#include<iostream>
#include<vector>

using namespace std;

vector<string> answer;

void calculate(string str,int start){
  string temp(1,str[start]);

  if(str.length() == start+1){
      answer.push_back(temp);
      return;
  }

  calculate(str,start+1);
  answer.push_back(temp);

  int n = answer.size();
  for(int i=0;i<n-1;i++){
    temp = str[start];
    answer.push_back(temp+answer[i]);
  }
}

int main(){

  string str;
  cin>>str;

  calculate(str,0);

  cout<<answer.size()+1<<"\n";
  cout<<""<<" ";
  for(string s : answer)
    cout<<s<<" ";

  cout<<endl;
  return 0;
}
