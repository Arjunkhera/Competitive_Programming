#include<iostream>
#include<list>

using namespace std;

class vertex;

class graph
 {
  list<vertex> adjacency_list;
  int nodes;

  public :
  graph(int nodes);
  bool add_edge();
  bool add_vertex();
  bool remove_edge();
  bool remove_vertex();
 };

graph::graph(int nodes=0)
 {
   this->nodes = nodes;

   for(int i=0;i<nodes;i++)
    {
      vertex v(i);
      adjacency_list.push_back(v);
    }
 }

bool graph::add_edge(int src,int dest)
 {
   for (auto i:adjacency_list)
    if (i.id = src)
      {
        vertex v(dest);
        i.node.push_back(v);
      }

   return true;
 }

bool graph::add_vertex(int id)
 {
   vertex v(id);
   adjacency_list.push_back(v);

   return true;
 }

class vertex
 {
  list<int> node;
  int id;
  public :
  vertex(int);
 };

vertex::vertex(int id)
 {
  this->id=id;
 }

int main()
{
  graph g();
  return 0;
}
