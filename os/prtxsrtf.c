#include <stdio.h>
#include <limits.h>
// SRTF
int main()
{
    int n;
    printf("Enter the number of programs: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    int iscom[n], tcom = 0;
    int eidx = 0, exorder[100];
    int ctime = 0;

    // Input arrival and burst times
    for (int i = 0; i < n; i++)
    {
        printf("For program P%d:\n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initialize remaining burst time to total burst time
        iscom[i] = 0;  // Set process completion flag to 0 (not completed)
    }

    // Run the SRTF algorithm to schedule processes
    while (tcom < n)
    {
        int idx = -1;
        int minrt = INT_MAX;

        // Find the process with the shortest remaining burst time that has arrived first
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= ctime && !iscom[i] && rt[i] > 0 &&
                (rt[i] < minrt || (rt[i] == minrt && at[i] < at[idx])))
            {
                minrt = rt[i];
                idx = i;
            }
        }

        // If a process is selected, execute it
        if (idx != -1)
        {
            // Process is executed for 1 unit of time
            rt[idx]--;
            exorder[eidx++] = idx;
            ctime++; 

            // If remaining time is zero, process is completed
            if (rt[idx] == 0)
            {
                ct[idx] = ctime;           // Completion time is current time + 1
                tat[idx] = ct[idx] - at[idx]; // Turnaround time = CT - AT
                wt[idx] = tat[idx] - bt[idx]; // Waiting time = TAT - BT
                iscom[idx] = 1;                     // Mark process as completed
                tcom++;                                // Increment the number of completed processes
            }
            
        }
        else
        {
            // If no process is ready, system is idle
            exorder[eidx++] = -1; // Mark as idle
            ctime++;              // Increase time by 1 unit
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

    // Print process names
    printf(" | ");
    int lastProcess = -2; // Initialize to a value that cannot be a process index
    ctime = 0;

    for (int i = 0; i < eidx; i++)
    {
        if (exorder[i] != lastProcess)
        {
            // Print the process or idle
            if (exorder[i] == -1)
            {
                printf(" idle ");
            }
            else
            {
                printf(" P%d ", exorder[i] + 1);
            }

            printf(" | ");
            lastProcess = exorder[i];
        }
        ctime++;
    }

    printf("   \n0 ");
    lastProcess = -2;
    ctime = 0;

    for (int i = 0; i < eidx; i++)
    {
        if (exorder[i] != lastProcess)
        {
            if (lastProcess != -2) // Avoid printing for the first process
            {
                printf("     %d ", ctime); // Print the timestamp below the process name
            }
            lastProcess = exorder[i];
        }
        ctime++;
    }
    printf("     %d\n", ctime); // Final timestamp

    return 0;
}
