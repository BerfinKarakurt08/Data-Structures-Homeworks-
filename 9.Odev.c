#include <stdio.h>
#define MAX 5

int graph[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0}
};

int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
 if (rear == MAX - 1) return;
    if (front == -1) front = 0;
        queue[++rear] = vertex;
}

int dequeue() {

if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int i = 0; i < MAX; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
     }
}

void BFS(int startVertex) {
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    front = -1; 
    rear = -1;
    
    printf("%d ", startVertex);
    visited[startVertex] = 1;
    enqueue(startVertex);
    
    while (front <= rear && front != -1) {
        int currentVertex = dequeue();
        
        for (int i = 0; i < MAX; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
              }
          }
       }
    }

int main() {
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");
    printf("BFS Traversal: ");
    BFS(0);
    printf("\n");
    
     return 0;
 }
