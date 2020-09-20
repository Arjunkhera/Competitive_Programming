#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}

int main(){

  vector<int> arr{1,2,3,7,7};
  cout<<minSubArrayLen(5,arr)<<endl;

  return 0;
}


/*
int main() {
    long int t,initial,final,n;
    cin>>t;

    while(t--){
     cin>>initial>>final;
     cin>>n;
     vector<int> arr(n);
     for(int i = 0;i < n;i++) cin>>arr[i];
     sort(arr.begin(),arr.end());

     if(initial > final) swap(final,initial);
     int diff = min(final-initial,1000-final+initial);

     vector<vector<int>> dp(n+1,vector<int>(diff+1,0));
     for(int i = 0;i <= diff;i++) dp[0][i] = INT_MAX;

     for(int i = 1;i <= n;i++)
         for(int j = 1;j <= diff;j++)
             if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
             else dp[i][j] = min(dp[i-1][j],1+dp[i][j-arr[i-1]]);
     cout<<dp[n][diff]<<endl;
    }
	return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	cin>>t;

	while(t--){
	    cin>>n;
	    vector<int> arr(n,0);
	    for(int i = 0;i < n;i++) cin>>arr[i];

	    if(n == 1) { cout<<arr[0]<<endl; continue; }

	    vector<int> sums(n,0);
	    sums[0] = arr[0];
	    for(int i = 1;i < n;i++) sums[i] = sums[i-1] + arr[i];
	    int rightsum = sum[n-1] - arr[0];
	    for(int i = 1;i < n-1;i++){
	        rightsum -= arr[i];
	        if(sums[i-1] == rightsum) break;
	    }
	    if(i == n) cout<<"-1\n";
	    else cout<<arr[i]<<endl;
	}

	return 0;
}
*/
