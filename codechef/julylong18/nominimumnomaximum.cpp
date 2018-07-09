#include<iostream>
#include<vector>
#include<algorithm>

#define modulo 1000000007
typedef long int li;

using namespace std;

li findpower(li base,li power){
  if(base == 0 || base == 1 || power == 1) return base;
  if(power == 0) return 1;

  li answer = 1;
  while(power){
    if(power & 1) answer = (answer*base)%modulo;
    base = (base*base)%modulo;
    power >>= 1;
  }
  return answer;
}

void binomial(li n,li k,vector<vector<li>> &coeff){
  for(li i = 0;i <= n; i++) coeff[i][0] = 1;

  for(li i = 1;i <= n; i++)
    for(li j = 1;j <= k; j++)
      if(j == i) coeff[i][j] = 1;
      else coeff[i][j] = coeff[i-1][j-1] + coeff[i-1][j];
}

int main(){
  li answer,power;
  int sz,k,n,t; cin>>t;
  while(t--){
    answer = 1;
    cin>>n>>k;

    // input the array
    vector<int> arr(n),powers(n+1,0);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    sort(arr.begin(),arr.end());

    // precalculate the coefficients
    vector<vector<li>> coeff(n+1,vector<li>(k+1,0));
    binomial(n,k,coeff);

    // solution
    for(int i = 0;i <= n-k;i++)
      for(int j = i+k-1;j < n ;j++){
        power = coeff[j-i-2][k-3];
        powers[i+1] += power; powers[j] -= power;
      }

    power = 0;
    for(int i = 0;i < n;i++) { power += powers[i]; answer = (answer*findpower(arr[i],power))%modulo; }
    // result
    cout<<answer<<endl;
  }
  return 0;
}
