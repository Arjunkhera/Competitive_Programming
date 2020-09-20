#include<iostream>
#include<deque>

using namespace std;

int main(){
  int temp,n,time=0;
  cin>>n;

  deque<int> calling;
  deque<int> ideal;

  for(int i=0;i<n;i++){
    cin>>temp;
    calling.push_back(temp);
  }
  for(int i=0;i<n;i++){
    cin>>temp;
    ideal.push_back(temp);
  }

  while(!ideal.empty()){
    if(calling[0] == ideal[0]){
      time++;
      calling.pop_front();
      ideal.pop_front();
      continue;
    }
    while(calling[0] != ideal[0]){
      time++;
      temp = calling[0];
      calling.pop_front();
      calling.push_back(temp);
    }
  }
  cout<<time<<"\n";
  return 0;
}
