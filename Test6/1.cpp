//
// Created by Mouse on 2019/12/26.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

int array[MAX];

void GenerateRandomData();

void Initialize();

void Print(int *array, int size);

void BubbleSort(int *array, int size);

void SelectSort(int *array, int size);

void InsertSort(int *array, int size);

int main() {
    GenerateRandomData();
    Initialize();
    Print(array, MAX);
    BubbleSort(array, MAX);
    Print(array, MAX);
    Initialize();
    SelectSort(array, MAX);
    Print(array, MAX);
    Initialize();
    InsertSort(array, MAX);
    Print(array, MAX);
    return 0;
}

void GenerateRandomData() {
    FILE *file = fopen("test6-1.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        fprintf(file, "%d\n", rand() % 100);
    }
    fclose(file);
}

void Initialize() {
    FILE *file = fopen("test6-1.txt", "r");
    for (int i = 0; i < MAX; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);
}

void Print(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int *array, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 1; j < size - i; ++j)
            if (array[j] < array[j - 1]) // 按非递增顺序排序
                swap(array[j], array[j - 1]);
}

void SelectSort(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min]) min = j; // 找到最小值
        }
        swap(array[i], array[min]);
    }
}

void InsertSort(int *array, int size) {
    for (int i = 1; i < size; ++i) {
        int t = array[i], j; // t为检查哨
        for (j = i - 1; j >= 0 && array[j] > t; j--) array[j + 1] = array[j]; // 查找一个比t小的值，并将比t大的值向后移动
        array[j + 1] = t;
    }
}