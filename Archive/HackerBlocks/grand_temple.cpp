#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;

ll solve(vector<ll> &x,vector<ll> &y,int n){

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  ll max_x=INT_MIN;
  ll max_y=INT_MIN;

  for(int i=1;i<n;i++){
    if(x[i]-x[i-1] > max_x)
      max_x = x[i]-x[i-1];
    if(y[i]-y[i-1] > max_y)
      max_y = y[i]-y[i-1];
  }

  return (max_x-1)*(max_y-1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t,tx,ty,n;
  vector<ll> x;
  vector<ll> y;

  t=1;
  while(t--){
    cin>>n;

    //input
    x.push_back(0);
    y.push_back(0);
    for(int i=0;i<n;i++){
      cin>>tx>>ty;
      x.push_back(tx);
      y.push_back(ty);
    }
    //x.push_back(w+1);
    //y.push_back(h+1);

    cout<<solve(x,y,n+1)<<"\n";

    //x.clear();
    //y.clear();
  }
  return 0;
}
