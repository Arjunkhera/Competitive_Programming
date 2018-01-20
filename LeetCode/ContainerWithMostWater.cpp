#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height){

  int length = height.size();
  vector<int> left(length,-1);
  vector<int> right(length,-1);

  int largest=0,index=-1;
  for(int i=0;i<length;i++){
    if(height[i] >= largest){
      largest = height[i];
      index = i;
    }
    left[i] = index;
  }
  largest=0;
  index=-1;
  for(int i=length-1;i>=0;i--){
    if(height[i] >= largest){
      largest = height[i];
      index = i;
    }
    right[i] = index;
  }

  /*
  for(int i=0;i<length;i++){
    cout<<left[i]<<" ";
  }
  cout<<"\n";
  for(int i=0;i<length;i++){
    cout<<right[i]<<" ";
  }
  cout<<"\n";
  */

  int temp,answer = 0,sum=0;
  for(int i=0;i<length;i++){

    if(left[i] == i || right[i] == i){
      answer = (answer > sum)?answer:sum;
      sum = 0;
      //cout<<sum<<" ";
      continue;
    }

    temp = (height[left[i]] > height[right[i]])?height[right[i]]:height[left[i]];
    sum += temp-height[i];
    //cout<<sum<<" ";
  }

  return answer;
}

int main(){

  vector<int> arr;
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
  }
  cout<<maxArea(arr)<<"\n";
  return 0;
}
