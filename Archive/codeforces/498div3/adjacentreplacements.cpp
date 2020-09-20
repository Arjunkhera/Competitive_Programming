#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>

typedef long int li;
using namespace std;

int main(){
  li n; cin>>n;
  vector<li> arr(n);

  for(li i = 0;i < n;i++){
    cin>>arr[i];
    if(!(arr[i] & 1)) arr[i] -= 1;
  }
  for(auto i:arr) cout<<i<<" ";
  cout<<endl;

  return 0;
}
