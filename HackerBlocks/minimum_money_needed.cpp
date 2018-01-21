#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
  int n,w,temp;
  cin>>n>>w;

  vector<int>arr;
  arr.push_back(INT_MAX);
  for(int i=0;i<w;i++){
    cin>>temp;
    arr.push_back(temp);
  }

  vector<int>solution(w+2,INT_MAX);
  solution[0] = 0;
  for(int i=1;i<=w;i++){
    for(int j=1;j<=w;j++){
      if(j>i)
        break;
      if(arr[j] == -1)
        continue;
      solution[i] = min(solution[i],solution[i-j]+arr[j]);
    }
  }
  /*
  for(int i=0;i<=w;i++){
    cout<<solution[i]<<" ";
  }
  cout<<endl;
  */
  if(solution[w] == INT_MAX)
    cout<<"-1\n";
  else cout<<solution[w]<<"\n";


  return 0;
}
