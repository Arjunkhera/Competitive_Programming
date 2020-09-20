#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

// solution function
string convertToTitle(int n){
  string answer;
  while(n) { n--; answer.push_back(65+(n%26)); n /= 26; }
  reverse(answer.begin(),answer.end());
  return answer;
}

// driver function
int main(){
  int n; cin>>n;
  cout<<convertToTitle(n)<<endl;

  return 0;
}
