#include <stdio.h>

#define MAX 20

int main() {
    int n;
    int pid[MAX], at[MAX], bt[MAX], pr[MAX];
    int rt[MAX];   // Remaining time
    int ct[MAX], tat[MAX], wt[MAX];
    int isCompleted[MAX] = {0};

    int i, time = 0, completed = 0;
    int minPr, idx;
    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Process Details:\n");
    printf("PID  ArrivalTime  BurstTime  Priority\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d %d %d", &pid[i], &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];   // initialize remaining time
    }

    printf("\n--- Gantt Chart ---\n");

    while(completed < n) {
        minPr = 50;
        idx = -1;

        // Find highest priority process available at current time
        for(i = 0; i < n; i++) {
            if(at[i] <= time && isCompleted[i] == 0 && rt[i] > 0) {
                if(pr[i] < minPr) {
                    minPr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            // Execute process for 1 unit time
            printf("| P%d ", pid[idx]);
            rt[idx]--;
            time++;
            // If process finishes
            if(rt[idx] == 0) {
                ct[idx] = time;
                isCompleted[idx] = 1;
                completed++;
            }
        } else {
            // CPU Idle
            printf("| Idle ");
            time++;
        }
    }
    printf("|\n");

    // Calculate TAT and WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT  += wt[i];
    }
    avgTAT /= n;
    avgWT  /= n;

    // Output Table
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", avgTAT);
    printf("\nAverage Waiting Time    = %.2f\n", avgWT);
    return 0;
}