#include<iostream>
#include<string>
#include<set>

using namespace std;
typedef long long int ll;

set<string> locker;

bool issafe(){

}

ll permutations(ll *arr,string str,int index,int numk,int sum){
  if(arr[numk]!=-1)
    return arr[numk];

  if(index == str.length()-1 ){
    locker.insert(str);
    return;
  }

  for(int i=index;i<str.length();i++){
    swap(str[index],str[i]);
    permutations(str,index+1);
    // backtrack : to ensure we get all permutations
    swap(str[i],str[index]);
  }
}

ll solve(int n,int k){
  if(k>=n)
    return 0;

  ll *arr = new ll[2*k+1];
  for(int i=0;i<=2*k;i++)
    arr[i] = -1;

  ll sum = 0;
  for(int i=1;i<k+1;i++){
    if(i+k > n)
      break;

    string one(i+k,'1');
    string zero(n-i-k,'0');
    string str = one+zero;

    sum += permutations(arr,str,0,i+k,k);
    locker.clear();
  }
  return sum;
}

int main(){
  int t,n,k;
  cin>>t;

  while(t--){
      cin>>n>>k;
      cout<<solve(n,k)<<"\n";
  }
  return 0;
}
