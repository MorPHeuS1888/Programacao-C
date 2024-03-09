#include <stdio.h>
#include <stdbool.h>

#define N 5

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max_sum_of_n_elements(int matrix[N][N]) {
    int max_sum = -2147483647; // Initialize with the smallest possible integer value

    // Iterate through all possible starting points for the sum
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int current_sum = 0;
            bool valid_combination = true;

            // Sum up the elements in the current combination
            for (int k = 0; k < N; k++) {
                if (matrix[(i + k) % N][(j + k) % N] == 0) {
                    valid_combination = false;
                    break;
                }
                current_sum += matrix[(i + k) % N][(j + k) % N];
            }

            if (valid_combination) {
                max_sum = max(max_sum, current_sum);
            }
        }
    }

    return max_sum;
}

int main() {
    int matrix[N][N] = {
        {7, 53, 183, 439, 863},
        {497, 383, 563, 79, 973},
        {287, 63, 343, 169, 583},
        {627, 343, 773, 959, 943},
        {767, 473, 103, 699, 303},
    };

    int result = max_sum_of_n_elements(matrix);
    printf("Maximum sum of %d elements: %d\n", N, result);

    return 0;
}