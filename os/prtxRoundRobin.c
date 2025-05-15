#include <stdio.h>

int main()
{
    int n, tq;

    printf("enter the nu of proces: and q time ");
    scanf("%d %d,&n,&tq");

    int at[n], bt[n], ct[n], tat[n], wt[n], x[n];
    int iscom[n],ncom = 0;
    int rt[n],ctime = 0;
    int  q[100], front = 0,rear = 0;
    int  exorder[100], extime[100],exidx = 0;

    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("For program P%d: ", i + 1);
        printf("Enter arrival time and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; 
        iscom[i] = 0;  
        x[i] = i;      // Store original process index for sorting
    }

    // Sort processes by arrival time using `x[i]`
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[x[i]] > at[x[j]])
            {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    // Handle idle time before the first process starts
  if (at[x[0]] > 0)
   {
     exorder[exidx] = -1;         
     extime[exidx++] = at[x[0]]; 
     ctime = at[x[0]];           
   }
    q[rear++] = x[0];     // Enqueue the first arriving process
    
    while (ncom < n)
    {
        if (front < rear)
        {
            int p = q[front++];
            
            int t = rt[p] > tq ? tq : rt[p];                  // Execute the process for the time quantum or remaining time
            ctime += t;
            rt[p] -= t;

            exorder[exidx] = p;
            extime[exidx++] = ctime;

            if (rt[p] == 0)
            {
                ct[p] = ctime;
                tat[p] = ct[p] - at[p];
                wt[p] = tat[p] - bt[p];
                iscom[p] = 1;
                ncom++;
            }

            // Add new processes to the queue up to the cureent time
            for (int i = 0; i < n; i++)
            {
                if (at[x[i]] <= ctime && !iscom[x[i]] && x[i] != p)
                {
                    int found = 0;
                    // Check if process is already in queue
                    for (int j = front; j < rear; j++)
                    {
                        if (q[j] == x[i])
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                        q[rear++] = x[i]; // Enqueue the new process
                }
            }

            // Re-enqueue the current process if not finished
            if (rt[p] > 0)
            q[rear++] = p;
        }
        else
        {
            // If no process is ready, system is idle
            ctime++;
            exorder[exidx++] = -1; // Add an idle time placeholder
            for (int i = 0; i < n; i++)
            {
                if (at[x[i]] <= ctime && !iscom[x[i]])
                {
                    q[rear++] = x[i];
                    break;
                }
            }
        }
    }

    // Print the results
    printf("\n PID    AT    BT    CT    TAT    WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\nGantt Chart:\n");
    printf(" | ");

    for (int i = 0; i < exidx; i++)
    {
        if (exorder[i] == -1)
            printf(" idle "); 
        else
            printf(" P%d ", exorder[i] + 1); 
        printf(" | ");
    }
    printf("\n");

    printf(" 0 "); 
    for (int i = 0; i < exidx; i++)
    {
        printf("     %d ", extime[i]); 
    }
    printf("\n");

    // Print averages
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
    printf("Average Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
