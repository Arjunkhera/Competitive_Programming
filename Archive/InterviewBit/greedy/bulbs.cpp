#include<iostream>
#include<vector>

using namespace std;

// solution function
int bulbs(vector<int> &arr){
  if(arr.empty()) return 0;

  int answer = 0; bool flag = true;
  for(int i = 0;i < arr.size();i++){
    if(flag){ if(arr[i] == 1) continue; answer++; flag = !flag; }
    else { if(arr[i] == 0) continue; answer++; flag = !flag; }
  }
  return answer;
}

// driver function
int main(){

  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }

  cout<<bulbs(arr)<<endl;

  return 0;
}
