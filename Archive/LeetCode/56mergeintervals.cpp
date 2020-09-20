#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Interval{
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a,Interval b){
  return (a.start < b.start )?1:0;
}

vector<Interval> merge(vector<Interval>& intervals) {

  vector<Interval> answer;

  if(intervals.empty())
    return answer;

  sort(intervals.begin(),intervals.end(),compare);

  /*
  for(int k = 0;k < intervals.size();k++)
    cout<<intervals[k].start<<" "<<intervals[k].end<<endl;
  */

  int i = 0;
  int j = 1;
  while(j < intervals.size()){

    // no merging
    if(intervals[j].start > intervals[i].end){
      i++;
      intervals[i].start = intervals[j].start;
      intervals[i].end = intervals[j].end;
      j++;

      continue;
    }

    if(intervals[j].end > intervals[i].end)
      intervals[i].end = intervals[j].end;

    j++;
  }

  for(int k = 0;k <= i;k++)
   answer.push_back(intervals[k]);

  return answer;
}

int main(){

  int temp;
  cin>>temp;
  cout<<endl;

  vector<Interval> arr(temp);
  while(temp){
    cin>>arr[temp-1].start>>arr[temp-1].end;
    temp--;
  }

  vector<Interval> answer = merge(arr);

  for(int i=0;i<answer.size();i++)
    cout<<answer[i].start<<" "<<answer[i].end<<endl;

  return 0;
}
