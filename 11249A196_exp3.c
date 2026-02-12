#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* sort(int *sequence, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if (sequence[j] < sequence[j + 1]) {
                sequence[j] = sequence[j] + sequence[j + 1];
                sequence[j + 1] = sequence[j] - sequence[j + 1];
                sequence[j] = sequence[j] - sequence[j + 1];
            }
    return sequence;
}
void binPacking(int *a, int size, int n) {
    int binCount = 0, i, j;
    int binValues[n];
    for (i = 0; i < n; i++)
        binValues[i] = size;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (binValues[j] - a[i] >= 0) {
                binValues[j] -= a[i];
                break;
            }
        }
    for (i = 0; i < n; i++)
        if (binValues[i] != size)
            binCount++;
    printf("Number of bins required using first fit decreasing algorithm is: %d", binCount);
}
int main() {
    printf("BIN - PACKING Algorithm 1D Objects(First Fit Decreasing)\n");
    printf("Enter the number of items in Set: ");
    int n, i;
    scanf("%d", &n);
    printf("Enter %d items: ", n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the bin size: ");
    int size;
    scanf("%d", &size);
    int *sequence = sort(a, n);
    binPacking(sequence, size, n);
    return 0;
}
