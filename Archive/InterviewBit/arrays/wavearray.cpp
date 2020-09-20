#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> &arr){

  bool flag = true;
  for(int i = 0;i < arr.size()-1;i++){

    if(flag && arr[i] < arr[i+1])
      swap(arr[i],arr[i+1]);
    else if(!flag && arr[i] > arr[i+1])
      swap(arr[i],arr[i+1]);

    flag = !flag;  
  }

}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  solve(arr);

  for(auto i:arr)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
