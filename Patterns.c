#include <stdio.h>
#include <stdlib.h>

void printPattern(int n) {
    int i, j;
    int min, max;

    // Determine the size of the pattern
    int size = 2*n-1;

    // Allocate memory for the pattern
    int **pattern = (int**)malloc(size*sizeof(int*));
    for (i = 0; i < size; i++) {
        pattern[i] = (int*)malloc(size*sizeof(int));
    }

    // Fill the pattern with values
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            min = i < j ? i : j;
            min = min < size-i ? min : size-i-1;
            min = min < size-j-1 ? min : size-j-1;
            pattern[i][j] = n - min;
        }
    }

    // Print the pattern
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", pattern[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < size; i++) {
        free(pattern[i]);
    }
    free(pattern);
}

int main() {
    int n;
   
    scanf("%d", &n);
    printPattern(n);
    return 0;
}
