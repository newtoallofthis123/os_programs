// simulate sequential file allocation

#include <stdio.h>
#include <string.h>

int main() {
  int st[20], b[20], b1[20], ch, i, j, c, n, blocks[20][20], sz[20];
  char F[20][20], S[20];
  printf("Enter the number of files: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter the file name: ");
        scanf("%s", F[i]);
        printf("Enter the file size: ");
        scanf("%d", &sz[i]);
        printf("Enter the starting block of %s: ", F[i]);
        scanf("%d", &st[i]);
        printf("Enter block size: ");
        scanf("%d", &b[i]);
    }
    for(i = 0; i < n; i++)
        b[i] = sz[i] * 1024 / b[i];
    for(i = 0; i < n; i++){
        for(j = 0; j < b[i]; j++){
            blocks[i][j] = st[i] + j;
        }
    }
    do{
        printf("Enter the filename: ");
        scanf("%s", S);
        for(i = 0; i < n; i++){
            if(strcmp(S, F[i]) == 0){
                for(j = 0; j < b[i]; j++){
                    printf("%d->%s\n", blocks[i][j], F[i]);
                }
                break;
            }
        }
    } while(i != n);
}
