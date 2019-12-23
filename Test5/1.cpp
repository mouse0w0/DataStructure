//
// Created by Mouse on 2019/12/22.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX 10

int array[MAX];

void generateRandomData();

void initialize();

int linearSearch(int *array, int size, int n);

int binarySearch(int *array, int size, int n);

int binaryRecursiveSearch(int *array, int start, int end, int n);

int compare(const void *o1, const void *o2);

int main() {
    generateRandomData();
    initialize();
    for (int i = 0; i < MAX; ++i) {
        printf("%d ", array[i]);
    }
    printf("\nEnter a number:");
    int n;
    scanf("%d", &n);
    printf("Linear search result: %d\n", linearSearch(array, MAX, n));
    qsort(array, MAX, sizeof(int), compare);
    printf("Binary search result: %d\n", binarySearch(array, MAX, n));
    printf("Binary recursive search result: %d\n", binaryRecursiveSearch(array, 0, MAX, n));
    return 0;
}

void generateRandomData() {
    FILE *file = fopen("test5-1.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        fprintf(file, "%d\n", rand() % 100);
    }
    fclose(file);
}

void initialize() {
    FILE *file = fopen("test5-1.txt", "r");
    for (int i = 0; i < MAX; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);
}

int linearSearch(int *array, int size, int n) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == n) return i;
    }
    return -1;
}

int binarySearch(int *array, int size, int n) {
    int start = 0;
    int end = size;
    while (start != end) {
        int mid = (start + end) / 2;
        if (array[mid] == n) return mid;
        if (array[mid] > n) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int binaryRecursiveSearch(int *array, int start, int end, int n) {
    if (start == end) return -1;
    int mid = (start + end) / 2;
    if (array[mid] == n) return mid;
    if (array[mid] > n) return binaryRecursiveSearch(array, start, mid - 1, n);
    else return binaryRecursiveSearch(array, mid + 1, end, n);
}

int compare(const void *o1, const void *o2) {
    return *(int *) o1 - *(int *) o2;
}
