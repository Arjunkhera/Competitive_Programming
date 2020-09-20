// Adjacency List Representation 

#include<iostream>
#include<vector>

using namespace std;

void addedge(vector<vector<int>> &graph,int source,int destination){
  graph[source].push_back(destination);
}

void addedgeweighted(vector<vector<pair<int,int>>> &graph,int source,int destination,int weight){
  graph[source].emplace_back(destination,weight);
}

void dfshelper(vector<vector<int>> &graph,int cur,vector<bool> &visited){
  visited[cur] = true;
  cout<<cur<<":";
  for(int i = 0;i < graph[cur].size();i++)
    if(!visited[graph[cur][i]]) dfshelper(graph,graph[cur][i],visited);
}

void dfs(vector<vector<int>> &graph){
  vector<bool> visited(graph.size());
  for(int i = 0;i < graph.size();i++)
    if(!visited[i]) dfshelper(graph,i,visited);
}

int main(){
  int V,E,src,dest;
  cin>>V>>E;

  vector<vector<int>> graph(V);
  for(int i = 0;i < E;i++){
    cin>>src>>dest;
    addedge(graph,src,dest);
  }

  return 0;
}
