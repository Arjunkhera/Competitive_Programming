#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<typeinfo>

#define all(container) container.begin(),container.end()

using namespace std;

void vectorTraversal(){

  vector<int> arr(5,3);

  int a = 12;
  cout<<typeid(a).name()<<endl;
  cout<<typeid(arr).name()<<endl;

  // using normal indexing with size function
  for(int i = 0; i < arr.size(); i++)
    cout<<arr[i]<<" ";

  cout<<endl;
  int j = arr.size();
  j = j - 10;
  cout<<j<<endl;

  // using iterators
  for( vector<int>::iterator i = arr.begin(); i != arr.end() ;i++)
    cout<<*i<<" ";
  cout<<endl;

}

void vectorModifications(){

  vector<int> first(3,1);

  cout<<first.size()<<endl;
  first.push_back(2);
  cout<<first.size()<<endl;
  first.push_back(3);
  cout<<first.size()<<endl;

  vector<int> check(3,3);

  // important difference here
  check.resize(5);
  check.push_back(6);
  check.push_back(7);

  // notice that the elements pushed are added after the resize
  for(auto i:check)
    cout<<i<<" ";
  cout<<endl;
}

bool compare(string a,string b){

  if( a.length() != b.length() )
    return a.length() < b.length();
  else return a > b;

}

void sortingVector(){

  vector<string> arr;

  arr.push_back("apple");
  arr.push_back("mango");
  arr.push_back("ape");

  sort(arr.begin(),arr.end(),compare);

  for(string i:arr)
    cout<<i<<endl;

}

int main(){

  //vectorTraversal();
  //vectorModifications();
  //sortingVector();

  string str = "";
  cout<<str.length()<<"{}"<<str.length()-1<<endl;

  return 0;
}
