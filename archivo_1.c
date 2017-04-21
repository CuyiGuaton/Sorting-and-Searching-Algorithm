#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]) {

  //abre el archivo
  FILE *inputfile;
  char c;
  int largo = 0;
  char *a = (char *)malloc(50000*sizeof(char *));;
  char *b = (char *)malloc(50000*sizeof(char *));;
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

  printf("El largo de la mierda es %i\n", largo);

  char key[4];
  int aux = 0;
  int freq = 0;
  int k;
  for (int i = 0; i < 10000; i++) {
    sprintf(key,"%04d",i);  
    for (size_t j = 0; j < largo-4; j++) {
      k =0;
      while(k <4 && a[j+k] == key[k])
        k=k+1;
      if(k == 4){ //Aquí encontro el string
          for (size_t t = 0; t < 4; t++) {
            printf("%c", key[t]);
          }
          printf("\n" );
        //freq++;
      }
    }

  }
  free(a);
  return 0;
}
