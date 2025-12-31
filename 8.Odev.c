#include <stdio.h>
#define V 6

int graph[V][V] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

int visited[V];

void DFS(int startNode) {
    visited[startNode] = 1;
    printf("%d ", startNode);

    for(int i = 0; i < V; i++) {
        if(graph[startNode][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
     }
   }

int main() {
    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }
  int clusterCount = 0;

  printf("Clusters:\n");
   for(int i = 0; i < V; i++) {
        if(visited[i] == 0) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            DFS(i);
            printf("}\n");
         }
      }
    printf("Total Clusters: %d\n", clusterCount);

    return 0;
 }

