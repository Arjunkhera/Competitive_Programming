#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(auto i : s){
        if(i == '('){
            st.push(')');
            continue;
        }
        if(i == '{'){
            st.push('}');
            continue;
        }
        if(i == '['){
            st.push(']');
            continue;
        }

        if(st.empty() || st.top() != i)
          return false;
        st.pop();
    }
    if(!st.empty())
      return false;
    return true;
}

int main(){
  string str;
  cin>>str;

  if(isValid(str))
    cout<<"Yes\n";
  else cout<<"No\n";
}
