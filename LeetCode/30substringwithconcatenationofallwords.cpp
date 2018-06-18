#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solution function
vector<int> findSubstring(string s, vector<string>& words){
  

}

int main(){

  string temp,str;
  vector<string> arr;
  cin>>temp;
  while(temp != "end"){ arr.push_back(temp); cin>>temp; }

  vector<int> answer = findSubstring();
  for(auto k:answer) cout<<k<<" ";
  cout<<endl;

  return 0;
}
