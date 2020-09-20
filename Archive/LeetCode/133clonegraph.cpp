#include<iostream>
#include<vector>

using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(){};
  UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

}

int main(){
  string str;
  getline(cin,str);

  int E,V = 1;
  for(auto i:str) if(i == '#') V++;

  UndirectedGraphNode *graph = new UndirectedGraphNode[V];
  for(int i = 0;i < V;i++) graph[i].label = i;

  int src = str[0]-48,i = 1;
  while(i < str.length()){
    if(str[i] == '#'){ i++; src = str[i]-48; }
    else if(str[i] != ','){
      graph[src].neighbors.push_back(&graph[str[i]-48]);
    }
    i++;
  }

  cout<<endl;
  for(int i = 0;i < V;i++){
    cout<<i<<" { ";
    for(int k = 0; k < graph[i].neighbors.size();k++) cout<<graph[i].neighbors[k]->label<<" ";
    cout<<" } \n";
  }

  return 0;
}

/*
0,1,2#1,2#2,2
*/
