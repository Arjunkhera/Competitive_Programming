#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
  return a.second < b.second;
}

int main(){

  int t;
  cin>>t;
  int n,answer,start,end;
  vector<pair<int,int>>arr;

  while(t--){

    cin>>n;
    for(int i=0;i<n;i++){
      cin>>start>>end;
      arr.push_back(make_pair(start,end));
    }

    sort(arr.begin(),arr.end(),compare);

    vector<pair<int,int>>::iterator i = arr.begin();
    int last_time = (*i).first;
    answer = 1;

    while(i!=arr.end()){

      if((*i).first >= last_time){
        answer++;
        last_time = (*i).second;
      }
      i++;
    }

    cout<<"The answer is :"<<answer<<endl;
    arr.clear();
  }
  return 0;
}
