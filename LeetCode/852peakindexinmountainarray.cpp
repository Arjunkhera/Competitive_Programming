#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// solution function
int peakIndexInMountainArray(vector<int>& A){
  if(A.size() < 3) return -1;

  long int n = A.size(),i = 0, j = n-1;
  while(i < j){ if(A[i+1] > A[i]) i++; if(A[j-1] > A[j]) j--; }
  if(i == j) return (int)i; else return -1;
}

int main(){
  int temp;
  cin>>temp;
  vector<int> arr;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }

  cout<<peakIndexInMountainArray(arr)<<endl;
  return 0;
}
