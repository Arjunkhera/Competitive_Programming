#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// solution function
int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C){

  int tempmin,tempmax,answer = INT_MAX,i = 0,j = 0,k = 0,len1 = A.size(),len2 = B.size(),len3 = C.size();
  while(i < len1 && j < len2 && k < len3){
      tempmin = min(A[i],min(B[j],C[k]));
      tempmax = max(A[i],max(B[j],C[k]));
      answer = min(answer,tempmax-tempmin);
      if(tempmin == A[i]) i++;
      else if (tempmin == B[j]) j++; else k++;
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
