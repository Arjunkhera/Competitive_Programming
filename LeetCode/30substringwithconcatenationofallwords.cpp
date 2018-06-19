#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

// solution function
vector<int> findSubstring(string s, vector<string>& words){
  vector<int> answer;
  if(s.empty() || words.empty()) return answer;

  unordered_map<string,int> main; for(auto k:words) main[k]++;
  int slen = s.size(),wlen = words[0].size(),total = words.size(),start,cur,i,j; string str;
  for(i = 0;i < wlen;i++){
    unordered_map<string,int> window; start = i; cur = 0;
    for(j = i;j <= (slen - wlen); j+= wlen){
      str = s.substr(j,wlen);
      // check if word belongs to the set or not, otherwise reset progress
      if(main.count(str)){
        // add the word to the window
        window[str]++; cur++;
        // shift the window right untill the violation is removed
        while(window[str] > main[str]){ window[s.substr(start,wlen)]-- ; cur--; start += wlen; }
        // push the index and shift the window right once
        if(cur == total){ answer.push_back(start); window[s.substr(start,wlen)]--; cur--; start += wlen;}
      }
      else { window.clear(); cur = 0; start = j+wlen; }
    }
  }
  return answer;
}

int main(){

  string temp,str;
  vector<string> arr;
  cin>>temp;
  while(temp != "end"){ arr.push_back(temp); cin>>temp; }
  cin>>str;

  vector<int> answer = findSubstring(str,arr);
  for(auto k:answer) cout<<k<<" ";
  cout<<endl;

  return 0;
}
