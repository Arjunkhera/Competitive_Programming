#include<iostream>
#include<string>

using namespace std;

#define pi "3.14"
#define rep "pi"
void recursive(string str,int start){

  size_t position = str.find(pi);

  if(position == string::npos){
    cout<<str<<"\n";
    return;
  }

  str.replace(position,4,rep);
  recursive(str,position);
}

int main(){
  int n;
  cin>>n;
  cin.ignore();
  string str;

  while(n--){
    getline(cin,str);
    recursive(str,0);
  }
  return 0;
}
