#include <stdio.h>
#include <limits.h>

int main(){
    int n,at[10],bt[10],rt[10],pr[10],ct[10],tat[10],wt[10];
    int i,time=0,complete=0,min,p;
    float avgtat=0, avgwt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(complete<n){
        min=INT_MAX;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && pr[i]<min){
                min=pr[i];
                p=i;
            }
        }

        rt[p]--;
        time++;

        if(rt[p]==0){
            complete++;
            ct[p]=time;
            tat[p]=ct[p]-at[p];
            wt[p]=tat[p]-bt[p];

            avgtat += tat[p];
            avgwt += wt[p];
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    printf("\nAverage Turnaround Time = %.2f", avgtat/n);
    printf("\nAverage Waiting Time = %.2f", avgwt/n);

    return 0;
}
