#include<iostream>
#include<vector>

using namespace std;

int main(){

  char str[] = "arjun";
  cout<<str<<endl;

  char *ptr = str;
  cout<<ptr<<endl;

  char c = 'a';
  cout<<c<<endl;
  ptr = &c;
  cout<<ptr<<endl;

  return 0;
}
