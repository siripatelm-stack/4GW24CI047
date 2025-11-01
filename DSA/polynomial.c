#include <stdio.h>
#define MAX 100

void addPolynomials(int A[], int B[], int m, int n, int result[]) {
    int size = (m > n) ? m : n;

    // Initialize result to zero
    for (int i = 0; i < size; i++)
        result[i] = 0;

    // Add coefficients of A
    for (int i = 0; i < m; i++)
    result[i] += A[i];

    // Add coefficients of B
    for (int i = 0; i < n; i++)
        result[i] += B[i];
}

int main() {
    // Example: 5 + 0x^1 + 10x^2 + 6x^3
    int A[MAX] = {5, 0, 10, 6};
    int m = 4;
    // Example: 1 + 2x^1 + 4x^2
    int B[MAX] = {1, 2, 4};
    int n = 3;

    int result[MAX];
    addPolynomials(A, B, m, n, result);

    int size = (m > n) ? m : n;
    printf("Sum Polynomial: ");
    for (int i = size - 1; i >= 0; i--) {
        if (result[i] != 0) {
            printf("%dx^%d", result[i], i);
            if (i != 0) printf(" + ");
        }
    }
    printf("\n");
    return 0;
}
