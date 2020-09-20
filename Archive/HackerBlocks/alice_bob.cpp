#include<iostream>
#include<vector>

using namespace std;
typedef long long int ll;

int main(){
  ll n,temp,m=1;
  cin>>n;

  ll values[100005]={0};
  for(ll i=0;i<n;i++){
    cin>>temp;
    values[temp]+=1;
  }

  // obtain elements and their frequencies
  vector<ll>arr;
  vector<ll>frequencies;
  arr.push_back(0);
  frequencies.push_back(0);
  for(ll i=1;i<100003;i++)
    if(values[i]){
      arr.push_back(i);
      frequencies.push_back(values[i]);
      m++;
    }

  // solve
  if(m==2){
    cout<<arr[1]*frequencies[1]<<endl;
  }
  else{
  for(ll i=2;i<m;i++){
    if(arr[i] != arr[i-1]+1){
      frequencies[i] = frequencies[i-1]+arr[i]*frequencies[i];
      continue;
    }
    temp = frequencies[i-2]+frequencies[i]*arr[i];
    frequencies[i] = max(temp,frequencies[i-1]);
  }
  cout<<frequencies[m-1]<<endl;
  }

  return 0;
}

/*
//display
for(ll i=0;i<m;i++)
  cout<<arr[i]<<" "<<frequencies[i]<<endl;
*/
