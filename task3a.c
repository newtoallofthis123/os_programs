#include <stdio.h>

// To simulate the round robin algorithm
int main(){
    int count, total, tat, waiting_time, n, i, quantum;
    int at[10], bt[10], temp[10];

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter a time quantum");
    scanf("%d", &quantum);

    printf("Enter the Arrival Time and Burst time: ");
    for(i = 0; i < n; i++){
        printf("P[%d]: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp[i] = bt[i];
    }

    for(total = 0, i =0; n != 0;){
        if(temp[i] <= quantum && temp[i] > 0){
            total += temp[i];
            temp[i] = 0;
            count = 1;
        } else if(temp[i] > 0){
            temp[i] -= quantum;
            total += quantum;
        }
        if(temp[i] == 0 && count == 1){
            n--;
            tat = total - at[i];
            waiting_time = total - at[i] - bt[i];
            printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], waiting_time, tat);
        }
        if(i == n-1){
            i = 0;
        } else if(at[i+1] <= total){
            i++;
        } else{
            i = 0;
        }
    }
}
