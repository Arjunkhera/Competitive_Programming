#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool compare(string a,string b){
  if( a.length() != b.length() )
    return a.length()<b.length();
  else return a>b;
}

int main(){
  vector<string> arr;

  arr.push_back("apple");
  arr.push_back("mango");
  arr.push_back("ape");

  sort(arr.begin(),arr.end(),compare);

  for(string i:arr)
    cout<<i<<"\n";

}
