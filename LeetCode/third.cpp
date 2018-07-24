#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long int li;

int solve(vector<int> &A, int B) {
    if(A.empty()) return 0;

    long int n = A.size();
    stack<int> stk;

    vector<int> largest(n,-1);
    stk.push(0);
    for(int i = 1;i < n;i++){
        while(!stk.empty() && A[stk.top()] < A[i]){
            largest[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();

    vector<int> smallest(n,-1);
    stk.push(0);
    for(int i = 1;i < n;i++){
        while(!stk.empty() && A[stk.top()] > A[i]){
            smallest[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();

    for(auto i:smallest) cout<<i<<":"; cout<<endl;
    for(auto i:largest) cout<<i<<":"; cout<<endl;

    long int answer = 1,i = 1,j = 0;
    pair<long int,long int> curmax,curmin;
    curmax.first = A[0]; curmax.second = 0;
    curmin.first = A[0]; curmin.second = 0;

    for(auto m:A) cout<<m<<":"; cout<<endl;
    while(i < n && j <= i){
        // no need to make changes, move ahead
        if(A[i] >= curmin.first && A[i] <= curmax.first){
          if(i-j+1 >= answer){
            cout<<" j : "<<A[j]<<" i : "<<A[i]<<" answer "<<answer<<endl;
            answer = i-j+1;
            cout<<" j is : "<<j<<" i is : "<<i<<" answer "<<answer<<endl;
          }
          //answer = max(answer,i-j+1);
          i++; continue;
        }

        if(A[i] > curmax.first){
            curmax.first = A[i]; curmax.second = i;
            if(A[i] - curmin.first < B) continue;
            j = curmin.second;
            while(j <= i && j != -1) j = largest[j];
            if(j > i || j == -1 || abs(A[i] - A[j]) > B) j = i;
            curmin.first = A[j]; curmin.second = j; continue;
        }

        curmin.first = A[i]; curmin.second = i;
        if(curmax.first - A[i] < B) continue;
        j = curmax.second;
        while(j <= i && j!= -1) j = smallest[j];
        if(j > i || j == -1 || abs(A[i] - A[j]) > B) j = i;
        curmax.first = A[j]; curmax.second = j;
    }
    cout<<answer<<"\n";
    return answer;
}

int main(){

  vector<int> arr;

  int temp; cin>> temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  cin>>temp;
  cout<<solve(arr,temp)<<endl;
  return 0;
}

/*

*/
