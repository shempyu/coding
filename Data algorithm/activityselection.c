#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortActivities(int s[], int f[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) { // Start j from i + 1
            if (f[i] > f[j]) {
                // Swap finish times
                swap(&f[i], &f[j]);
                // Swap corresponding start times
                swap(&s[i], &s[j]);
            }
        }
    }
}


// Function to implement the Iterative Activity Selection Algorithm
void activitySelection(int s[], int f[], int n) {
    printf("Selected activities are:\n");

    // The first activity is always selected
    int i = 0;
    printf("A%d ", i + 1);
    
    for (int m = 1; m < n; m++) {
        // If the start time of activity m is greater or equal to the finish time of the last selected activity
        if (s[m] >= f[i]) {
            printf("A%d ", m + 1);
            i = m; // Update the last selected activity
        }
    }
}

int main() {
    // Example input: start times and finish times of activities
    int n ;
    printf("enetr the no .of activities: ");
    scanf("%d",&n);
    int s[n],f[n];
    for(int i = 0;i<n;i++){
        printf("enter stime & ftime for activity%d ",i+1);
        scanf("%d %d",&s[i],&f[i]);
    }
    sortActivities(s, f, n);
    // Call the activity selection function
    activitySelection(s, f, n);

    return 0;
}
