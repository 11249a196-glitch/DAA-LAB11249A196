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
int main() {
    Item items[] = {{60,10}, {100,20}, {120,30}};
    int n = 3;
    int W = 50;
    for(int i = 0; i < n; i++)
        items[i].ratio = (float)items[i].value / items[i].weight;
    printf("Items (Value, Weight, Ratio):\n");
    for(int i = 0; i < n; i++)
        printf("Item %d: %d, %d, %.2f\n", i+1, items[i].value, items[i].weight, items[i].ratio);
    float result = fractionalKnapsack(items, n, W);
    printf("\nMaximum value: %.2f\n", result);
    return 0;
}
