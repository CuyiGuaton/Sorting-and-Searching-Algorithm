#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quicksort(int *A, int len);

//Algoritmo de ordenamiento quicksort
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
  /* Se Abre el archivo  */
  FILE *inputfile;
  char c; // guarda cada caracter leido
  int largo = 0;
  char *array = (char *)malloc(120000*sizeof(char *)); // array donde se guardan los elementos del arreglo
  inputfile = fopen("archivo_3.tex", "r");
  if (inputfile == NULL) {
      fprintf(stderr, "Failed to open the file.\n");
      exit(1);
  }
  if (inputfile) {
      for ( int i=0; (c = getc(inputfile)) != EOF; i++){
          array[i] = c;
          largo++;
      }
      fclose(inputfile);
  }

  clock_t start_t, end_t, total_t;
  start_t = clock();
  int *splitArray = malloc((largo/6)*sizeof(int *));

  // se divide el arreglo a en segmentos de números de largo 6.
  for (size_t i = 0; i < largo/6; i++) {
    splitArray[i] = atoi(strndup(array + 6 * i, 6));
  }

  /* Se ordena el arreglo  */
  quicksort(splitArray, largo/6);

  /* Se muestran los elementos ordenados y se cuenta cuantas veces se repite*/
  int freq = 1;
  int aux = splitArray[0];
  for (size_t i = 1; i < largo/6  ; i++) {
    if (splitArray[i] == aux) { // si el elemento se repite su frecuencia aumenta.
      freq++;
    }
    else{ // si el siguiente elemento es distinto al anterior entonces se muestra con las veces que se repitio
      if (freq > 1)
          printf("%06i - %i\n", splitArray[i],freq);
      freq = 1;
      aux = splitArray[i];
    }
  }
  end_t = clock();
  printf("\n time: %f segundos",  (double)(end_t - start_t) / CLOCKS_PER_SEC);
  free(splitArray);
  free(array);
  return 0;
}
