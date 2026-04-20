#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int random_partition(int arr[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(&arr[r], &arr[high]);
    return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = random_partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));

    int arr[] = {6, 4, 12, 8, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
