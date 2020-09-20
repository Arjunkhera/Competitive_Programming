#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int main(){
  long int t;
  cin>>t;
  while(t--){
    string str; cin>>str;
    long int answer = 0, n = str.length(),tempsum,delta,curpos;
    vector<int> right(26,0); vector<int> left(26,0); vector<vector<int>> cumsum(26,vector<int>(2,0));

    // right to left : no modifications
    for(long int i = n-1;i >= 0;i--){
      curpos = str[i]-97; tempsum = 0;
      for(int j = curpos+1;j < 26;j++) tempsum += right[j];
      right[curpos]++; answer += tempsum;
    }
    tempsum = INT_MAX;
    // left to right : does modification increase score ?
    for(long int i = 0;i < n;i++){
      curpos = str[i]-97; right[curpos]--;
      cumsum[0][0] = left[0]; cumsum[0][1] = right[0];
      for(int j = 1;j < 26;j++){
        cumsum[j][0] = cumsum[j-1][0] + left[j];
        cumsum[j][1] = cumsum[j-1][1] + right[j];
      }
      if(curpos == 0){
        for(int j = curpos+1;j < 26;j++){
          delta = (j-curpos) + cumsum[j-1][0] - (cumsum[j][1] - cumsum[curpos][1]);
          tempsum = min(tempsum,delta);
        }
      }
      else{
        delta = curpos - cumsum[curpos-1][0] + (cumsum[curpos][1] - cumsum[0][1]);
        tempsum = min(tempsum,delta);
        for(int j = 1;j < curpos;j++){
          delta = (curpos-j) - (cumsum[curpos-1][0] - cumsum[j-1][0]) + (cumsum[curpos][1] - cumsum[j][1]);
          tempsum = min(tempsum,delta);
        }
        for(int j = curpos+1;j < 26;j++){
          delta = (j-curpos) + (cumsum[j-1][0] - cumsum[curpos-1][0]) - (cumsum[j][1] - cumsum[curpos][1]);
          tempsum = min(tempsum,delta);
        }
      }
      left[curpos]++;
    }
    answer = min(answer,answer+tempsum);
    cout<<answer<<"\n";
  }
  return 0;
}

/*
3
abcd
dbca
dcba
*/
