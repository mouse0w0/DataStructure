//
// Created by Mouse on 2019/12/26.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX 10000

using namespace std;

int array[MAX];

void GenerateRandomData();

void Initialize();

void Print(int *array, int size);

void QuickSort(int *array, int size);

int main() {
    GenerateRandomData();
    Initialize();
    Print(array, MAX);
    QuickSort(array, MAX);
    Print(array, MAX);
    return 0;
}

void GenerateRandomData() {
    FILE *file = fopen("test6-2.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        fprintf(file, "%d\n", rand() % 100000);
    }
    fclose(file);
}

void Initialize() {
    FILE *file = fopen("test6-2.txt", "r");
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

int Partition(int *array, int start, int end) {
    int key = array[start]; //元素移动
    int i = start, j = end;
    while (i < j) {
        while (i < j && array[j] >= key) j--;
        array[i] = array[j]; // 元素移动
        while (i < j && array[i] <= key) i++;
        array[j] = array[i]; // 元素移动
    }
    array[i] = key; // 元素移动
    return i; // 返回枢轴元素最后确定的位置
}

void QuickSort(int *array, int start, int end) {
    if (start >= end) return; // 结束递归
    int mid = Partition(array, start, end); //一趟划分，确定枢轴元素位置
    QuickSort(array, start, mid - 1); // 左子序列进行快速排序
    QuickSort(array, mid + 1, end); // 右子序列进行快速排序
}

void QuickSort(int *array, int size) {
    QuickSort(array, 0, size - 1);
}