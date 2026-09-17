#include <stdio.h>

struct Process{
	int pid;
	int at, bt, rt, ct, tat, wt;
};

int main(){
	int n;
	int curr_time=0, completed=0;
	float avg_tat=0, avg_wt=0;
	int gantt[20];
    int start[20];
    int end[20];
    int gc = 0;
	
	printf("No. of process= ");
	scanf("%d",&n);
	
	struct Process p[n];
	
	for(int i=0;i<n;i++){
		p[i].pid = i+1;
		printf("Arrival Time of P%d= ",i+1);
		scanf("%d",&p[i].at);
		
		printf("Burst Timr of P%d= ",i+1);
		scanf("%d",&p[i].bt);
		
		p[i].rt = p[i].bt;
	}
	
	while(completed<n){
		int shortest=-1;
		for(int i=0;i<n;i++){
			if(p[i].at<= curr_time && p[i].rt>0){
				if(shortest==-1 || p[i].rt<p[shortest].rt){
					shortest=i;
				}
			}
		}
		
		if(shortest==-1){
			curr_time++;
			continue;
		}
		
		if (gc == 0 || gantt[gc-1] != p[shortest].pid){
            gantt[gc]=p[shortest].pid;
            start[gc]=curr_time;
            end[gc]=curr_time + 1;
            gc++;
        }
        else
            end[gc-1] = curr_time + 1;
		
		p[shortest].rt--;
		curr_time++;
		
		if(p[shortest].rt==0){
			completed++;
			
			p[shortest].ct=curr_time;
			p[shortest].tat=p[shortest].ct - p[shortest].at;
			p[shortest].wt= p[shortest].tat - p[shortest].bt;
			
			avg_tat+=p[shortest].tat;
			avg_wt+=p[shortest].wt;
		}
	}
	
	printf("\n\n----SRTF Scheduling----\n");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
	
	printf("\n\n----Gantt Chart----\n\n");

    printf(" ");
    for(int i = 0; i < gc; i++){
        printf("--------");
    }

    printf("\n|");

    for(int i = 0; i < gc; i++){
        printf("  P%d   |", gantt[i]);
    }

    printf("\n ");

    for(int i = 0; i < gc; i++){
        printf("--------");
    }

    printf("\n");

    printf("%d", start[0]);

    for(int i = 0; i < gc; i++){
        printf("\t%d", end[i]);
    }
    
    printf("\n");
    
    return 0;
}
