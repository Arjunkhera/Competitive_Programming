#include<iostream>

using namespace std;
typedef long long int ll;

int main(){
  string str;
  cin>>str;
  ll answer=0,power = 1;
  string::iterator i = str.end()-1;
  while(i >= str.begin()){
    if(*i == '1')
      answer = answer + power;
    power = power*2;
    i--;
  }
  cout<<answer<<"\n";
  return 0;
}
