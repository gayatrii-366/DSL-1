#include <stdio.h>

int main() {
    int n, m, p, q;
    int i, j;

    // --- Matrix A Input ---
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &n, &m);
    int arr1[n][m];
    
    printf("Enter elements for Matrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
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
            scanf("%d", &arr2[i][j]);
        }
    }

    // --- Dimension Verification for Addition/Subtraction ---
    if (n != p || m != q) {
        printf("\nError: Matrices must have identical dimensions for addition and subtraction.\n");
        return 1;
    }

    // Allocate result arrays
    int sum[n][m];
    int sub[n][m];

    // --- Performing calculations using loops ---
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
            sub[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    // --- Displaying the Addition Result ---
    printf("\nResult of Matrix Addition:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

