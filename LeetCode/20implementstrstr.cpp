#include<iostream>
#include<vector>
#include<string>

using namespace std;

int strStr(string haystack, string needle) {

  if(haystack.empty() && needle.empty())
    return 0;
  if(!haystack.empty() && needle.empty())
    return 0;
  if(haystack.empty() && !needle.empty())
    return -1;

  int i = 0, j = 0;
  while(i < haystack.size() && j < needle.size()){
    if(haystack[i] == needle[j])
      j++;
    else {
        int k = j;

    }
    else j = 0;
    i++;
  }
  if(j == needle.size())
    return i-needle.size();
  else return -1;
}

int main(){
  string haystack,needle;
  getline(cin,haystack);
  getline(cin,needle);

  cout<<strStr(haystack,needle)<<endl;

  return 0;
}

// mississippi
// issip
