#include <stdio.h>

// Function to display sparse matrix in triplet form
void display(int s[][3], int t) {
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= t; i++) {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}

// Function to create sparse matrix from normal matrix
void createSparse(int A[][10], int m, int n, int S[][3]) {
    int k = 1;
    S[0][0] = m;
    S[0][1] = n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }
    S[0][2] = k - 1;  // Total non-zero elements
}

// SIMPLE TRANSPOSE
void simpleTranspose(int A[][3], int B[][3]) {
    int rows = A[0][0];
    int cols = A[0][1];
    int t = A[0][2];
    
    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = t;
    
    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= t; i++) {
            if (A[i][1] == col) {
                B[k][0] = A[i][1];  // New row = old column
                B[k][1] = A[i][0];  // New column = old row
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

// FAST TRANSPOSE (Efficient method)
void fastTranspose(int A[][3], int B[][3]) {
    int rows = A[0][0];
    int cols = A[0][1];
    int t = A[0][2];
    
    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = t;
    
    if (t <= 0) return;
    
    int S[10] = {0};  // Frequency of each column
    int T[10] = {0};  // Starting position for each row
    
    // Step 1: Count elements in each column
    for (int i = 1; i <= t; i++) {
        S[A[i][1]]++;
    }
    
    // Step 2: Calculate starting positions
    T[0] = 1;
    for (int i = 1; i < cols; i++) {
        T[i] = T[i-1] + S[i-1];
    }
    
    // Step 3: Place elements in transpose
    for (int i = 1; i <= t; i++) {
        int col = A[i][1];
        int pos = T[col];
        B[pos][0] = A[i][1];
        B[pos][1] = A[i][0];
        B[pos][2] = A[i][2];
        T[col]++;
    }
}

int main() {
    int A[10][10], S[20][3], T1[20][3], T2[20][3];
    int m, n;
    
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    
    // Create sparse matrix
    createSparse(A, m, n, S);
    printf("\nSparse Matrix (Triplet Form):");
    display(S, S[0][2]);
    
    // Simple Transpose
    simpleTranspose(S, T1);
    printf("\nSimple Transpose:");
    display(T1, T1[0][2]);
    
    // Fast Transpose
    fastTranspose(S, T2);
    printf("\nFast Transpose:");
    display(T2, T2[0][2]);
    
    return 0;
}