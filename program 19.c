#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    push(v);
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, n);

    printf("\nTopological Sort (DFS): ");
    while (top != -1)
        printf("%d ", stack[top--]);

    printf("\n");
    return 0;
}

