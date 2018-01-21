#include<iostream>
#include<stack>

using namespace std;

int main(){

  stack<char> st;
  bool flag = true;
  string str;
  cin>>str;

  string::iterator i = str.begin();
  while(i!=str.end()){

    if(*i == ')'){
      if(st.empty())
        flag = false;
      else st.pop();
    }
    if(!flag)
      break;

    if(*i == '(')
      st.push(*i);
    i++;
  }

  if(!flag || !st.empty())
    cout<<"No\n";
  else cout<<"Yes\n";
  return 0;
}
