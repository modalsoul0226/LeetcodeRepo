#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = pow((double)2, (double)n);
    int *res = (int *)malloc(sizeof(int) * (*returnSize)); 
    memset(res, 0, sizeof(int) * (*returnSize));
    
    int prev = 0;
    for (int i = 2; i <= *returnSize; i++) {
        if (i % 2 == 0) {
                prev ^= 0x1;
                res[i - 1] = prev;
                continue;
            }
        
        for (int j = 1; j < n; j++) {
            int rem = pow((double)2, (double)j) + 1;
            int div = pow((double)2, (double)(j + 1));
            if (i % div == rem) {
                // printf(":%d:", 1 << (j + 1));
                prev ^= (1 << j);
                res[i - 1] = prev;
                break;
            }
        }
    }
    
    return res;
}

int main() {
    int size = 0;
    int *res = grayCode(3, &size);
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}