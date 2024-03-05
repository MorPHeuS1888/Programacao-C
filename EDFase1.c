#include <stdio.h>

#define ROWS 5
#define COLS 5

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSumNoAdjacent(int matrix[ROWS][COLS]) {
    int maxSumExcluding[COLS] = {0};
    int maxSumIncluding[COLS] = {0};
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int current = matrix[i][j];
            if (j == 0) {
                maxSumExcluding[j] = max(maxSumIncluding[j], maxSumExcluding[j]);
                maxSumIncluding[j] = current + maxSumExcluding[j];
            } else {
                int prevMaxExcluding = max(maxSumIncluding[j-1], maxSumExcluding[j-1]);
                maxSumExcluding[j] = prevMaxExcluding;
                maxSumIncluding[j] = current + prevMaxExcluding;
            }
        }
    }
    
    return max(maxSumExcluding[COLS-1], maxSumIncluding[COLS-1]);
}

int main() {
    int matrix[ROWS][COLS] = {
        {7, 53, 183, 439, 863},
        {497, 383, 563, 79, 973},
        {287, 63, 343, 169, 583},
        {627, 343, 773, 959, 943},
        {767, 473, 103, 699, 303}
    };

    printf("Soma máxima possível: %d\n", maxSumNoAdjacent(matrix));

    return 0;
}
