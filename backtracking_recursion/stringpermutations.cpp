#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string> locker;

void display(){
  for(string s:locker)
    cout<<s<<endl;
}

void permutations(string str,int index){

  if(index == str.length()-1 ){
    locker.insert(str);
    return;
  }

  for(int i=index;i<str.length();i++){
    swap(str[index],str[i]);
    permutations(str,index+1);
    // backtrack : to ensure we get all permutations
    swap(str[i],str[index]);
  }
}

int main(){

  string str;
  cin>>str;

  permutations(str,0);
  cout<<"The number of unique strings are :"<<locker.size()<<endl;
  display();
  return 0;
}
