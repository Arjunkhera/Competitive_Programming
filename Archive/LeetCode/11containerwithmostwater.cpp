#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height){

  int answer = 0;
  int left = 0;
  int right = height.size()-1;

  while(left < right)
    if(height[left] < height[right]){
      answer = max(answer,height[left]*(right-left));
      left++;
    }
    else {
      answer = max(answer,height[right]*(right-left));
      right--;
    }

  return answer;
}

int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<maxArea(arr)<<endl;

  return 0;
}
