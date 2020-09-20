#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef unsigned long long int ull;

int main() {
  ull q,l,r,temp,answer;
  vector<int> arr(100000,-1);
  int count,t;
  cin>>t;
  while(t--){
    cin>>q;
    while(q--){
      cin>>l>>r;
      if(l > r) swap(l,r);
      answer = 0;
      for(ull i = l;i <= r;i++){
        temp = i; count = 0;
        if(temp < 100000 && arr[temp] != -1) { if(arr[temp] < 4) answer++; continue; }
        while(temp && count < 3){
          if(temp & 1) count++; temp >>= 1;
          if(temp < 100000 && arr[temp] != -1) { count += arr[temp]; break; }
        }
        if(count < 4) answer++;
        if(i < 100000) arr[i] = count;
      }
      cout<<answer<<endl;
    }
  }
	return 0;
}
