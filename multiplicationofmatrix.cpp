#include <stdio.h>

int main() {
    int n, m, p, q;
    int i, j, k;

    // --- Matrix A Input ---
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &n, &m);
    int arr1[n][m];
    
    printf("Enter elements for Matrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    // --- Matrix B Input ---
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &p, &q);
    int arr2[p][q];

    printf("Enter elements for Matrix B:\n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < q; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    // --- Multiplicability Validation ---
    if (m != p) {
        printf("\nError: Multiplication impossible! Columns of A (%d) must equal Rows of B (%d).\n", m, p);
        return 1;
    }

    // --- Matrix Multiplication Calculation ---
    int multiply[n][q];

    for(i = 0; i < n; i++) {
        for(j = 0; j < q; j++) {
            multiply[i][j] = 0; // Clear junk value before accumulation
            for(k = 0; k < m; k++) {
                multiply[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // --- Displaying the Multiplication Result ---
    printf("\nResultant Product Matrix (%dx%d):\n", n, q);
    for(i = 0; i < n; i++) {
        for(j = 0; j < q; j++) {
            printf("%d\t", multiply[i][j]);
        }
        printf("\n");
    }

    return 0;
}

