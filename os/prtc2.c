#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter the number of programs: ");
    scanf("%d", &n);

    // Declare arrays for process attributes
    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], x[n];
    int iscom[n], q[100], exorder[100], extime[100];
    int front = 0, rear = 0, exidx = 0, tcom = 0, ctime = 0;

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("For program P%d:\n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time
        iscom[i] = 0;  // Mark as not completed
        x[i] = i;      // Store original process index for sorting
    }

    // Sort processes by arrival time using `x[i]`
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[x[i]] > at[x[j]]) {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    // Add the first process to the queue
    if (at[x[0]] > 0) ctime = at[x[0]]; // Handle idle time if needed
    q[rear++] = x[0];     // Enqueue the first arriving process

    while (tcom < n) {
        if (front < rear) {
            int p = q[front++];

            // Execute the process for the time quantum or remaining time
            int t = (rt[p] > tq) ? tq : rt[p];
            ctime += t;
            rt[p] -= t;

            // Record execution order and time
            exorder[exidx] = p;
            extime[exidx++] = ctime;

            // If process is complete
            if (rt[p] == 0) {
                ct[p] = ctime;
                tat[p] = ct[p] - at[p];
                wt[p] = tat[p] - bt[p];
                iscom[p] = 1;
                tcom++;
            }

            // Add new processes to the queue up to the cureent
            for (int i = 0; i < n; i++) {
                if (at[x[i]] <= ctime && !iscom[x[i]] && x[i] != p) {
                    int found = 0;
                    for (int j = front; j < rear; j++) {
                        if (q[j] == x[i]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) q[rear++] = x[i];
                }
            }

            // Re-enqueue the current process if not finished
            if (rt[p] > 0) q[rear++] = p;
        } else {
            // If no process is ready, system is idle
            ctime++;
            for (int i = 0; i < n; i++) {
                if (at[x[i]] <= ctime && !iscom[x[i]]) {
                    q[rear++] = x[i];
                    break;
                }
            }
        }
    }

    // Print the results
    printf("\n PID    AT    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Display Gantt chart
    printf("\nGantt Chart:\n");

    // Print process names (with idle time)
    int lastProcess = -2;  // To track the last process
    for (int i = 0; i < exidx; i++) {
        if (exorder[i] != lastProcess) {
            // Print the process or idle
            if (exorder[i] == -1) {
                printf("idle ");
            } else {
                printf("P%d ", exorder[i] + 1);
            }
            lastProcess = exorder[i];
        }
    }
    printf("\n");

    // Print the timestamps
    printf("0 ");
    lastProcess = -2;  // Reset to -2 for the timestamps
    ctime = 0;
    for (int i = 0; i < exidx; i++) {
        if (exorder[i] != lastProcess) {
            if (lastProcess != -2) {
                printf("   %d", ctime);  // Print timestamp
            }
            lastProcess = exorder[i];
        }
        ctime++;
    }
    printf("   %d\n", ctime);  // Final timestamp

    // Print averages
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
    printf("Average Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
