#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("enetr the size: ");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],x[n];
    int iscom[n],tcom = 0,ctime = 0;
    int exidx =0,exorder[2*n];
    for(int i =0;i<n;i++){
        printf("%d enetr at bt pt: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        iscom[i] = 0;
        x[i] = i;
    }
       // Sorting processes based on arrival time (FCFS)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[x[i]] > at[x[j]]) {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    while(tcom<n){
        int idx = -1;
        for(int i = 0;i<n;i++){
            if(at[x[i]]<=ctime && !iscom[x[i]]){
                idx = x[i];
                break;
            }
        }
        if(idx != -1){
            ctime +=bt[idx];
            ct[idx] = ctime;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            iscom[idx] = 1;
            tcom ++;

            exorder[exidx++] = idx;

        }
        else{
            exorder[exidx++] = -1;
            ctime++;
        }
    }
    printf("pid    at     bt     pt    tat    wt\n");
    for(int i = 0;i<n;i++){
        printf("p%d     %d     %d     %d     %d     %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("gantt chart\n");
    printf("| ");
    for(int i = 0;i<exidx;i++){
        if(exorder[i] == -1)
        {
            printf("idle | ");
        }
        else{
            printf("p%d | ",exorder[i]+1);
        }
    }
    printf("\n");
printf("0 ");
ctime = 0;
     for(int i = 0;i<exidx;i++){
        if(exorder[i] == -1)
        {
            ctime++;
            printf("    %d ",ctime);
        }
        else{
            ctime = ct[exorder[i]];
              printf("    %d ",ctime);
        }
    }
    return 0;
}