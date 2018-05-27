#include<iostream>
#include<vector>

using namespace std;

int maxCrossing(vector<int>& arr,int left,int mid,int right){

  int sum = 0;
  int leftHalf = 0;
  for(int i = mid; i >= 0; i--){
    sum += arr[i];
    if(sum > leftHalf)
      leftHalf = sum;
  }

  sum = 0;
  int rightHalf = 0;
  for(int i = mid+1; i < arr.size(); i++){
    sum += arr[i];
    if(sum > rightHalf)
      rightHalf = sum;
  }

  return leftHalf + rightHalf;
}

int divideConquer(vector<int>& arr,int left,int right){

  // base case
  if( left > right)
    return 0;

  if(left == right)
    return arr[left];

  int mid = left + (right-left)/2;

  int leftHalf = divideConquer(arr,left,mid-1);
  int rightHalf = divideConquer(arr,mid+1,right);
  int crossing = maxCrossing(arr,left,mid,right);

  return max(crossing,max(leftHalf,rightHalf));

}

int kadane(vector<int>& arr){

  int answer = arr[0];
  int temp = arr[0];

  for(int i = 1; i < arr.size(); i++){

    temp = max(arr[i],temp+arr[i]);
    answer = max(answer,temp);
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
  cout<<divideConquer(arr,0,arr.size()-1)<<endl;

  return 0;
}
