#include<stdio.h>
#include<stdlib.h>

 struct Node{
    int vertex;
    struct Node* next;
};

struct Graph{
    int numvertices;
    struct Node** adjLists;
};

struct Node* createNode(int vetex){
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> vertex = vetex;
    newNode -> next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest){
    struct Node* newNode = createNode(dest);
    newNode -> next = graph -> adjLists[src];
    graph -> adjLists[src] = newNode;

    newNode = createNode(src);
    newNode -> next = graph -> adjLists[dest];
    graph -> adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph){
    int v;
    for(v=0;v<graph->numvertices;v++){
        struct Node* temp = graph->adjLists[v];
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("null\n");
    }
}

int main(){
    int vertices = 5;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> numvertices = vertices;
    graph -> adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for(int i = 0; i<vertices;i++){
        graph -> adjLists[i] = NULL;
    }
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
