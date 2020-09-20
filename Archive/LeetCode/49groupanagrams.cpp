#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

// solution function
vector<vector<string>> groupAnagrams(vector<string>& strs){
  vector<vector<string>> answer;
  if(strs.empty()) return answer;

  map<string,vector<string>> dict; string str;
  for(auto i:strs){ str = i; sort(str.begin(),str.end()); dict[str].push_back(i); }
  for(auto i:dict) answer.push_back(i.second);
  return answer;
}

// solution function
vector<vector<string>> groupAnagrams2(vector<string>& strs){
  vector<vector<string>> answer;
  if(strs.empty()) return answer;

  map<string,vector<string>> dict; vector<int> count(26,0);
  for(auto i:strs){
    string str = "";
    for(auto k:i) count[k-97]++;
    for(int k = 0;k < count.size(); k++) {str =  str + "." + to_string(count[k]); count[k] = 0;}
    cout<<str<<endl;
    dict[str].push_back(i);
  }
  for(auto i:dict) answer.push_back(i.second);
  return answer;
}

int main(){

  string temp,str;
  vector<string> arr;
  cin>>temp;
  while(temp != "end"){ arr.push_back(temp); cin>>temp; }

  vector<vector<string>> answer = groupAnagrams2(arr);
  for(auto i:answer){ for(auto j:i) cout<<j<<" "; cout<<endl; }

  return 0;
}
