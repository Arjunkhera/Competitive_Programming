#include<iostream>
#include<vector>

using namespace std;

vector<int> answer;
int k;

void calculate(vector<int> &temp,int index,int length){
  if( 6-length > k-index )
    return;

  if( length==6 || index == k){
    if(length<6)
      return;

    vector<int>::iterator i = temp.begin();
    for(;i!=temp.end();i++)
      cout<<*i<<" ";
    cout<<"\n";

    return;
  }

  temp.push_back(answer[index]);
  calculate(temp,index+1,length+1);
  temp.pop_back();

  calculate(temp,index+1,length);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin>>k;

  for(int i=0;i<k;i++){
      cin>>t;
      answer.push_back(t);
  }

  vector<int> temp;
  calculate(temp,0,0);
  return 0;
}
