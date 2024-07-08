// To simulate least recently used page replacement algorithm.
#include <stdio.h>

int main(){
    int i, j, a[50],frame[10], no, k, avail, count = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &no);
    printf("Enter the page numbers: ");
    for(i = 1; i <= no; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &no);
    for(i = 0; i < no; i++){
        frame[i] = -1;
    }
    j = 0;
    printf("Ref String\tPage Frames\n");
    for(i = 1; i <= no; i++){
        printf("%d\t\t", a[i]);
        avail = 0;
        for(k = 0; k < no; k++){
            if(frame[k] == a[i]){
                avail = 1;
            }
        }
        if(avail == 0){
            frame[j] = a[i];
            j = (j+1)%no;
            count++;
            for(k = 0; k < no; k++){
                printf("%d\t", frame[k]);
            }
        }
        printf("\n");
        printf("Page Fault is %d\n", count);
    }
}
