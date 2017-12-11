#include<iostream>
#include<vector>

using namespace std;

int sum = 0;

void calculate(vector<int> &arr,int left,int right,bool chance){

  if(left == right)
    return;

  int temp=0;
  if(arr[left] >= arr[right]){
    temp = arr[left];
    left++;
  }
  else {
    temp = arr[right];
    right--;
  }

  if(chance)
    sum += temp;

  calculate(arr,left,right,!chance);
}

int main(){

  int n,temp;
  cin>>n;

  vector<int> arr;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
  }
  calculate(arr,0,n-1,true);

  cout<<sum;
  return 0;
}
