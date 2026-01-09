#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int adj[MAX][MAX]; //adjacency matrix
int visited[MAX]; //visited matrix
int queue[MAX],front=-1,rear=-1;  

//Add edge to adjacency matrix
void addEdge(int u,int v,int n)
{
    if(u>=0 &&u<n&&v>=0&&v<n)   
        adj[u][v]=1; //directed edge u->v
}

//DFS Traversal
void DFS(int start,int n)
{
    visited[start]=1;
    printf("%d",start);
    for (int i=0;i<n;i++){
        if(adj[start][i]&& !visited[i])
        {
            DFS(i,n);
        }
    }
}

//BFS Traversal 
void enqueue(int v)
{
    if(rear==MAX-1)
        return;
    if(front==-1)
    {
        front=0;
        queue[++rear]=v;
    }
}

int dequeue()
{
    if(front==-1||front>rear)
        return -1;
    return queue[front++];
}

void BFS(int start,int n)
{
    for(int i=0;i<n;i++)
        visited[i]=0;
    enqueue(start);
    visited[start]=1;
    while(front<=rear)
    {
        int v=dequeue();
        printf("%d ",v);
        for (int i=0;i<n;i++)
        {
            if(ad)
        }
    }
}