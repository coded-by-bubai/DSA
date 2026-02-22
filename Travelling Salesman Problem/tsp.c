#include<stdio.h>
#include<limits.h>
#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INT_MAX;
int path[MAX];
int bestPath[MAX];

void tsp(int city, int count, int currCost){
    if (count == n && cost[city][0])
    {
        if (currCost + cost[city][0] < minCost)
        {
            minCost = currCost + cost[city][0];
            for (int i = 0; i < n; i++)
            {
                bestPath[i] = path[i];
            }
            
        }
        return;
    }
    

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i])
        {
            visited[i] = 1;
            path[count] = i;
            tsp(i, count+1, currCost + cost[city][i]);
            visited[i] = 0;
        }
        
    }
    
}

int main(){
    
    printf("Enter number of city(Enter < 10) :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter cost to travel city%d to city%d : ",i,j);
            scanf("%d", &cost[i][j]);
        }
        
    }
    
    visited[0] = 1;
    path[0] = 0;
    tsp(0,1,0);
    printf("Minimum cost is : %d\n", minCost);
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", bestPath[i]);
    }
    printf("0\n");
    return 0;
}
