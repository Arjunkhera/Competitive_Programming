#include<iostream>
#include<map>
#include<cmath>
#include<climits>

using namespace std;

typedef long long int ll;
map<ll,ll> factors;
int answer;

void solve(ll n,ll k){

  ll lowest=INT_MAX,minimum;
  ll factor,temp;
  map<ll,ll>::iterator i = factors.begin();
  while(i != factors.end()){
    minimum = 0;
    factor = i->first;
    temp = n;
    while(temp){
      minimum += temp/factor;
      temp /= factor;
    }
    minimum = (minimum/i->second);

    if(minimum < lowest)
      lowest = minimum;

    i++;
  }

  answer = lowest;
}

void factorize(ll n){
  while(n%2 == 0){
    factors[2]++;
    n = n/2;
  }

  for(ll i = 3; i <= sqrt(n); i = i+2){
    if(n%i==0)
      factors[i] = 0;

    while(n%i == 0){
      factors[i]++;
      n = n/i;
    }
  }

  if(n > 2)
    factors[n] = 1;
}

int main(){
  ll t,n,k;
  cin>>t;

  while(t--){
    cin>>n>>k;
    factorize(k);
    solve(n,k);
    factors.clear();
    cout<<answer<<endl;
  }

  return 0;
}
