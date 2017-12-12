#include<iostream>
#include<vector>

using namespace std;

int n;
int answer=1;

void binarysearch(int start,int end){

  if(start>end)
    return ;

  int mid = (start+end)/2;
  int temp = mid*mid;

  if(temp <= n){
      answer = mid;
      binarysearch(mid+1,end);
      return;
  }
  else binarysearch(start,mid-1);
}

int main(){
  cin>>n;
  if(n!=1)
    binarysearch(0,n/2);
  cout<<answer<<endl;

  return 0;
}
