#include <stdio.h>
#include <limits.h>
int main()
{
    int n, ishigh;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Is high priority scheduling (1 for yes, 0 for no): ");
    scanf("%d", &ishigh);
    int at[n], bt[n], pt[n], ct[n], tat[n], wt[n];
    int iscom[n],ncom = 0;
    int rt[n],ctime = 0;
    int  exorder[100], exidx = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter at bt priority for process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pt[i]);
        rt[i] = bt[i];
        iscom[i] = 0;
    }

    while (ncom < n)
    {
        int spt = ishigh ? -1 : INT_MAX;
        int idx = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= ctime && !iscom[i])
            {
                if ((ishigh && pt[i] > spt) || (!ishigh && pt[i] < spt))
                {
                    idx = i;
                    spt = pt[i];
                }
            }
        }

        if (idx != -1)
        {
            rt[idx]--;
            exorder[exidx++] = idx;
            ctime++; 

            if (rt[idx] == 0)
            {
                ct[idx] = ctime;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                iscom[idx] = 1;
                ncom++;
            }
        }
        else
        {
            exorder[exidx++] = -1; // Idle period
            ctime++;
        }
    }

    printf("PID    AT    BT    PT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d     %d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], pt[i], ct[i], tat[i], wt[i]);
    }
// Display the Gantt Chart
    printf("\nGantt Chart:\n");
   
    int lastProcess = -2; // Initialize to a value that cannot be a process index
    printf(" | ");
    for (int i = 0; i < exidx; i++)
    {
        if (exorder[i] != lastProcess)
        {
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
       
    }

    printf("\n");
    printf(" 0 ");
    lastProcess = -2;
    ctime = 0;

    for (int i = 0; i < exidx; i++)
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
    printf("\n");
    return 0;
}
