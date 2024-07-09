#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int alloc[MAX_PROCESSES][MAX_RESOURCES], int np, int nr) {
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

bool isSafe(int processes[], int avail[], int max[][MAX_RESOURCES], int alloc[][MAX_RESOURCES], int np, int nr) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, alloc, np, nr);

    bool finished[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];

    for (int i = 0; i < nr; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < np) {
        bool found = false;
        for (int p = 0; p < np; p++) {
            if (!finished[p]) {
                int j;
                for (j = 0; j < nr; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                if (j == nr) {
                    for (int k = 0; k < nr; k++) {
                        work[k] += alloc[p][k];
                    }
                    safeSequence[count++] = p;
                    finished[p] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < np; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main() {
    int np, nr;
    int processes[MAX_PROCESSES], avail[MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], alloc[MAX_PROCESSES][MAX_RESOURCES];

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("Enter the number of resources: ");
    scanf("%d", &nr);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < nr; i++) {
        scanf("%d", &avail[i]);
    }

    for (int i = 0; i < np; i++) {
        processes[i] = i;
    }

    isSafe(processes, avail, max, alloc, np, nr);

    return 0;
}
