#include <stdio.h>

//updated  First Come First Serve
int main() {
    int n;
    printf("Enter the number of programs you want: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], x[n];
    int iscom[n], tcom = 0;
    int eidx = 0, exorder[100];
    int ctime = 0;

    for (int i = 0; i < n; i++) { 
        printf("For P%d: \n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        iscom[i] = 0;
        x[i] = i;
    }
    //sort
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[x[i]] > at[x[j]]) {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

 
    while (tcom < n) {
        int idx = -1;
          for (int i = 0; i < n; i++) {
            if (at[x[i]] <= ctime && !iscom[x[i]])
             {
                idx = x[i];
                break;
            }
        }

        if (idx != -1) {
            ct[idx] = ctime + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            ctime += bt[idx];
            iscom[idx] = 1;
            tcom++;
            exorder[eidx++] = idx; // Store executed process index
        } else {
            exorder[eidx++] = -1; // Record idle time
            ctime++;
        }
    }

    // Print process details
    printf("\nPID    AT    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n");

    // Print execution order
    printf(" | ");
    for (int i = 0; i < eidx; i++) {
        if (exorder[i] == -1) {
            printf(" Idle | ");
        } else {
            printf(" P%d | ", exorder[i] + 1);
        }
    }
    printf("\n");

    printf(" 0");
    ctime = 0;
    for (int i = 0; i < eidx; i++) {
        if (exorder[i] == -1) {
            ctime++;
            printf("     %d ", ctime);
        } else {
            ctime = ct[exorder[i]];
            printf("     %d ", ctime);
        }
    }
    printf("\n");

    return 0;
}
