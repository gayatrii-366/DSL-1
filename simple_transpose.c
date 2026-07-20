#include <stdio.h>

void displaySparse(int matrix[10][3]) {
    int total_elements = matrix[0][2];
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= total_elements; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

void transposeSparse(int A[10][3], int B[10][3]) {
    int rows = A[0][0];
    int cols = A[0][1];
    int non_zero_elements = A[0][2];

    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = non_zero_elements;

    if (non_zero_elements <= 0) {
        return;
    }

    int q = 1; 
    for (int i = 0; i < cols; i++) {
        for (int p = 1; p <= non_zero_elements; p++) {
            if (A[p][1] == i) {
                B[q][0] = A[p][1]; 
                B[q][1] = A[p][0]; 
                B[q][2] = A[p][2]; 
                q++;
            }
        }
    }
}

int main() {
    int A[10][3] = {
        {3, 3, 4}, 
        {0, 1, 5},
        {1, 2, 8},
        {2, 0, 3},
        {2, 2, 1}
    };
    
    int B[10][3];

    transposeSparse(A, B);

    printf("Transposed Sparse Matrix:\n");
    displaySparse(B);

    return 0;
}
