// author Shubhankar Agarwal

/*
This program creates a graph, which contains v vertex pointing to each other as defined by the user . 
*/
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////
// Structures //
typedef struct graph
{
  int n;   // number of roomates
  struct vertex vertexT[];
  struct vertex *startnode; // starting node of the graph
  struct vertex *lastnode; // last node of the graph

}

typedef struct edge
{
    int id ;
    struct edge vertex; // egde pointing to the other edge
    struct edge* next;   // pointer to the next vertex
}

typedef struct vertex
{ int id ;
  bool is_visited;     // check if vertex is visited or not
  bool is_reachable;   // is rechable by any other vertex
  struct vertex* next;

} vertex;
/////////////////////////////////////////////////////////////
// Functions //
struct vertex* Addvertex( int id )
{
    vertex* newVertex = (vertex*) malloc(sizeof(vertex));
    newVertex->id = id;
    newVertex->next = NULL;
    return newVertex;
}

struct edge* graphAddEdge( int id )
{
  edge* newEdge = (edge*) malloc(sizeof(edge));
  newEdge->id = id;
  newEdge->next = NULL:
  return newEdge;
}

graph* make_graph( int v)
{
    graph* graphT = (graph *) malloc (sizeof(graph));


    for (int i = 0; i < v ; i++)
    {
    graph->vertexT[i] = (vertex*) malloc(sizeof(vertex));
    }

    graphT->startnode = vertex[0];
    return graphT;
}

void addEdge(graph *graph , int )
