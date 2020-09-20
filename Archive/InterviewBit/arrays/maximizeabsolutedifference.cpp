#include<iostream>
#include<vector>

using namespace std;

int maxArr(vector<int> &A){
 int max1 = INT_MIN,max2 = INT_MIN,ans = INT_MIN;
 int min1 = INT_MAX,min2 = INT_MAX;
 for(int i=0;i<A.size();i++){
    max1 = max(max1,A[i] + i); min1 = min(min1,A[i] + i);
    max2 = max(max2,A[i] - i); min2 = min(min2,A[i] - i);
  }
  ans = max(ans,max1 - min1);
  ans = max(ans,max2 - min2);

  return ans;
}

int main(){
  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  cout<<maxArr(arr)<<endl;

  return 0;
}
