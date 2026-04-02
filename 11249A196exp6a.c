#include <stdio.h>
#define MAX 10
#define INF 
int main() {
    int n, cost[MAX][MAX], distance[MAX], visited[MAX];
    int i, j, start, count, minDist, nextNode;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    for(i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while(count < n - 1) {
        minDist = INF;
        for(i = 0; i < n; i++) {
            if(distance[i] < minDist && !visited[i]) {
                minDist = distance[i];
                nextNode = i;
            }
        }
        visited[nextNode] = 1;
        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                if(minDist + cost[nextNode][i] < distance[i]) {
                    distance[i] = minDist + cost[nextNode][i];
                }
            }
        }
        count++;
    }
    printf("\nShortest distances from node %d:\n", start);
    for(i = 0; i < n; i++) {
        printf("To node %d = %d\n", i, distance[i]);
    }
    return 0;
}
