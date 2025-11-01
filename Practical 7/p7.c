#include <stdio.h>

#define V 5

int isSafe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int solveHamiltonian(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        return 0;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (solveHamiltonian(graph, path, pos + 1) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void printSolution(int path[], char names[]) {
    printf("Hamiltonian Cycle found:\n");
    for (int i = 0; i < V; i++)
        printf("%c -> ", names[path[i]]);
    printf("%c\n", names[path[0]]);
}

void hamiltonianCycle(int graph[V][V], char names[]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;

    if (solveHamiltonian(graph, path, 1) == 0)
        printf("No Hamiltonian Cycle exists\n");
    else
        printSolution(path, names);
}

int main() {
    int graph1[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    char names1[] = {'A', 'B', 'C', 'D', 'E'};

    int graph2[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };
    char names2[] = {'T', 'M', 'S', 'H', 'C'};

    printf("Graph 1 (Areas A–E):\n");
    hamiltonianCycle(graph1, names1);

    printf("\nGraph 2 (Areas T–C):\n");
    hamiltonianCycle(graph2, names2);

    return 0;
}
