#include <stdio.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

struct Edge edge[MAX];

int parent[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    int n, e, i, j;
    int totalCost = 0, count = 0;
    struct Edge temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    // Construct MST
    for (i = 0; i < e && count < n - 1; i++){
        int u = edge[i].u;
        int v = edge[i].v;

        if (find(u) != find(v)){
            printf("%d - %d : %d\n",
                   u, v, edge[i].w);

            totalCost += edge[i].w;
            unite(u, v);
            count++;
        }
    }

    if (count != n - 1){
        printf("MST does not exist.\n");
    }
    else
    {
        printf("Total MST Cost: %d\n", totalCost);
    }
    return 0;
}