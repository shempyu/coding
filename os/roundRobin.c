#include <stdio.h>

int main() {
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], bt_remaining[n], ct[n], tat[n], wt[n], x[n];
    int is_completed[n], total_completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Input process arrival time and burst time
    for (int i = 0; i < n; i++) {
        printf("For P%d: \n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        bt_remaining[i] = bt[i];  // Initialize remaining burst time
        is_completed[i] = 0;      // Mark all processes as not completed
        ct[i] = 0; 
        x[i] = i;                 // Store original process index for sorting
    }
    
    // Sort processes by arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[x[i]] > at[x[j]]) {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    int queue[100], front = 0, rear = 0; // Queue to store process indices
    int execution_order[100], exec_time_slice[100], exec_idx = 0;  // To store the Gantt chart order and time slices

    // Enqueue first arriving process (handle idle time if arrival time > 0)
    if (at[x[0]] > 0) {
        current_time = at[x[0]];  // Start at the first process's arrival time
    }
    queue[rear++] = x[0];  // Enqueue the first arriving process

    while (total_completed < n) {
        if (front != rear) {  // If the queue is not empty
            int p = queue[front++];  // Dequeue process
            
            // Execute the process for the time quantum or remaining burst time
            int execution_time = (bt_remaining[p] > quantum) ? quantum : bt_remaining[p];
            current_time += execution_time;
            bt_remaining[p] -= execution_time;
            
            // Record the process execution order and the time slice for Gantt chart
            execution_order[exec_idx] = p;
            exec_time_slice[exec_idx] = current_time;  // Record the time after the process runs
            exec_idx++;
            
            // If the process finishes, calculate CT, TAT, and WT
            if (bt_remaining[p] == 0) {
                ct[p] = current_time;
                tat[p] = ct[p] - at[p]; // Turnaround time
                wt[p] = tat[p] - bt[p]; // Waiting time
                
                is_completed[p] = 1;
                total_completed++;
                
                total_tat += tat[p];
                total_wt += wt[p];
            }

            // Check for any newly arrived processes up to the current time
            for (int i = 0; i < n; i++) {
                if (at[x[i]] <= current_time && !is_completed[x[i]] && x[i] != p) {
                    int found = 0;
                    // Check if process is already in queue
                    for (int j = front; j < rear; j++) {
                        if (queue[j] == x[i]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        queue[rear++] = x[i];  // Enqueue the new process
                    }
                }
            }
            
            // Re-enqueue the current process if it has remaining burst time
            if (bt_remaining[p] > 0) {
                queue[rear++] = p;  // Re-enqueue the process
            }
        } else {
            // If no process is in the queue, move the time forward
            current_time++;
            
            // Add processes that have arrived by now
            for (int i = 0; i < n; i++) {
                if (at[x[i]] <= current_time && !is_completed[x[i]]) {
                    queue[rear++] = x[i];
                    break;
                }
            }
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
    if (at[x[0]] > 0) {
        printf("----");  // Add idle time block if first process starts after time 0
    }
    for (int i = 0; i < exec_idx; i++) {
        printf("----");
    }
    printf("\n");

    // Middle part with process names
    printf("|");
    if (at[x[0]] > 0) {
        printf(" IDLE |");  // Show idle time if the first process starts after 0
    }
    for (int i = 0; i < exec_idx; i++) {
        printf(" P%d |", execution_order[i] + 1);
    }
    printf("\n");

    // Bottom border of the Gantt chart
    printf(" ");
    if (at[x[0]] > 0) {
        printf("----");
    }
    for (int i = 0; i < exec_idx; i++) {
        printf("----");
    }
    printf("\n");

    // Time markers at the bottom
    if (at[x[0]] > 0) {
        printf("0   %d", at[x[0]]);  // Add idle time marker
    } else {
        printf("0");
    }
    for (int i = 0; i < exec_idx; i++) {
        printf("   %d", exec_time_slice[i]); // Print the time marker after each process execution
    }
    printf("\n");

    // Print average TAT and WT
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
