#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

// absolutely beautiful solution from guagua
bool isNumber_discussion(string s){

  string str;
  map<char,int> count;
  for(int j = 0;j < 10;j++) count[48+j] = 0;
  count['+'] = 0; count['-'] = 0; count['.'] = 0; count['e'] = 0;

  int i = 0, n = s.size();
  // remove the leading white spaces
  while(s[i] == ' ') {i++;}
  if(i == n) return false;
  // insert characters into a new string
  while(i < n){
    if(s[i] == ' ') break;
    if(count.find(s[i]) == count.end()) return false;
    count[s[i]]++; str.push_back(s[i]); i++;
  }
  // remove trailing whitespaces
  while(s[i] == ' ') {i++;}
  if(i != n) return false;

  // invalid frequency counts
  //cout<<str<<endl;
  if(count['.'] > 1 || count['e'] > 1 || count['+']+ count['-'] > 2 ) return false;
  n = str.size();
  int num_after = 0,num_before = 0; ;i = 0;
  if(str[i] == '+' || str[i] == '-') i++;
  while(i < n && (str[i] >= 48 && str[i] <= 57)) {num_before++;i++;}
  if(i == n && num_before) return true;
  if(str[i] == '.') i++;
  while(i < n && (str[i] >= 48 && str[i] <= 57)) {num_after++;i++;}
  // check the exponent if exist
  if(str[i] == 'e'){ if(num_before+num_after < 1) return false;
    i++; if(str[i] == '+' || str[i] == '-') i++; // skip the sign
    int num_after_e = 0;
    while(i < n && (str[i] >= 48 && str[i] <= 57)) {num_after_e++;i++;}
    if(num_after_e < 1) return false;
    //cout<<"hello\n";
  } else if((num_after == 0 && num_before == 0)||(num_before > 0 && num_after < 1)) return false;
  if(i == n) return true;
  return false;
}

int main(){
  string str;
  getline(cin,str);

  if(isNumber_discussion(str))
    cout<<"Valid\n";
  else cout<<"Not Valid\n";

  return 0;
}
