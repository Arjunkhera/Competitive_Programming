#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int romanToInt(string s){

  int answer = 0;
  map<char,int> values;

  values['I'] = 1;
  values['V'] = 5;
  values['X'] = 10;
  values['L'] = 50;
  values['C'] = 100;
  values['D'] = 500;
  values['M'] = 1000;

  answer = values[s.back()];

  for (int i = s.length() - 2; i >= 0; --i)
    if (values[s[i]] < values[s[i + 1]])
      answer -= values[s[i]];
    else
      answer += values[s[i]];


  /*
  // my solution
  while(i < s.size()){
    answer = answer + values[s[i]];
    if((s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')) || (s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')) || (s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')))
      answer = answer - 2*values[s[i-1]];
    i++;
  }
  */

  return answer;
}

int main(){

  string str;
  cin>>str;

  int n = romanToInt(str);
  cout<<n<<endl;

  return 0;
}
