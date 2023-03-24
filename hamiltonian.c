#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

int n;
int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
bool visited[MAX_VERTICES];

void printCycle() {
    for (int i = 0; i < n; i++) 
        printf("%d ", path[i]+1);
    printf("%d\n", path[0]+1);
}

void backtrack(int pos) {
    if (pos == n)
    {
        // Check if the last vertex is adjacent to the first vertex
        if (graph[path[n-1]][path[0]]) {
            printCycle();
        }
        return;
    }
    for (int i = 1; i < n; i++) 
    {
        if (!visited[i] && graph[path[pos-1]][i]) 
        {
            visited[i] = true;
            path[pos] = i;
            backtrack(pos+1);
            visited[i] = false;
        }
    }
}

void findHamiltonianCycles() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    path[0] = 0;
    visited[0] = true;
    backtrack(1);
}

int main() {
    printf("\n enter the no of vertices...");
    scanf("%d", &n);
    printf("\n enter the graph info...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n Hamiltonian cycles possible are....\n");
    findHamiltonianCycles();
    return 0;
}
