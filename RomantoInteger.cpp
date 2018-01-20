#include<iostream>
#include<vector>

using namespace std;

int romanToInt(string s) {
  vector<vector<string>> arr =
  {{"", "M", "MM", "MMM"},
  {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
  {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
  {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};

  int answer = 1;
  for(int)

  return 1;
}

int main(){
  string str;
  cin>>str;

  cout<<romanToInt(str)<<endl;
  return 0;
}
