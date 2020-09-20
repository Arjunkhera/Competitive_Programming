#include<iostream>
#include<vector>
#include<set>

typedef long int li;
using namespace std;

int main(){
  li w,h,n,curheight = 1000000010;
  cin>>n;

  bool flag = true;
  while(n--){
    if(!flag){ cin>>w>>h; continue; }
    cin>>w>>h;
    if(curheight < w && curheight < h) flag = false;
    else if(curheight > w && curheight < h) curheight = h;
    else if(curheight > h && curheight < w) curheight = w;
    else curheight = max(h,w);
  }
  if(flag) cout<<"YES"; else cout<<"NO";
  return 0;
}

/*
*/
