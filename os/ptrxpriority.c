#include <stdio.h>
#include <limits.h>
int main()
{
   int n, ishigh;
   printf("enetr size: ");
   scanf("%d", &n);
   printf("is high p is high 1 y 0 n: ");
   scanf("%d", &ishigh);
   int at[n], bt[n], pt[n], ct[n], tat[n], wt[n];
   int iscom[n], ncom = 0, ctime = 0;
   int exidx = 0, exorder[2 * n];
   for (int i = 0; i < n; i++)
   {
      printf(" %d enter birst at pt: ", i + 1);
      scanf("%d %d %d", &at[i], &bt[i], &pt[i]);
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
         ctime += bt[idx];
         ct[idx] = ctime;
         tat[idx] = ct[idx] - at[idx];
         wt[idx] = tat[idx] - bt[idx];

         iscom[idx] = 1;
         ncom++;

         exorder[exidx++] = idx;
      }
      else
      {
         exorder[exidx++] = -1;
         ctime++;
      }
   }

   printf("pid    at    bt    pt    ct    tat    wt\n");
   for (int i = 0; i < n; i++)
   {
      printf("p%d     %d     %d     %d     %d     %d     %d\n", i + 1, at[i], bt[i], pt[i], ct[i], tat[i], wt[i]);
   }
   printf("\ngant\n");
   printf(" | ");
   for (int i = 0; i < exidx; i++)
   {
      if (exorder[i] == -1)
      {
         printf(" idle | ");
      }
      else
      {
         printf(" p%d | ", exorder[i] + 1);
      }
   }
   printf("\n");
   printf(" 0 ");
   ctime = 0;
   for (int i = 0; i < exidx; i++)
   {
      if (exorder[i] == -1)
      {
         ctime++;
         printf("    %d ", ctime);
      }
      else
      {
         ctime = ct[exorder[i]];
         printf("    %d ", ctime);
      }
   }
   return 0;
}
