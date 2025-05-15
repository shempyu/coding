#include <stdio.h>
#include <limits.h>
// srtf
int main()
{
    int n;
    printf("Enter the number of programs: ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    int iscom[n],rt[n] ,tcom = 0, ctime = 0;
    int eidx = 0, exorder[100];
   

    for (int i = 0; i < n; i++)
    {
        printf("For program P%d:\n", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        iscom[i] = 0;
    }

    while (tcom < n)
    {
        int idx = -1;
        int minrt = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= ctime && !iscom[i] && rt[i] >0 &&
               (rt[i] < minrt || (rt[i] == minrt && at[i] < at[idx] )))
            {
                minrt = bt[i];
                idx = i;
            }
        }
        if (idx != -1)
        {
            rt[idx]--;
            ctime++;
            exorder[eidx++] = idx;

           if(rt[idx] == 0){

                 ct[idx] = ctime;
                 tat[idx] = ct[idx] - at[idx];
                  wt[idx] = tat[idx] - bt[idx];
                  iscom[idx] = 1;
                  tcom++;
           }  
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