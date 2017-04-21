#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int busqueda(char key[4], char* a, int largo);

int busqueda(char key[4], char* a, int largo){
  int freq=0;
  int k;
  for (int j = 0; j < largo-4; j++) { // Aquí empíeza la busqueda
    k =0;
    while(k <4 && key[k] == a[j+k])
      k=k+1;
    if(k == 4) //Aquí encontro el string
        freq++;
  }
  return freq;
}

int main(int argc, char const *argv[]) {

  //abre el archivo
  FILE *inputfile;
  char c;
  int largo = 0;
  char *a = (char *)malloc(50000*sizeof(char *));
  inputfile = fopen("archivo_1.tex", "r");
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
  char key[5]; //key es de largo 5 para dejar espacio al end of string character
  int freq;
  int M = 0;
  int resultFreq[10000]; //Guarda las frecencias de la llave que tenga como indice
  for (int i = 0; i < 10000; i++) {
    sprintf(key,"%04i",i); // guarda el deicmal i de 4 digitos en key, se rellena con 0 si tiene menos de 4 digitos
    freq = busqueda(key,a,largo);
    if(freq > M)
      M=freq;
    resultFreq[i]=freq; //no es necesario guardar la llave ya que será igual a su indice
  }
  printf("Los números más repetidos son:\n", M);
  for (size_t i = 0; i < 10000; i++)
    if (resultFreq[i] == M)
      printf("%04i se repite %i veces\n", i,resultFreq[i] );

    end_t = clock();
  printf("\n time: %f segundos",  (double)(end_t - start_t) / CLOCKS_PER_SEC);
  free(a);
  return 0;
}
