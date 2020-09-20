#include<iostream>
#include<vector>
#include<string>

using namespace std;

int strStr_kmp(string haystack, string needle){
  if(haystack.empty() && needle.empty())
    return 0;
  if(!haystack.empty() && needle.empty())
    return 0;
  if(haystack.empty() && !needle.empty())
    return -1;

  int n = haystack.size();
  int m = needle.size();
  vector<int> preprocess(m,0);
  int i = 0,j = 1;
  // preprocess the substring
  while(j < m)
    if(needle[i] == needle[j]){
      preprocess[j] = i+1;
      i++;
      j++;
    }
    else {
      while(i != 0 && needle[i] != needle[j])
        i = preprocess[i-1];
      if(needle[i] == needle[j]){
        preprocess[j] = i+1;
        i++;
      }
      j++;
    }
  // traverse the main substring
  i = 0;
  j = 0;
  while(i < n && j < m)
    if(haystack[i] == needle[j]){
      i++;
      j++;
    }
    else {
      while(j != 0 && haystack[i] != needle[j])
        j = preprocess[j-1];
      if(haystack[i] == needle[j])
        j++;
      i++;
    }

  if(j == m)
    return i-m;
  return -1;
}

// bruteforce : keep comparing for haystack index
int strStr_bruteforce(string haystack, string needle){

  if(haystack.empty() && needle.empty())
    return 0;
  if(!haystack.empty() && needle.empty())
    return 0;
  if(haystack.empty() && !needle.empty())
    return -1;

  int n = haystack.size();
  int m = needle.size();
  int j;

  for(int i = 0;i < n-m+1;i++){
    for(j = 0;j < m && haystack[i+j] == needle[j];j++);
    if(j == m)
      return i;
  }
  return -1;
}

int main(){
  string haystack,needle;
  getline(cin,haystack);
  getline(cin,needle);

  //cout<<strStr_bruteforce(haystack,needle)<<endl;
  cout<<strStr_kmp(haystack,needle)<<endl;

  return 0;
}

// mississippi
// issip
