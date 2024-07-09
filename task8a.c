// Best fit algorithm for memory management
#include <stdio.h>
#define max 25

int main() {
  int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
  static int bf[max], ff[max];
  printf("Enter the number of blocks: ");
  scanf("%d", &nb);
  printf("Enter the number of files: ");
  scanf("%d", &nf);
  printf("Enter the size of the blocks: ");
  for (i = 1; i <= nb; i++) {
    printf("Block %d: ", i);
    scanf("%d", &b[i]);
  }
  printf("Enter the size of the files: ");
  for (i = 1; i <= nf; i++) {
    printf("File %d: ", i);
    scanf("%d", &f[i]);
  }
  for (i = 1; i <= nf; i++) {
    for (j = 1; j <= nb; j++) {
      if (bf[j] != 1) {
        temp = b[j] - f[i];
        if (temp >= 0 && lowest > temp) {
          ff[i] = j;
          lowest = temp;
        }
      }
    }
    frag[i] = lowest;
    bf[ff[i]] = 1;
    lowest = 10000;
  }
  printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
  for (i = 1; i <= nf && ff[i] != 0; i++) {
    printf("%d\t%d\t%d\t%d\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
  }
  return 0;
}
