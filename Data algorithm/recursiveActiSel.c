#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortActivities(int s[], int f[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) { // Start j from i + 1
            if (f[i] > f[j]) {

                swap(&f[i], &f[j]);
                swap(&s[i], &s[j]);
            }
        }
    }
}

// Recursive function to select activities
void recursiveActivitySelector(int s[], int f[], int i, int n) {
    int m = i + 1;
    while (m < n && s[m] < f[i]) 
        m++;

    if (m < n) {
        printf("A%d ", m + 1);
        recursiveActivitySelector(s, f, m, n);
    }
}


int main() {
    int n;
    printf("No. of activities: ");
    scanf("%d", &n);

    int s[n], f[n];

    printf("s times :");
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    printf("f times :");
    for (int j = 0; j < n; j++) 
        scanf("%d", &f[j]);

    // Sort activities by f time
    sortActivities(s, f, n);

    printf("Selected activities are : ");
    printf("A1 ");  // The first activity always gets selected
    recursiveActivitySelector(s, f, 0, n);

    return 0;
}