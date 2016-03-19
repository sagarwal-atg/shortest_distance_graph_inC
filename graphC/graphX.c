#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 5

int newmin = 0, min = -1; // initially the distance is infinite


struct vertex {
   int id;
    int con;
    int next[N];
    int isreachable;
    int isvisited;
};

struct vertex_array
{
  int arr_num;
  struct vertex *element;
};
struct graph
{
  int ver_num;
  struct vertex_array *graph_arr;
};

///////////////////////////////////////////////////////

struct vertex* createnode(int id)
{
  struct vertex *vertexT = (struct vertex*)malloc(sizeof(struct vertex));

  vertexT->id = id;
  vertexT->con = 0;
  for(int i = 0; i < (N) ; i++){
  vertexT->next[i] = -1;}
  vertexT->isreachable = 1;
  vertexT->isvisited = 0;
  return vertexT;
}

struct graph* creategraph(int num )
{
  struct graph *graphT = (struct graph*)malloc(sizeof(struct graph));
  graphT->ver_num = num;

  graphT->graph_arr = (struct vertex_array*)malloc(num* sizeof(struct vertex));

  for (int i = 0 ; i < num ; i++)
  {
    graphT->graph_arr[i].element = createnode(i);
  }
 return graphT;
}

void addConnection(struct graph* graphT,  int start ,int end , int start_in , int end_in )
{
  // Add edge from start to end. A new vertex is cretaed pointing to the start
  // Since the graph is undirected add an egde from end to start
   graphT->graph_arr[start].element->next[start_in] = graphT->graph_arr[end].element->id;
   graphT->graph_arr[end].element->next[end_in] = graphT->graph_arr[start].element->id;
   graphT->graph_arr[start].element->con = graphT->graph_arr[start].element->con + 1;
   graphT->graph_arr[end].element->con = graphT->graph_arr[end].element->con + 1;
}
//a function to print the graph
void printgraph(struct graph *graphT)
{
  for (int v = 0 ; v < graphT->ver_num ; v++)
  {  int ver_num = 0;
    int k=0;
    //ver_num = graphT->graph_arr[v].element->next[k];
    printf("\n All the connection of vertex %d are\n", v);
    while( ver_num != -1 && k < N )
    {
      ver_num = graphT->graph_arr[v].element->next[k];
      if(ver_num != -1)
      printf("\tconnection %d : %d\n",k, ver_num);

      k++;
    }
    printf("\n" );
  }
}

//This function finds the shortest distance between two nodes

  int shortestdist(struct graph *graphT , int start , int end)
  {

     int neigh_id = start;
     if( neigh_id == end){
     return 0;}

    struct vertex* vcrawl = graphT->graph_arr[start].element;
      int k = 0;


      while(vcrawl->next[k] != -1  && graphT->graph_arr[start].element->isvisited == 0  )

      {  neigh_id  = vcrawl->next[k];


        graphT->graph_arr[start].element->isvisited = 1;

        printf(" min = %d newmin = %d\n", min , newmin  );
        if(min == -1 && (graphT->graph_arr[neigh_id].element->isvisited != 1)){

          graphT->graph_arr[neigh_id].element->isvisited = 1;
          min = shortestdist(graphT , neigh_id, end);
          printf("yo %d\n",min );
          //graphT->graph_arr[neigh_id].element->isvisited = 0;
          min = min + 1;
        }
        else
        { graphT->graph_arr[neigh_id].element->isvisited = 1;
          newmin = shortestdist(graphT , neigh_id , end);
          //graphT->graph_arr[neigh_id].element->isvisited = 0;

          newmin = newmin + 1;
          if( newmin < min )
          {
            min = newmin;
          }
        }

          printf("%d -> ", neigh_id);
        k++;
      }
      return min;
}
//
// ////////////////////////////////////////////////////////////////////////
//
int main()
{
    // create the graph given in above fugure
    int V = 6;
    struct graph* graphT = creategraph(V);

    printf("The number of vertices in the graph are %d\n", graphT->ver_num );
    addConnection(graphT, 0, 1, 0, 0);
    addConnection(graphT, 0, 3, 1, 0);
    addConnection(graphT, 1, 2, 1, 0);
    addConnection(graphT, 1, 5, 2, 0);
    addConnection(graphT, 3, 2, 1, 1);
    addConnection(graphT, 3, 4, 2, 0);
    addConnection(graphT, 2, 5, 2, 1);
    addConnection(graphT, 4, 5, 1, 2);
   // print the adjacency list representation of t he above graph
 printgraph(graphT);
int min = 0 , start = 0 , end = 4;
min = shortestdist(graphT , start , end);
printf("The shortest distance between the vertex %d and %d is %d \n", start , end , min );
  return 0;

}
