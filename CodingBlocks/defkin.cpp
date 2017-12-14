#include<iostream>

using namespace std;

int main(){

  int t,w,h,n,tempx,tempy;
  vector<int>arrx;
  vector<int>arry;
  cin>>t;

  while(t--){
    cin>>w>>h>>n;

    arrx.push_back(w-1);
    arry.push_back(h-1);

    for(int i=0;i<n;i++){
      cin>>tempx>>tempy;
      arrx.push_back(tempx);
      arry.push_back(tempy);
    }

    arrx.push_back(w+1);
    arry.push_back(h+1);

    arrx.clear();
    arry.clear();

    


  }

  return 0;

}
