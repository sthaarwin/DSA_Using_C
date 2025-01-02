#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void addEdge(int start, int end) {
    adj[start][end] = 1;
    adj[end][start] = 1; // For undirected graph
}

void DFS(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void BFS(int start, int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 6; // Number of vertices

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0, n);
    printf("\n");

    printf("BFS Traversal: ");
    BFS(0, n);
    printf("\n");

    return 0;
}