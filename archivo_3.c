#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int busqueda(char key[10], char* a, int largo);

int busqueda(char key[10], char* a, int largo){
  int freq=0;
  int k;
  for (int j = 0; j < largo-6; j++) { // Aquí empíeza la busqueda
    k =0;
    while(k <6 && key[k] == a[j+k])
      k=k+1;
    if(k == 6) //Aquí encontro el string
        freq++;
  }
  return freq;
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

  char key[2]; //key es de largo 5 para dejar espacio al end of string character
  int freq;
  for (int i = 0; i < largo; i+=6) {
    strncpy(key, a, 6);
    freq = busqueda(key,a,largo);
    if(freq > 1)
      printf("%s - %i\n",key,freq );
    a+=6;
  }

  end_t = clock();
  printf("\n time: %f segundos",  (double)(end_t - start_t) / CLOCKS_PER_SEC);
  free(a);
  return 0;
}
