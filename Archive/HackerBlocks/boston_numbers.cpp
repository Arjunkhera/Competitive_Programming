#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef long long int ll;
ll check;

void factorize(ll n,vector<ll> &num,vector<ll> &power){

  ll count = 0;
  num.push_back(2);
  while(n%2==0){
    count++;
    n/=2;
  }
  power.push_back(count);

  for(ll i=3;i<=sqrt(n);i+=2){
    count=0;
    while(n%i == 0){
      count++;
      n/=i;
    }
    if(count){
      //cout<<i<<" ";
      num.push_back(i);
      power.push_back(count);
    }
  }

  if(n > 2 and n!=check){
    num.push_back(n);
    power.push_back(1);
  }
}

int main(){
  ll l,sum,fac_sum,temp,temp_count;
  cin>>l;
  check = l;
  vector<ll>num;
  vector<ll>power;
  factorize(l,num,power);
  //cout<<endl;

  fac_sum = 0;
  vector<ll>::iterator i = num.begin();
  vector<ll>::iterator j = power.begin();
  while(i!= num.end()){

    temp = *i;
    temp_count = 0;
    while(temp){
      temp_count += temp%10;
      temp/=10;
    }
    fac_sum += (temp_count)*(*j);
    i++;
    j++;
  }

  sum = 0;
  while(l){
    sum += l%10;
    l/=10;
  }

  if(sum == fac_sum)
    cout<<"1\n";
  else cout<<"0\n";

  return 0;
}
