#include <stdio.h>

// To implement paging technique of memory management
int main(){
    int np, ps,pt[20],nf,la,pn,index,pa, i, j;
    printf("Enter number of pages: \n");
    scanf("%d", &np);
    printf("Enter the page size: \n");
    scanf("%d", &ps);
    printf("Enter the number of frames: \n");
    scanf("%d", &nf);
    printf("Enter the page table");
    for(i = 0; i < np; i++){
        scanf("%d", &pt[i]);
    }
    printf("Enter the logical address: \n");
    scanf("%d", &la);
    pn = la/ps;
    index = la%ps;
    pa = pt[pn]*ps + index;
    printf("The physical address is: %d\n", pa);
}
