#include <stdio.h>
#include <stdlib.h>
#define INFI 99

//  edges[10][10]  stores MST edges, wt[10][10] is Cost adjacency matrix, n is Number of vertices
int edges[10][10], n, wt[10][10];


void prims() {

// u[i] is Parent vertex through which minimum cost is obtained, lowcost[i] is Minimum cost edge connecting vertex i to MST and visited[i] is Whether vertex i is in MST
    int u[10], lowcost[10], visited[10];
    int min, mincost = 0, i, j, v;
    visited[1] = 1;     //start MST from vertex 1

// Initially MST contains only vertex 1. For every other vertex: Parent = 1, Cost = edge from vertex 1

    for(i = 2; i <= n; i++) {
        visited[i] = 0;
        u[i] = 1;
        lowcost[i] = wt[1][i];
    }


    for(i = 1; i <= n - 1; i++) {
        min = lowcost[2];  //Assume vertex 2 is minimum initially
        v = 2;

//Search all vertices not yet included. Choose vertex with smallest connection cost
        for(j = 3; j <= n; j++) {
            if(lowcost[j] < min) {
                min = lowcost[j];
                v = j;
            }
        }

// Add Edge to MST
        edges[i][1] = u[v];
        edges[i][2] = v;

//Add edge weight to MST cost
        mincost += lowcost[v];

//Include vertex in MST
        visited[v] = 1;

//Mark vertex as processed
        lowcost[v] = INFI;

//Update Costs: After adding vertex v, Check whether going through v gives a cheaper connection. If yes, Update lowcost and u
        for(j = 2; j <= n; j++) {
            if(wt[v][j] < lowcost[j] && !visited[j]) {
                lowcost[j] = wt[v][j];
                u[j] = v;
            }
        }
    }

//display MST and Total weight
    printf("Edges of Minimum Spanning Tree:\n");
    for(i = 1; i <= n - 1; i++)
        printf("(%d %d) ", edges[i][1], edges[i][2]);
    printf("\nMinimum Cost: %d\n", mincost);
}

int main() {
    int i, j;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Cost Matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &wt[i][j]);
    prims();
    return 0;
}