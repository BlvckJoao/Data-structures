#include <stdio.h>
#include <stdlib.h>
#include "include/matrix_graph.h"
#include "../stacks_queues/include/stack.h"
#include "../stacks_queues/include/queue.h"

Graph* graph_create(int num_vertices) {
        if (num_vertices <= 0) return NULL;

        Graph* g = (Graph*)malloc(sizeof(Graph));
        if (!g) return NULL;

        g->num_vertices = num_vertices;
        g->adj_matrix = (int**)malloc(num_vertices * sizeof(int*));
        if (!g->adj_matrix) {
                free(g);
                return NULL;
        }

        for (int i = 0; i < num_vertices; i++) {
                g->adj_matrix[i] = (int*)calloc(num_vertices, sizeof(int));
                if (!g->adj_matrix[i]) {
                        for (int j = 0; j < i; j++) free(g->adj_matrix[j]);
                        free(g->adj_matrix);
                        free(g);
                        return NULL;
                }
        }

        return g;
}

Graph* graph_destroy(Graph* g) {
        if (!g) return NULL;

        for (int i = 0; i < g->num_vertices; i++) {
                free(g->adj_matrix[i]);
        }
        free(g->adj_matrix);
        free(g);
        return NULL;
}

int graph_bfs(Graph* g, int start_vertex, int* visited) {
        if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return -1;

        Queue* q = queue_create();
        int visitado[MAX] = {0};

        visitado[start_vertex] = 1;
        queue_enqueue(q, start_vertex);

        while (!queue_is_empty(q)) {
                int v = queue_dequeue(q);
                printf("%d ", v);
                for cada vizinho u de v:
                        if (!visitado[u]) {
                                visitado[u] = 1;
                                queue_enqueue(q, u);  
                        }
        }
        return 0;
}

int graph_dfs(Graph* g, int start_vertex, int* visited) {
        if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return -1;

        Stack* s = stack_create();
        int visitado[MAX] = {0};

        visitado[start_vertex] = 1;
        stack_push(s, start_vertex);

        while (!stack_is_empty(s)) {
                int v = stack_pop(s);
                printf("%d ", v);
                for cada vizinho u de v:
                        if (!visitado[u]) {
                                visitado[u] = 1;
                                stack_push(s, u);  
                        }
        }
        return 0;
}