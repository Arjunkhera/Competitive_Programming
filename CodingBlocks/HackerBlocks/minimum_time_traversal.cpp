#include<iostream>
#include<vector>
using namespace std;

int n;
int end_x,end_y;

int solve(int x1,int y1,vector<pair<int,int>> &pipe_one,vector<pair<int,int>> &pipe_two,vector<int> &time_taken,vector<bool> visited){

  int travel_time = abs(end_x-x1)+abs(end_y-y1);
  int dist_1,dist_2,temp_time;
  for(int i=0;i<n;i++){
    if(visited[i])
      continue;

    visited[i] = true;
    temp_time = time_taken[i];
    dist_1 = abs(pipe_one[i].first-x1)+abs(pipe_one[i].second-y1);
    dist_2 = abs(pipe_two[i].first-x1)+abs(pipe_two[i].second-y1);

    if(dist_1 < dist_2){
      temp_time += dist_1 + solve(pipe_two[i].first,pipe_two[i].second,pipe_one,pipe_two,time_taken,visited);
    }
    else {
      temp_time += dist_2 + solve(pipe_one[i].first,pipe_one[i].second,pipe_one,pipe_two,time_taken,visited);
    }
    travel_time = min(travel_time,temp_time);
    // backtrack
    visited[i] = false;
  }

  return travel_time;
}

int main(){
  int t,x,y,x1,y1,x2,y2,travel_time,j=1;
  cin>>t;

  vector<pair<int,int>> pipe_one;
  vector<pair<int,int>> pipe_two;
  vector<int> time_taken;
  vector<bool> visited;
  while(j<=t){
    cin>>n;
    cin>>x>>y;
    cin>>end_x>>end_y;

    for(int i=0;i<n;i++){
      cin>>x1>>y1;
      cin>>x2>>y2;
      cin>>travel_time;

      pipe_one.push_back(make_pair(x1,y1));
      pipe_two.push_back(make_pair(x2,y2));
      time_taken.push_back(travel_time);
      visited.push_back(false);
    }

    cout<<"#"<<j<<" : "<<solve(x,y,pipe_one,pipe_two,time_taken,visited)<<"\n";

    pipe_one.clear();
    pipe_two.clear();
    time_taken.clear();
    visited.clear();
    j++;
  }
  return 0;
}
