#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

set<int> locker;
bool comparator(pair<int,int> a,pair<int,int> b){
  return a.first > b.first;
}

int main(){
  int t,n,l,b,h,answer,i,j;
  vector<pair<int,int>> arr;
  cin>>t;

  while(t--){
    cin>>n;
    for(i=0;i<n;i++){
      cin>>l>>b>>h;
      arr.push_back(make_pair(l,b*h));
      arr.push_back(make_pair(b,l*h));
      arr.push_back(make_pair(h,b*l));
    }
    sort(arr.begin(),arr.end(),comparator);

    
    for(int k=0;k<3*n;k++)
      cout<<arr[k].first<<" "<<arr[k].second<<"\n";


    answer = arr[0].first;
    locker.insert(arr[0].second);
    j=i=1;
    while(1){
      if(i==n||j==3*n)
        break;

      if(locker.find(arr[j].second) == locker.end()){
        answer += arr[j].first;
        locker.insert(arr[j].second);
        i++;
      }
      j++;
    }
    cout<<answer<<"\n";
    locker.clear();
    arr.clear();
  }
  return 0;
}
