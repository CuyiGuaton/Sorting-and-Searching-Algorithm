#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quicksort(int *A, int len);

void quicksort(int *A, int len)
{
  if (len < 2) return;

  int pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;

    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}


int main(int argc, char const *argv[]) {

  //abre el archivo
  FILE *inputfile;
  char c;
  int largo = 0;
  char *a = (char *)malloc(12000*sizeof(char *));
  inputfile = fopen("archivo_3.tex", "r");
  if (inputfile == NULL) {
      fprintf(stderr, "Failed to open the file.\n");
      exit(1);
  }
  if (inputfile) {
      for ( int i=0; (c = getc(inputfile)) != EOF; i++){
          a[i] = c;
          //putchar(a[i]);
          largo++;
      }
      fclose(inputfile);
  }

  clock_t start_t, end_t, total_t;
  start_t = clock();
  int *splitArray = malloc((largo/6)*sizeof(int *));
  for (size_t i = 0; i < largo/6; i++) {
    splitArray[i] = atoi(strndup(a + 6 * i, 6));
  }
  quicksort(splitArray, largo/6);
  for (size_t i = 0; i < largo/6  ; i++) {
    if (splitArray[i+1] == splitArray[i]) {
      printf("%06i\n", splitArray[i]);
    }
  }

  end_t = clock();
  printf("\n time: %f segundos",  (double)(end_t - start_t) / CLOCKS_PER_SEC);
  free(a);
  return 0;
}
