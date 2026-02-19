#include <stdio.h>
int matrix[25][25], visited[25], n, cost = 0;
int nearest(int city) {
    int i;
    int min = 999;
    int next = -1;
    for(i = 0; i < n; i++) {
        if(matrix[city][i] != 0 && visited[i] == 0) {
            if(matrix[city][i] < min) {
                min = matrix[city][i];
                next = i;
            }
        }
    }
    return next;
}
void tsp(int city) {
    int next_city;
    visited[city] = 1;
    printf("%d ", city + 1);
    next_city = nearest(city);
    if(next_city == -1) {
        printf("%d ", 1);
        cost += matrix[city][0];
        return;
    }
    cost += matrix[city][next_city];
    tsp(next_city);
}
int main() {
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        visited[i] = 0;
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nPath: ");
    tsp(0);
    printf("\nMinimum Cost: %d\n", cost);
    return 0;
}
