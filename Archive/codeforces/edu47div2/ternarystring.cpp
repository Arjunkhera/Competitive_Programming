#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>

typedef long int li;
using namespace std;

int main(){
  string s;
  cin>>s;

  int start,temp,i = 0,n = s.length();
  while(i < n && (s[i] == '0' || s[i] == '1')) i++;
  sort(s.begin(),s.begin()+i);

  while(i < n){
    if(s[i] == '2'){
      start = i;
      while(i < n && s[i] == '2') i++;
      if(i == n) break;

      if(s[i] == '1'){
        while(i < n && s[i] == '1') i++;
        sort(s.begin()+start,s.begin()+start+i);
        i--;
        while(i >= 0 && s[i] == '2') i--;
        i++;
        continue;
      }

      if(s[i] == '0'){
        temp = i;
        while(i < n && s[i] == '0') i++;
        if(i == n) break;
        if(s[i] == '2') continue;
        while(i < n && s[i] == '1') i++;
        sort(s.begin()+temp,s.begin()+temp+i);
        i = start; continue;
      }
    }
    else i++;
  }
  cout<<s;
  return 0;
}

/*
int main(){
  string s;
  cin>>s;
  bool flag = true;
  int i = 0,n = s.length(),start = 0;
  while(i < n){
      if(s[i] == '1') { i++; continue; }
      if(s[i] == '0'){
        while(i < n && (s[i] == '1' || s[i] == '0')) i++;
        if(i == n) break;
        sort(s.begin()+start,s.begin()+i);
        start = i; continue;
      }
      if(s[i] == '2'){
        while(i < n && (s[i] == '2' || s[i] == '1')) i++;
        if(i == n) break;
        sort(s.begin()+start,s.begin()+i);
        start = i; continue;
      }
  }
  sort(s.begin()+start,s.end());

  // cout<<"mid is : "<<s<<"\n";
  flag = true;
  int count0,count1,count2;
  while(flag){
  i = 0; flag = false;
  while(i < n){
    while(i < n && (s[i] == '1' || s[i] == '0')) i++;
    if(i == n) break;

    start = i; count0 = 0; count1 = 0; count2 = 0;
    while(i < n && s[i] == '2') { count2++; i++; }
    if(i == n) break;
    if(s[i] == '1') continue;
    while(i < n && s[i] == '0') { count0++; i++; }
    if(i == n) break;
    if(s[i] == '2') continue;
    while(i < n && s[i] == '1') { count1++; i++; }
    flag = true;
    int j = start;
    while(count1--) { s[j] = '1'; j++; }
    while(count2--) { s[j] = '2'; j++; }
    while(count0--) { s[j] = '0'; j++; }
  }
  }

  cout<<s;
  return 0;
}
*/
/*
while(flag){
  flag = false;
  for(int i = 1;i < s.length();){
    if(s[i] == '0' && s[i-1] == '1') { s[i] = '1'; s[i-1] = '0'; flag = true; continue;}
    if(s[i] == '1' && s[i-1] == '2') { s[i] = '2'; s[i-1] = '1'; flag = true; continue;}
    i++;
  }
}
*/
