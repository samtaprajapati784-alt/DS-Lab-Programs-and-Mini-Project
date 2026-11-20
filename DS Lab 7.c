/*
Name: Samta Prajapati
Roll no: CO2122
Title: Social network connectivity using adjacency matrix.
*/
#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int n;

/* Add connection between two users */
void addConnection(int u, int v)
{
    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        printf("Invalid user ID!\n");
        return;
    }
    if (u == v)
    {
        printf("Self-connection is not allowed.\n");
        return;
    }
    if (adj[u][v] == 1)
    {
        printf("Connection already exists.\n");
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    printf("Connection added successfully.\n");
}

/* Display adjacency matrix */
void displayGraph()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

/* Breadth First Search */
void BFS(int start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int i, current;

    if (start < 0 || start >= n)
    {
        printf("Invalid starting user ID!\n");
        return;
    }
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear)
    {
        current = queue[front++];
        printf("%d ", current);
        for (i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

/* DFS recursive utility function */
void DFSUtil(int vertex, int visited[])
{
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && visited[i] == 0)
        {
            DFSUtil(i, visited);
        }
    }
}

/* Depth First Search */
void DFS(int start)
{
    int visited[MAX] = {0};

    if (start < 0 || start >= n)
    {
        printf("Invalid starting user ID!\n");
        return;
    }
    printf("DFS Traversal: ");
    DFSUtil(start, visited);
    printf("\n");
}

int main()
{
    int choice, u, v, start;

    printf("Enter number of users (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX)
    {
        printf("Invalid number of users!\n");
        return 1;
    }

    do
    {
        printf("\n==== Social Network Menu ====\n");
        printf("1. Add Connection\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Perform BFS\n");
        printf("4. Perform DFS\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two user IDs (0 to %d): ", n - 1);
                scanf("%d %d", &u, &v);
                addConnection(u, v);
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("Enter starting user ID: ");
                scanf("%d", &start);
                BFS(start);
                break;
            case 4:
                printf("Enter starting user ID: ");
                scanf("%d", &start);
                DFS(start);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/*OUTPUT
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 1
Enter two user IDs (0 to 4): 0 1
Connection added successfully.
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 1
Enter two user IDs (0 to 4): 0 2
Connection added successfully.
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 1
Enter two user IDs (0 to 4): 1 3
Connection added successfully.
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 2
Adjacency Matrix:
01234
0:01 100
1:10011
2:10000
3:01000
4:01000
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 3
Enter starting user ID: 0
BFS Traversal: 01234
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 4
Enter starting user ID: 0
DFS Traversal: 0 1 3 4 2
==== Social Network Menu ====
1. Add Connection
2. Display Adjacency Matrix
3. Perform BFS
4. Perform DFS
5. Exit
Enter your choice: 5
Exiting program.
*/
