#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define len 1010

bool comparator(pair<int,int> a,pair<int,int> b){
  return a.first < b.first;
}

int main(){

  int s,n;
  int left,right;
  cin>>s>>n;

  vector<pair<int,int>> weights;
  int arr[len][len] = {0};

  for(int i=0;i<n;i++){
    cin>>left>>right;
    weights.push_back(make_pair(left,right));
  }
  sort(weights.begin(),weights.end());

  for(int i=1;i<=n;i++)
    for(int j=1;j<=s;j++){
      if(j<weights[i-1].first){
        arr[i][j]=arr[i-1][j];
        continue;
      }
      arr[i][j] = max(arr[i-1][j],arr[i-1][j-weights[i-1].first]+weights[i-1].second);
    }

  /*
  for(int i=0;i<=n;i++){
    for(int j=0;j<=s;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  cout<<arr[n][s]<<endl;
  return 0;
}
