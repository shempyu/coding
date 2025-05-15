#include <stdio.h>

// First Come First Serve
int main() {
    int n;
    printf("Enter the number of programs you want: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], x[n];

    // Input arrival time and burst time
    for (int i = 0; i < n; i++) {
        x[i] = i;
        printf("For P%d: \n", i + 1);
        printf("Enter AT and BT: ");
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("\n\n");

    // Sorting processes based on arrival time (FCFS)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[x[i]] > at[x[j]]) {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    // Calculate Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT)
    int ctx = 0; // Start Gantt chart from 0
    for (int i = 0; i < n; i++) {
        if (ctx < at[x[i]]) {
            ctx = at[x[i]]; // If CPU is idle, start at process's arrival time
        }

        ct[x[i]] = bt[x[i]] + ctx;  // Completion time
        tat[x[i]] = ct[x[i]] - at[x[i]];  // Turnaround time
        wt[x[i]] = tat[x[i]] - bt[x[i]];  // Waiting time
        ctx = ct[x[i]];  // Move current time to completion time of the process
    }

    // Print process details
    printf("PID    AT    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Gantt chart
    printf("\n\nGantt Chart:\n\n");

    // Top border of the Gantt chart
    printf(" ");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Check for idle time (when no process is running)
        if (current_time < at[x[i]]) {
            // Print idle period
            for (int j = 0; j < (at[x[i]] - current_time) * 2 + 4; j++) {
                printf("-");
            }
            current_time = at[x[i]];
        }
        for (int j = 0; j < bt[x[i]] * 2 + 4; j++) {
            printf("-");
        }
        current_time = ct[x[i]];
    }
    printf("-\n");

    // Middle part with process names
    current_time = 0;
    printf("|");
    for (int i = 0; i < n; i++) {
        // Check for idle time
        if (current_time < at[x[i]]) {
            // Print idle period
            printf(" Idle ");
            for (int j = 0; j < (at[x[i]] - current_time) * 2 - 4; j++) {
                printf(" ");
            }
            printf("|");
            current_time = at[x[i]];
        }

        // Print process
        for (int j = 0; j < bt[x[i]]; j++) {
            printf(" ");
        }
        printf("P%d", x[i] + 1);
        for (int j = 0; j < bt[x[i]]; j++) {
            printf(" ");
        }
        printf("|");
        current_time = ct[x[i]];
    }
    printf("\n");

    // Bottom border of the Gantt chart
    current_time = 0;
    printf(" ");
    for (int i = 0; i < n; i++) {
        // Check for idle time (when no process is running)
        if (current_time < at[x[i]]) {
            // Print idle period
            for (int j = 0; j < (at[x[i]] - current_time) * 2 + 4; j++) {
                printf("-");
            }
            current_time = at[x[i]];
        }

        for (int j = 0; j < bt[x[i]] * 2 + 4; j++) {
            printf("-");
        }
        current_time = ct[x[i]];
    }
    printf("-\n");

    // Time markers at the bottom
    printf("0"); // Start time
    current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < at[x[i]]) {
            // Print idle period time
            printf("%*d", (at[x[i]] - current_time) * 2 + 4, at[x[i]]);
            current_time = at[x[i]];
        }
        printf("%*d", bt[x[i]] * 2 + 4, ct[x[i]]); // Print completion time
        current_time = ct[x[i]];
    }
    printf("\n");

    return 0;
}
