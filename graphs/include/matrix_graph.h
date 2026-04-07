#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
        int num_vertices;
        int** adj_matrix;
} Graph;

Graph* graph_create(int num_vertices);
Graph* graph_destroy(Graph* g);
int graph_bfs(Graph* g, int start_vertex, int* visited);
int graph_dfs(Graph* g, int start_vertex, int* visited);

#endif