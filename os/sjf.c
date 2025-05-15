#include <stdio.h>
// Shortest Job First (SJF) with idle time in Gantt chart
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], is_completed[n], total_completed = 0, current_time = 0;
    int execution_order[2 * n];  // Array to store the order of execution, including idle times
    int exec_idx = 0;            // Index to track the order of execution
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("For P%d: \n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        is_completed[i] = 0; // Mark all processes as not completed
    }

    // Keep executing until all processes are completed
    while (total_completed < n) {
        int shortest_job_index = -1;
        int min_bt = 100000; // Initialize with a large value to find the minimum burst time

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && !is_completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                shortest_job_index = i;
            }
        }

        // If no process has arrived yet, move current time forward and add idle period
        if (shortest_job_index == -1) {
            execution_order[exec_idx++] = -1;  // Idle period
            current_time++;  // Move the time forward by 1 unit for idle period
        } else {
            // Execute the process with the shortest burst time
            current_time += bt[shortest_job_index]; // Move time forward by burst time
            ct[shortest_job_index] = current_time;  // Completion time
            tat[shortest_job_index] = ct[shortest_job_index] - at[shortest_job_index]; // Turnaround time
            wt[shortest_job_index] = tat[shortest_job_index] - bt[shortest_job_index]; // Waiting time

            // Mark this process as completed
            is_completed[shortest_job_index] = 1;
            execution_order[exec_idx++] = shortest_job_index; // Store the process in the order of execution
            total_completed++;

            // Calculate total TAT and WT for averages
            total_tat += tat[shortest_job_index];
            total_wt += wt[shortest_job_index];
        }
    }

    // Output the results in table format
    printf("\nPID    AT    BT    CT    TAT   WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Gantt chart
    printf("\nGantt chart: \n\n");

    // Top border of the Gantt chart
    printf(" ");
    current_time = 0;  // Reset current_time for Gantt chart
    for (int i = 0; i < exec_idx; i++) {
        int p = execution_order[i]; // Process ID in order of execution
        if (p == -1) {
            // Idle time (1 unit)
            for (int j = 0; j < 6; j++) {
                printf("-");
            }
        } else {
            // Process execution time
            for (int j = 0; j < bt[p] * 2 + 4; j++) {
                printf("-");
            }
        }
    }
    printf("-\n");

    // Middle part with process names
    printf("|");
    for (int i = 0; i < exec_idx; i++) {
        int p = execution_order[i]; // Process ID in order of execution
        if (p == -1) {
            // Idle time
            printf(" Idle ");
        } else {
            for (int j = 0; j < bt[p]; j++)
                printf(" ");
            printf("P%d", p + 1);
            for (int j = 0; j < bt[p]; j++)
                printf(" ");
        }
        printf("|");
    }
    printf("\n");

    // Bottom border of the Gantt chart
    printf(" ");
    for (int i = 0; i < exec_idx; i++) {
        int p = execution_order[i]; // Process ID in order of execution
        if (p == -1) {
            // Idle time
            for (int j = 0; j < 6; j++) {
                printf("-");
            }
        } else {
            for (int j = 0; j < bt[p] * 2 + 4; j++) {
                printf("-");
            }
        }
    }
    printf("-\n");

    // Time markers at the bottom
    printf("0"); // Start time
    current_time = 0;
    for (int i = 0; i < exec_idx; i++) {
        int p = execution_order[i]; // Process ID in order of execution
        if (p == -1) {
            current_time++;  // Idle time is 1 unit
            printf("     %d", current_time);
        } else {
            current_time = ct[p];
            printf("%*d", bt[p] * 2 + 4, current_time); // Print completion time for the current process
        }
    }
    printf("\n");

    // Print average TAT and WT
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
