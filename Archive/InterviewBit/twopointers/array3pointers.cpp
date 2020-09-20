#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C){

  int tempsum1,tempsum2,tempsum3,answer = INT_MAX,i = 0,j = 0,k = 0,len1 = A.size(),len2 = B.size(),len3 = C.size();
  while(i < len1 && j < len2 && k < len3){
    tempsum1 = A[i] - B[j]; tempsum2 = B[j] - C[k]; tempsum3 = C[k] - A[i];
    answer = min(answer,max(abs(tempsum1),max(abs(tempsum2),abs(tempsum3))));
    if(abs(tempsum1) >= abs(tempsum2) && abs(tempsum1) >= abs(tempsum3))
      if(tempsum1 > 0) j++; else i++;
    else if(abs(tempsum2) >= abs(tempsum1) && abs(tempsum2) >= abs(tempsum3))
      if(tempsum2 > 0) k++; else j++;
    else if(abs(tempsum3) >= abs(tempsum1) && abs(tempsum3) >= abs(tempsum2))
      if(tempsum3 > 0) i++; else k++;
  }
  return answer;
}

int main(){
  int n,temp;
  cin>>n; temp = n;
  vector<int> arr1(n,0);
  while(temp--) { cin>>arr1[temp]; }

  cin>>n; temp = n;
  vector<int> arr2(n,0);
  while(temp--) { cin>>arr2[temp]; }

  cin>>n; temp = n;
  vector<int> arr3(n,0);
  while(temp--) { cin>>arr3[temp]; }

  cout<<minimize(arr1,arr2,arr3)<<endl;
  return 0;
}
