#include<iostream>
#include<vector>

#define maxrange 100005

using namespace std;

int main(){
  long int n,answer = 0; cin>>n;
  vector<long int> arr(n),distinct(n);
  vector<bool> visited(maxrange,false);

  cin>>arr[0]; distinct[0] = 1; visited[arr[0]] = true;
  for(long int i = 1;i < n;i++){
    cin>>arr[i];
    if(!visited[arr[i]]){
      visited[arr[i]] = true;
      distinct[i] = distinct[i-1]+1;
    }
    else distinct[i] = distinct[i-1];
  }
  for(long int i = 0;i < maxrange;i++) visited[i] = false;
  for(long int i = n-1;i > 0;i--){
    if(visited[arr[i]]) continue;
    answer += distinct[i-1];
    visited[arr[i]] = true;
  }
  cout<<answer;
  return 0;
}

/*
5
1 5 4 1 3
----------------
7
1 2 1 1 1 3 2
*/
/*

// Cerberus97
// Hanit Banga


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int a[N], occ[N];
bool seen[N];

int main() {
	int n; cin >> n;
	int ctr = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		occ[a[i]]++;
		if (occ[a[i]] == 1) {
			++ctr;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		--occ[a[i]];
		if (occ[a[i]] == 0) {
			--ctr;
		}
		if (!seen[a[i]]) {
			seen[a[i]] = true;
			ans += ctr;
		}
	}
	cout << ans;
}
*/
