#include<stdio.h>
#include<limits.h>
int main()
{
    int n,qt;
    printf("enter no pf process and quntam time: ");
    scanf("%d %d",&n,&qt);
    
    int at[n],bt[n],ct[n],tat[n],wt[n],x[n];
    int iscom[n],rt[n],ncom=0,ctime=0;
    int q[100],rear = 0,front =0;
    int exorder[100],extime[n],exidx = 0;

    for(int i = 0;i<n;i++){
        printf("for p%d enter at bt: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        iscom[i] = 0;
        rt[i] = bt[i];
        x[i] = i;
    }
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
    while(ncom < n)
    {
        int idx = -1;
        for(int i = 0;i<n;i++)
        {
             if(at[x[i]]<=ctime && !iscom[x[i]] )
             {
                idx = i;
             break;
             }
        }
        if(idx != -1){
            
        }
        
        
    }
   
    return 0;
}