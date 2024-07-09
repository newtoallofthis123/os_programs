#include <stdio.h>

// To simulate the round robin algorithm
int main(){
    int count, total, n, wait_time = 0, tat = 0, i, quantum;
    int arrival_time[10], burst_time[10], temp[10];

    printf("Enter no of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of the processes: \n");
    for(i = 0; i < n; i++){
        printf("P[%d]: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(total = 0, i = 0; n != 0;){
        if(temp[i] <= quantum && temp[i] > 0){
            total += temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0){
            temp[i] -= quantum;
            total += quantum;
        }

        if(temp[i] == 0 && count == 1){
            n--;
            wait_time = total - arrival_time[i] - burst_time[i];
            tat = wait_time + burst_time[i];
            printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], wait_time, tat);
            count = 0;
        }

        if(i == n-1){
            i = 0;
        } else if (arrival_time[i+1] <= total){
            i++;
        } else {
            i = 0;
        }
    }
}
