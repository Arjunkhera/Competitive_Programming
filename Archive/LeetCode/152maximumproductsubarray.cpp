#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int kadane(vector<int>& arr){
  if(arr.empty()) return 0;

  int n = arr.size(),prod = 1,answer = INT_MIN;
  for(int i = 0;i < n;i++){
    prod *= arr[i];
    answer = max(prod,answer);
    if(arr[i] == 0) prod = 1;
  }

  prod = 1;
  for(int i = n-1;i >= 0;i--){
    prod *= arr[i];
    answer = max(prod,answer);
    if(arr[i] == 0) prod = 1;
  }
  return answer;
}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -100){

    arr.push_back(temp);
    cin>>temp;

  }

  cout<<kadane(arr)<<endl;
  // cout<<divideConquer(arr,0,arr.size()-1);

  return 0;
}
