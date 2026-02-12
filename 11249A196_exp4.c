#include <stdio.h>
typedef struct {
    int value, weight;
    float ratio;
} Item;
void swap(Item* a, Item* b) {
    Item temp = *a; *a = *b; *b = temp;
}
void sortByRatio(Item arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j].ratio < arr[j+1].ratio)
                swap(&arr[j], &arr[j+1]);
}
float fractionalKnapsack(Item items[], int n, int W) {
    sortByRatio(items, n);
    float totalValue = 0;
    int i;
    for(i = 0; i < n && W > 0; i++) {
        if(items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * W;
            W = 0;
        }
    }
    return totalValue;
}
