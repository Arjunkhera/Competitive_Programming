#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// solution function
void arrange(vector<int> &arr){
  if(arr.empty()) return;

  int n = arr.size();
  for(int i = 0;i < n;i++) arr[i] += (arr[arr[i]]%n)*n;
  for(int i = 0;i < n;i++) arr[i] /= n;
}

// driver function
int main(){
  int temp; cin>>temp;
  vector<int> arr;
  while(temp != -1) {arr.push_back(temp); cin>>temp;}

  arrange(arr);
  for(auto i:arr) cout<<i<<" "; cout<<endl;

  return 0;
}
