#include<iostream>
#include<vector>

using namespace std;

// space optimized : from discussion
int numDecodings2(string s){
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }
        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}

// solution function
int numDecodings(string s){

  if(s.empty())
    return 0;
  if(s[0] == '0')
    return 0;

  vector<int> arr(s.size()+1,0);
  arr[0] = 1;
  arr[1] = 1;
  for(int i = 2;i <= s.size(); i++){
    if(s[i-1] != '0')
      arr[i] = arr[i-1];
    if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7' ))
      arr[i] += arr[i-2];
  }

  return arr[s.size()];
}

int main(){

  string s;
  cin>>s;

  cout<<numDecodings(s)<<endl;

  return 0;
}
