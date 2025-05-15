#include <stdio.h>
#include <limits.h>
// updated sjf
int main()
{
    int n;
    printf("Enter the number of programs: ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    int iscom[n], tcom = 0, ctime = 0;
    int eidx = 0, exorder[100];
   

    for (int i = 0; i < n; i++)
    {
        printf("For program P%d:\n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        iscom[i] = 0;
    }

    while (tcom < n)
    {
        int minidx = -1;
        int minbt = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= ctime && !iscom[i] && bt[i] < minbt)
            {
                minbt = bt[i];
                minidx = i;
            }
        }
        if (minidx != -1)
        {
            ct[minidx] = ctime + bt[minidx];
            tat[minidx] = ct[minidx] - at[minidx];
            wt[minidx] = tat[minidx] - bt[minidx];
            ctime += bt[minidx];
            iscom[minidx] = 1;
            tcom++;
            exorder[eidx++] = minidx;
        }
        else
        {
            exorder[eidx++] = -1;
            ctime++;
        }
    }

    printf("\n PID    AT    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Gantt Chart:\n");

    printf(" | ");
    for (int i = 0; i < eidx; i++)
    {
        if (exorder[i] == -1)
            printf(" idle | ");
        else
            printf(" P%d | ", exorder[i] + 1);
    }
    printf("\n");

    printf(" 0 ");
    ctime = 0;
    for (int i = 0; i < eidx; i++)
    {
        if (exorder[i] == -1)
        {
            ctime++;
            printf("     %d ", ctime);
        }
        else
        {
            ctime = ct[exorder[i]];
            printf("     %d ", ctime);
        }
    }
    printf("\n");

    return 0;
}