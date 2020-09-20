#include<iostream>
#include<vector>

using namespace std;

int trap(vector<int>& height){

  if(height.size() <= 2)
    return 0;

  int n = height.size();
  vector<int> ltor(n,-1);
  vector<int> rtol(n,-1);

  int temp = 0;
  ltor[0] = 0;
  for(int i = 1;i < n;i++)
    if(height[i] > height[temp]){
      ltor[i] = i;
      temp = i;
    }
    else ltor[i] = temp;

  temp = n-1;
  rtol[n-1] = n-1;
  for(int i = n-2;i >= 0;i--)
    if(height[i] > height[temp]){
      rtol[i] = i;
      temp = i;
    }
    else rtol[i] = temp;

  int answer = 0;
  temp = 0;

  for(int i = 0;i < n;i++)
    if(height[ltor[i]] <= height[i] || height[rtol[i]] <= height[i]){
      answer = answer+temp;
      temp = 0;
    }
    else temp = temp + min(height[ltor[i]],height[rtol[i]]) - height[i];

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

  cout<<trap(arr)<<endl;

  return 0;
}
