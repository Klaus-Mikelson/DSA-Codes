#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int val)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = val;
    root->next = NULL;
    return root;
}

void addedge(struct node *adjlist[], int vertex, int nvertex)
{
    struct node *newNode = createnode(nvertex);

    // Insert the new node in the correct position to maintain ascending order
    if (adjlist[vertex] == NULL || adjlist[vertex]->data > nvertex)
    {
        newNode->next = adjlist[vertex];
        adjlist[vertex] = newNode;
    }
    else
    {
        struct node *current = adjlist[vertex];
        while (current->next != NULL && current->next->data < nvertex)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dfs(struct node *adjlist[], int vertex, int *visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);
    struct node *tmp = adjlist[vertex];
    while (tmp != NULL)
    {
        int vnode = tmp->data;
        if (!visited[vnode])
        {
            dfs(adjlist, vnode, visited);
        }
        tmp = tmp->next;
    }
}
int main()
{
    int vertex = 5;
    int visited[vertex];
    for (int i = 0; i < vertex; i++)
    {
        visited[i] = 0;
    }

    struct node *adjlist[vertex];
    for (int i = 0; i < vertex; i++)
    {
        adjlist[i] = NULL;
    }

    addedge(adjlist, 0, 1);
    addedge(adjlist, 0, 2);
    addedge(adjlist, 1, 3);
    addedge(adjlist, 1, 4);
    addedge(adjlist, 2, 4);

    printf("DFS Traversal of graph from 0 vertex: ");
    dfs(adjlist, 0, visited);

    return 0;
}