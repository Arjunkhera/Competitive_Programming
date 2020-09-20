#include<iostream>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex){

  rowIndex += 1;
  long int cur = 1;
  vector<int> answer;

  for(long int j = 1;j <= rowIndex;j++){
      answer.push_back(cur);
      cur = cur*(rowIndex-j)/j;
  }

  return answer;
}

int main(){

  int n;
  cin>>n;

  vector<int> answer = getRow(n);

  for(auto i:answer)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
