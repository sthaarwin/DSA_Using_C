#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int numVertices;
    int** adjMatrix;
};

struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> numVertices = vertices;
    graph -> adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for(int i = 0; i<vertices;i++){
        graph -> adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for(int j = 0; j<vertices;j++){
            graph -> adjMatrix[i][j] = 0;
        }
    }
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest){
    graph -> adjMatrix[src][dest] = 1;
    graph -> adjMatrix[dest][src] = 1;//for undirected graph
}

void printGraph(struct Graph* graph){
    int v, e;
    for(v=0;v<graph->numVertices;v++){
        for(e=0;e<graph->numVertices;e++){
            printf("%d ", graph->adjMatrix[v][e]);
        }
        printf("\n");
    }
}
int main(){
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printf("Original Graph : \n");
    printGraph(graph);
    return 0;
}