#include <stdio.h>

#define MAXN 20

int Delete(int A[], int L, int minA, int maxA);

int main() {
    int A[MAXN], L, minA, maxA, i;

    scanf("%d", &L);
    for (i = 0; i < L; i++) scanf("%d", &A[i]);
    scanf("%d %d", &minA, &maxA);
    L = Delete(A, L, minA, maxA);
    for (i = 0; i < L; i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}

/* 你的代码将被嵌在这里 */
#include <string.h>

int Delete(int A[], int L, int minA, int maxA) {
    int NewL = 0;
    int NewArray[MAXN];
    for (int i = 0; i < L; i++) {
        if (A[i] <= minA || A[i] >= maxA) {
            NewArray[NewL++] = A[i];
        }
    }
    memcpy(A, NewArray, sizeof(int) * NewL);
    return NewL;
}
