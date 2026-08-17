#include <stdio.h>
#include <stdlib.h>

int acceptAndVerifyMatrix(int matrix[][3], int matrixNum) {
    int rows, cols, elements;
    
    printf("\nInput for Compact Sparse Matrix %c \n", (matrixNum == 1) ? 'A' : 'B');
    printf("Enter number of matrix rows: ");
    scanf("%d", &rows);
    printf("Enter number of matrix columns: ");
    scanf("%d", &cols);
    printf("Enter total number of non-zero elements: ");
    scanf("%d", &elements);

    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = elements;

    printf("\nEnter %d elements (Row, Column, Value) in ascending order:\n", elements);
    
    int lastRow = -1;
    int lastCol = -1;

    for (int i = 1; i <= elements; i++) {
        printf("Element %d details (row col val): ", i);
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);

        if (matrix[i][0] < 0 || matrix[i][0] >= rows || matrix[i][1] < 0 || matrix[i][1] >= cols) {
            printf("\n[Validation Error]: Coordinates (%d, %d) out of matrix bounds (%d x %d)!\n", 
                   matrix[i][0], matrix[i][1], rows, cols);
            return 0; 
        }

        if (matrix[i][0] < lastRow || (matrix[i][0] == lastRow && matrix[i][1] <= lastCol)) {
            printf("\n[Validation Error]: Elements are not in row-major sorted sequence!\n");
            return 0; 
        }

        lastRow = matrix[i][0];
        lastCol = matrix[i][1];
    }
    return 1; 
}

void printCompactMatrix(int matrix[][3], char matrixName) {
    int totalTerms = matrix[0][2];
    
    printf("\nCompact Sparse Matrix %c \n", matrixName);
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= totalTerms; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

void addCompactSparseMatrices(int compactA[][3], int compactB[][3], int compactSum[][3], int n, int m) {
    int totalNonZeroA = compactA[0][2];
    int totalNonZeroB = compactB[0][2];

    compactSum[0][0] = n;
    compactSum[0][1] = m;

    int i = 1; 
    int j = 1; 
    int k = 1; 
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int has_A = (i <= totalNonZeroA && compactA[i][0] == row && compactA[i][1] == col);
            
            int has_B = (j <= totalNonZeroB && compactB[j][0] == row && compactB[j][1] == col);

            if (has_A && has_B) {
                int sum = compactA[i][2] + compactB[j][2];
                if (sum != 0) { 
                    compactSum[k][0] = row;
                    compactSum[k][1] = col;
                    compactSum[k][2] = sum;
                    k++;
                }
                i++;
                j++;
            }
            // RULE 2: "Jo pehle aata hai" -> Only Matrix A has an element at this position
            else if (has_A) {
                compactSum[k][0] = compactA[i][0];
                compactSum[k][1] = compactA[i][1];
                compactSum[k][2] = compactA[i][2];
                i++;
                k++;
            }
            // RULE 2: "Jo pehle aata hai" -> Only Matrix B has an element at this position
            else if (has_B) {
                compactSum[k][0] = compactB[j][0];
                compactSum[k][1] = compactB[j][1];
                compactSum[k][2] = compactB[j][2];
                j++;
                k++;
            }
        }
    }

    compactSum[0][2] = k - 1;
}

int main() {
    int compactA[100][3];
    int compactB[100][3];
    int compactSum[200][3];

    if (!acceptAndVerifyMatrix(compactA, 1)) {
        printf("\nExecution Aborted: Invalid input configuration for Matrix A.\n");
        return 1;
    }

    if (!acceptAndVerifyMatrix(compactB, 2)) {
        printf("\nExecution Aborted: Invalid input configuration for Matrix B.\n");
        return 1;
    }

    if (compactA[0][0] != compactB[0][0] || compactA[0][1] != compactB[0][1]) {
        printf("\n[Size Match Error]: Dimensions of Matrix A (%dx%d) and Matrix B (%dx%d) must match!\n",
               compactA[0][0], compactA[0][1], compactB[0][0], compactB[0][1]);
        return 1;
    }

    int rows = compactA[0][0];
    int cols = compactA[0][1];

    addCompactSparseMatrices(compactA, compactB, compactSum, rows, cols);

    printCompactMatrix(compactA, 'A');
    printCompactMatrix(compactB, 'B');
    printCompactMatrix(compactSum, 'S'); 

    return 0;
}

