#include <stdio.h>

void acceptMatrix(int rows, int cols, int matrix[4][4]) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void compact(int rows, int cols, int matrix[4][4], int compact_matrix[16][3]) {
    compact_matrix[0][0] = rows;
    compact_matrix[0][1] = cols;
    
    int k = 1;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compact_matrix[k][0] = i;
                compact_matrix[k][1] = j;
                compact_matrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    compact_matrix[0][2] = k - 1;
}

int main() {
    int matrix[4][4] = {0};
    int compact_matrix[16][3];
    int rows = 4, cols = 4;

    acceptMatrix(rows, cols, matrix);
    compact(rows, cols, matrix, compact_matrix);

    printf("\nCompact Matrix (Triplet Form):\n");
    for (int i = 0; i <= compact_matrix[0][2]; i++) {
        printf("%d %d %d\n", compact_matrix[i][0], compact_matrix[i][1], compact_matrix[i][2]);
    }

    return 0;
}
