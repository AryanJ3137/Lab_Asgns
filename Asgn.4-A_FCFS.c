#include <stdio.h>

struct Process{
    int pid;
    int at, bt, st, ct, tat, wt;
};

int main(){
    int n, i, j;
    float avg_tat = 0, avg_wt = 0;
    int current_time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], temp;

    for (i = 0; i < n; i++){
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (p[j].at > p[j + 1].at){
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++){
        if (current_time < p[i].at)
            current_time = p[i].at;
        
        p[i].st = current_time;
        p[i].ct = p[i].st + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        current_time = p[i].ct;

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }

    printf("\n\n----FCFS Scheduling----\n");
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt);
    }


    printf("\nGantt Chart:\n");

    printf(" ");
    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n|");

    for (i = 0; i < n; i++)
        printf("  P%d   |", p[i].pid);

    printf("\n ");

    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n");

    printf("%d", p[0].st);

    for (i = 0; i < n; i++)
        printf("\t%d", p[i].ct);

    printf("\n");

    avg_tat = avg_tat / n;
    avg_wt = avg_wt / n;

    printf("\nAverage TAT = %.2f", avg_tat);
    printf("\nAverage WT = %.2f\n", avg_wt);

    return 0;
}
