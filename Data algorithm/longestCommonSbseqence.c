#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char *X, char *Y, int m, int n) {
    int L[m+1][n+1];  

                                                                         // Building the table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) 
                L[i][j] = 0;                                             // LCS of empty strings is 0
             else if (X[i-1] == Y[j-1]) 
                L[i][j] = L[i-1][j-1] + 1;  
             else 
                L[i][j] = max(L[i-1][j], L[i][j-1]);  
            
        }
    }
                                                                        // L[m][n] contains the length of LCS for X[0..m-1] and Y[0..n-1]
    return L[m][n];
}

void printLCS(char *X, char *Y, int m, int n) {
     int L[m+1][n+1];

                                                                        // Build the LCS length table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    int index = L[m][n];

    char lcs[index+1];
    lcs[index] = '\0'; 

                                                                    // Start from the bottom-right corner of the table
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];  
            i--;
            j--;
            index--;
        } else if (L[i-1][j] > L[i][j-1]) {
            i--;                                       // Move to the upper cell if it has the larger value
        } else {
            j--;                                       // Move to the left cell if it has the larger value
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[100];
    char Y[100];
    printf("Enter a string1: ");
    scanf("%s", X); 
    
     printf("Enter a string2: ");
    scanf("%s", Y); 
    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS: %d\n", LCS(X, Y, m, n));
    printLCS(X, Y, m, n);

    return 0;
}

