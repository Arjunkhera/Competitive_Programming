#include<iostream>
#include<set>

using namespace std;

set<string> locker;

void permutations(string str,int index){

  if(index == str.length()-1){
    locker.insert(str);
    return;
  }

  for(int i=index;i<str.length();i++){
      swap(str[index],str[i]);
      permutations(str,index+1);
      swap(str[i],str[index]);
  }
}

int main(){

  string str;
  cin>>str;

  permutations(str,0);
  for(string s : locker)
    cout<<s<<endl;

  return 0;
}
