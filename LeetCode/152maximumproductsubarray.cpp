#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int kadane(vector<int>& arr){

  if(arr.empty())
    return 0;

  int answer = INT_MIN;
  int positive = 1,negative = 1;
  int i = 0;
  bool truePositive = false;

  while(i < arr.size()){

    if(arr[i] == 0){
      truePositive = false;
      answer = (answer < 0)?0:answer;
      positive = 1;
      negative = 1;
      i++;
      continue;
    }

    if(arr[i] > 0){
      truePositive = true;
      positive = positive*arr[i];
      negative = min(negative*arr[i],1);
    }
    else {
      int temp = positive;
      if(negative*arr[i] >= 1)
        truePositive = true;
      positive = max(negative*arr[i],1);
      negative = temp*arr[i];
    }

    i++;
    if(!truePositive && positive == 1)
      continue;
    answer = max(answer,positive);
  }

  if(answer == INT_MIN)
    answer = negative;

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

  return 0;
}
