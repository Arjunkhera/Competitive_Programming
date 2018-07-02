#include<iostream>
#include<vector>

using namespace std;

long minimumSum(vector<int> &l, vector<int> &r){
    // Return the minimum sum among all arrays that satisfy the condition.

    long int n = l.size();
    int curpos,curmin = l[0],curmax = r[0];
    long int answer = 0;
    vector<pair<int,int>> ranges;
    long int i = 1;

    while(i < n){
       if(curmax < l[i] || curmin > r[i]){
           ranges.emplace_back(curmin,curmax);
           curmin = l[i]; curmax = r[i];
           i++;
           continue;
       }
       curmax = min(curmax,r[i]); curmin = max(curmin,l[i]);
       i++;
    }
    ranges.emplace_back(curmin,curmax);
    if(ranges.size() == 1) return 0;

    cout<<"---\n";
    for(auto k : ranges) cout<<k.first<<" : "<<k.second<<endl;
    cout<<"---\n";

    if(ranges[1].first > ranges[0].second)
      curpos = ranges[0].second;
    else curpos = ranges[0].first;

    for(int j = 1;j < ranges.size();j++){
        if(ranges[j].first > curpos){
            answer += abs(ranges[j].first - curpos);
            curpos = ranges[j].first;
        }
        else{
            answer += abs(ranges[j].second - curpos);
            curpos = ranges[j].second;
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

  cout<<minimumSum(left,right)<<endl;
  return 0;
}

/*
1 2 6 1 2 -100
3 5 8 2 3 -100
*/
