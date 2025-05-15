#include <stdio.h>
#include <limits.h>
//SRTF
int main()
{
    int n;
    printf("Enter the number of programs: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    int iscom[n], tcom = 0;
    int eidx = 0, exorder[3 * n];
    int ctime = 0;

    // Input arrival and burst times
    for (int i = 0; i < n; i++)
    {
        printf("For program P%d:\n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initialize remaining burst time to total burst time
        iscom[i] = 0;   // Set process completion flag to 0 (not completed)
    }

    // Run the SRTF algorithm to schedule processes
    while (tcom < n)
    {
        int minidx = -1;
        int minrt = INT_MAX;

        // Find the process with the shortest remaining burst time that has arrived first
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= ctime && !iscom[i] && rt[i] > 0 && 
        (rt[i] < minrt || (rt[i] == minrt && at[i] < at[minidx])))
            {
                minrt = rt[i];
                minidx = i;
            }
        }

        // If a process is selected, execute it
        if (minidx != -1)
        {
            // Process is executed for 1 unit of time
            rt[minidx]--;
            exorder[eidx++] = minidx;

            // If remaining time is zero, process is completed
            if (rt[minidx] == 0)
            {
                ct[minidx] = ctime + 1;  // Completion time is current time + 1
                tat[minidx] = ct[minidx] - at[minidx];  // Turnaround time = CT - AT
                wt[minidx] = tat[minidx] - bt[minidx];  // Waiting time = TAT - BT
                iscom[minidx] = 1;  // Mark process as completed
                tcom++;  // Increment the number of completed processes
            }
            ctime++;  // Increase time by 1 unit after each process execution
        }
        else
        {
            // If no process is ready, system is idle
            exorder[eidx++] = -1;  // Mark as idle
            ctime++;  // Increase time by 1 unit
        }
    }

    // Print the results: PID, AT, BT, CT, TAT, WT
    printf("\n PID    AT    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Display the Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" | ");
    for (int i = 0; i < eidx; i++)
    {
        if (exorder[i] == -1)
        {
            printf(" idle | ");
        }
        else
        {
            printf(" P%d | ", exorder[i] + 1);
        }
    }
    printf("\n");

    // Display the corresponding time stamps
    printf(" 0 ");
    ctime = 0;
    for (int i = 0; i < eidx; i++)
    {
        if (exorder[i] == -1)
        {
            ctime++;
            printf("    %d ", ctime);
        }
        else
        {
            ctime++;
            printf("    %d ", ctime);
        }
    }
    printf("\n");

    return 0;
}
