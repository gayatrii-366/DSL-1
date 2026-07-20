#include <stdio.h>

void displaySparse(int matrix[10][3]) {
    int total_elements = matrix[0][2];
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= total_elements; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

void fast_transpose(int A[10][3], int B[10][3]) {
    int rows = A[0][0];
    int cols = A[0][1];
    int non_zero_elements = A[0][2];
    
    B[0][0] = cols; 
    B[0][1] = rows;
    B[0][2] = non_zero_elements;
    
    if (non_zero_elements <= 0) {
        return;
    }
    
    int row_terms[10] = {0};
    int starting_pos[10] = {0};
    
    for (int i = 1; i <= non_zero_elements; i++) {
        row_terms[A[i][1]]++;
    }
    
    starting_pos[0] = 1;
    for (int i = 1; i < cols; i++) {
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
    }
    
    for (int i = 1; i <= non_zero_elements; i++) {
        int col_idx = A[i][1];
        int dest_pos = starting_pos[col_idx]++;
        
        B[dest_pos][0] = A[i][1];
        B[dest_pos][1] = A[i][0];
        B[dest_pos][2] = A[i][2];
    }
}

int main() {
    int A[10][3], B[10][3];
    
    printf("Enter total rows, total columns, and total non-zero elements: ");
    scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]);
    
    printf("Enter the non-zero elements (Row, Column, Value):\n");
    for (int i = 1; i <= A[0][2]; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }
    
    printf("\nOriginal Sparse Matrix:\n");
    displaySparse(A);
    
    fast_transpose(A, B);
    
    printf("\nTransposed Sparse Matrix:\n");
    displaySparse(B);
    
    return 0;
}
