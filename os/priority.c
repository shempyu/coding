#include <stdio.h>
//priority schedulling code
int main() {
    int n, is_higher_priority_high;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Ask user if higher numbers mean higher priority
    printf("Should higher priority numbers indicate higher priority? (1 for Yes, 0 for No): ");
    scanf("%d", &is_higher_priority_high);

    int at[n], bt[n], pri[n], ct[n], tat[n], wt[n], rt[n], is_completed[n];
    int execution_order[2 * n]; // Store the order of execution (including idle periods)
    int exec_idx = 0;           // Index for execution order
    int total_completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("For P%d: \n", i + 1);
        printf("Enter arrival time, burst time, and priority: ");
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
        rt[i] = bt[i];         // Remaining time is initially the burst time
        is_completed[i] = 0;   // Mark all processes as not completed
    }

    // Run scheduling until all processes are completed
    while (total_completed < n) {
        int selected_process_index = -1;
        int selected_priority = is_higher_priority_high ? -1 : 1000000; // Initialize based on priority preference

        // Select the process with the correct priority based on user input
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && !is_completed[i]) {
                if ((is_higher_priority_high && pri[i] > selected_priority) || 
                    (!is_higher_priority_high && pri[i] < selected_priority)) {
                    selected_priority = pri[i];
                    selected_process_index = i;
                }
            }
        }

        // If no process is ready to execute, add idle time
        if (selected_process_index == -1) {
            execution_order[exec_idx++] = -1; // Idle period
            current_time++;
        } else {
            // Execute the selected process
            current_time += rt[selected_process_index]; // Add remaining time to current time
            ct[selected_process_index] = current_time; // Completion time
            tat[selected_process_index] = ct[selected_process_index] - at[selected_process_index]; // Turnaround time
            wt[selected_process_index] = tat[selected_process_index] - bt[selected_process_index]; // Waiting time

            is_completed[selected_process_index] = 1; // Mark process as completed
            execution_order[exec_idx++] = selected_process_index; // Store process in execution order
            total_completed++;

            // Update totals for averages
            total_tat += tat[selected_process_index];
            total_wt += wt[selected_process_index];
        }
    }

    // Output the results in table format
    printf("\nPID    AT    BT    PRI   CT    TAT   WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d     %d     %d     %d     %d     %d     %d\n", 
               i + 1, at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
    }

    // Gantt chart
    printf("\nGantt chart: \n\n");

    // Top border
    printf(" ");
    for (int i = 0; i < exec_idx; i++) {
        if (execution_order[i] == -1) {
            for (int j = 0; j < 6; j++) {
                printf("-");
            }
        } else {
            for (int j = 0; j < 6; j++) {
                printf("-");
            }
        }
    }
    printf("-\n");

    // Middle part with process names
    printf("|");
    for (int i = 0; i < exec_idx; i++) {
        if (execution_order[i] == -1) {
            printf(" Idle ");
        } else {
            printf("  P%d  ", execution_order[i] + 1);
        }
        printf("|");
    }
    printf("\n");

    // Bottom border
    printf(" ");
    for (int i = 0; i < exec_idx; i++) {
        if (execution_order[i] == -1) {
            for (int j = 0; j < 6; j++) {
                printf("-");
            }
        } else {
            for (int j = 0; j < 6; j++) {
                printf("-");
            }
        }
    }
    printf("-\n");

    // Time markers
    printf("0");
    current_time = 0;
    for (int i = 0; i < exec_idx; i++) {
        if (execution_order[i] == -1) {
            current_time++;
            printf("     %d", current_time);
        } else {
            current_time = ct[execution_order[i]];
            printf("     %d", current_time);
        }
    }
    printf("\n");

    // Print average TAT and WT
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
