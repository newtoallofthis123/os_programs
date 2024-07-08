#include <stdio.h>

struct process{
    int arrival_time;
    int burst_time;
    int tat;
}p[10], temp[10];

int main(){
    int count, n, wait_time, tat, i, total;

    printf("Total Processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of the processes: \n");
    for(i = 0; i < n; i++){
        printf("P[%d]: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }
    // simulate shortest job first algorithm
    for(i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].burst_time > p[j].burst_time){
                temp[i] = p[i];
                p[i] = p[j];
                p[j] = temp[i];
            }
        }
    }

    printf("Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(total = 0, i = 0; n != 0;){
        total += p[i].burst_time;
        wait_time = total - p[i].arrival_time - p[i].burst_time;
        tat = total - p[i].arrival_time;
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i].arrival_time, p[i].burst_time, wait_time, tat);
        n--;
        i++;
    }
}
