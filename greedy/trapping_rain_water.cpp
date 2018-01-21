#include<iostream>
#include<vector>

using namespace std;

int optimizespace(vector<int> &arr){
    int result = 0;
    int left_max = 0, right_max = 0;
    int lo = 0, hi = arr.size()-1;

    while(lo <= hi) {
        if(arr[lo] < arr[hi]){
            if(arr[lo] > left_max)
            left_max = arr[lo];
            else
            result += left_max - arr[lo];
            lo++;
        }
        else{
            if(arr[hi] > right_max)
            right_max = arr[hi];
            else
            result += right_max - arr[hi];
            hi--;
        }
    }

  return result;
}

int solve(vector<int> &arr){
  int temp,answer=0;
  int n = arr.size();
  int left[n];
  int right[n];

  temp=0;
  for(int i=0;i<n;i++){
    if(arr[i] > temp)
      temp = arr[i];
    left[i] = temp;
  }

  temp=0;
  for(int i=n-1;i>=0;i--){
    if(arr[i] > temp)
      temp = arr[i];
    right[i] = temp;
  }

  for(int i=0;i<n;i++){
    answer += (min(left[i],right[i])-arr[i]);
  }

  return answer;
}

int main(){

  int t,n,temp;
  cin>>t;
  vector<int> arr;

  while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>temp;
      arr.push_back(temp);
    }

    cout<<solve(arr)<<"\n";
    arr.clear();
  }
  return 0;
}
