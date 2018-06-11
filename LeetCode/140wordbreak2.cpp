#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<string> bottomupdp(string str,int start,unordered_set<string> &wordDict,unordered_map<int,vector<string>> &store){

  if(store.count(start))
    return store[start];

  string prefix;
  vector<string> rem;
  for(int i = start+1;i <= str.size();i++){
    prefix = str.substr(start,i-start);
    if(wordDict.count(prefix)){
        rem = bottomupdp(str,i,wordDict,store);
        for(string j:rem)
          if(j == "")
            store[i].push_back(prefix+"");
          else store[i].push_back(prefix+" "+j);
    }
  }

  return store[start];
}

void recursive(string str,unordered_set<string> &wordDict,vector<string> &answer,string result){

  int n = str.size();
  string temp;

  for(int i = 1;i <= n;i++){
    temp = str.substr(0,i);
    if(wordDict.find(temp) != wordDict.end()){
      if(i == n){
        result = result + temp;
        answer.push_back(result);
        return;
      }
      recursive(str.substr(i,n-i),wordDict,answer,result+temp+" ");
    }
  }
}

vector<string> wordBreak(string s, vector<string>& wordDict){

  unordered_set<string> arr;
  for(int i = 0;i < wordDict.size();i++)
    arr.insert(wordDict[i]);

  unordered_map<int,vector<string>> store {{s.size(),{""}}};
  vector<string> answer;
  //recursive(s,arr,answer,"");
  answer = bottomupdp(s,0,arr,store);
  return answer;
}

int main(){

  string str;
  cin>>str;

  int n;
  cin>>n;
  vector<string> dictionary(n);
  for(int i = 0;i < n;i++)
    cin>>dictionary[i];

  vector<string> answer = wordBreak(str,dictionary);
  for(auto i:answer)
    cout<<i<<endl;

  return 0;
}
