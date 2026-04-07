#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

typedef struct node {
        int vertex;
        struct node* next;
} Node;

typedef struct graph {
        int num_vertices;
        Node** adj_list;
} Graph;

Graph* graph_create(int num_vertices);
Graph* graph_destroy(Graph* g);
int graph_bfs(Graph* g, int start_vertex, int* visited);
int graph_dfs(Graph* g, int start_vertex, int* visited);

#endif