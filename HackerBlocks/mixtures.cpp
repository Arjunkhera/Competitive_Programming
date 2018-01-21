#include<iostream>
#include<climits>

using namespace std;
typedef long long int ll;

int main(){
  // input
  ll n;
  cin>>n;
  ll *values = new ll[n+1];
  for(ll i=1;i<=n;i++)
    cin>>values[i];

  // edge case
  if(n==1){
    cout<<"0\n";
    return 0;
  }
  // dp initialization
  ll **smoke = new ll*[n+1];
  for(ll i=0;i<=n;i++)
    smoke[i] = new ll[n+1];
  ll **arr = new ll*[n+1];
  for(ll i=0;i<=n;i++)
    arr[i] = new ll[n+1];
  for(ll i=1;i<=n;i++){
    arr[i][i] = values[i];
    smoke[i][i] = 0;
  }

  // solve
  ll k,best_smoke,best_value,temp_smoke,temp_value;
  for(ll i=2;i<=n;i++){
    k = i;
    for(ll j=1;j<=n-i+1;j++){
      smoke[j][k] = INT_MAX;
      for(ll lm=j;lm<k;lm++){
        temp_smoke = smoke[j][lm]+smoke[lm+1][k]+arr[j][lm]*arr[lm+1][k];
        if(temp_smoke<smoke[j][k]){
          smoke[j][k] = temp_smoke;
          arr[j][k] = (arr[j][lm]+arr[lm+1][k])%100;
        }
      }
      k++;
    }
  }
  cout<<smoke[1][n]<<endl;
  return 0;
}
/*
//display
cout<<"smoke\n";
for(ll i=1;i<=n;i++){
  for(ll j=1;j<=n;j++)
    cout<<smoke[i][j]<<" ";
  cout<<endl;
}
cout<<"arr\n";
for(ll i=1;i<=n;i++){
  for(ll j=1;j<=n;j++)
    cout<<arr[i][j]<<" ";
  cout<<endl;
}
*/

/*
if(i==2){
  arr[j][k] = (values[j]+values[j+1])%100;
  smoke[j][k] = values[j]*values[j+1];
  //cout<<smoke[k][j]<<" "<<arr[k][j]<<endl;
  k++;
  continue;
}

up_smoke = smoke[j][k-1]+arr[j][k-1]*values[k];
down_smoke = smoke[j+1][k]+arr[j+1][k]*values[k-i+1];
//cout<<j<<" "<<k<<endl;
//cout<<up_smoke<<" "<<down_smoke<<endl;
if(up_smoke < down_smoke){
  smoke[j][k] = up_smoke;
  arr[j][k] = (arr[j][k-1]+values[k])%100;
}
else {
  smoke[j][k] = down_smoke;
  arr[j][k] = (arr[j+1][k]+values[k-i+1])%100;
}
*/
