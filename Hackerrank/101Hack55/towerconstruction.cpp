#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool mycompx(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool mycompy(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

// Complete the fewestTowers function below.
long fewestTowers(vector<int> x, vector<int> y) {
    // Return the minimum number of towers that need to be constructed so that the condition is satisfied.

    vector<pair<int,int>> xy,yx;
    int n = x.size(); long int answer = 0;
    for(int i = 0;i < n;i++) {
        xy.emplace_back(x[i],y[i]);
        yx.emplace_back(x[i],y[i]);
    }

    sort(xy.begin(),xy.end(),mycompx);
    int i = 0;
    pair<int,int> cur;
    while(i < n){
        cur = xy[i]; i++;
        while(i < n && cur.first == xy[i].first){
            for(int j = cur.second+1; j < xy[i].second; j++){
                yx.emplace_back(cur.first,j);
                answer++;
            }
            cur.second = xy[i].second;
            i++;
        }
    }

    sort(yx.begin(),yx.end(),mycompy);
    i = 0;
    while(i < n){
        cur = yx[i]; i++;
        while(i < n && cur.second == yx[i].second){
            for(int j = cur.first+1; j < yx[i].first; j++) answer++;
            cur.first = yx[i].first;
            i++;
        }
    }
    return answer;
}

int main(){
  int temp;
  vector<int> left,right;
  cin>>temp;
  while(temp != -100) { left.push_back(temp); cin>>temp; }

  cin>>temp;
  while(temp != -100) { right.push_back(temp); cin>>temp; }

  cout<<fewestTowers(left,right)<<endl;
  return 0;
}

/*
-1 0 0 0 1 -1 -1 1 0 -2 -100
2 0 2 3 3 3 1 0 1 2 -100
------------------------------------
1 1 2 3 3 3 -100
2 1 1 1 2 3 -100
*/
