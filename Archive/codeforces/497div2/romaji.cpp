#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
  string str; cin>>str;

  set<char> vowels = {'a','e','i','o','u'};
  bool flag = true;

  int i = 0;
  while(i < str.length()){
    if(str[i] == 'n') { i++; continue; }
    if(vowels.find(str[i]) != vowels.end()) { i++; continue; }
    // if a consonant
    i++;
    if(i == str.length() || vowels.find(str[i]) == vowels.end()) { flag = false; break; }
  }
  if(flag) cout<<"YES"; else cout<<"NO";
  return 0;
}

/*
*/
