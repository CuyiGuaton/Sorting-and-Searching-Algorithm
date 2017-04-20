#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  FILE *inputfile;
  int c;
  int largo = 0;
  char *a = (char *)malloc(8337*sizeof(char *));;
  inputfile = fopen("archivo_2.tex", "r");

  if (inputfile == NULL) {
      fprintf(stderr, "Failed to open the file\n");
      exit(1);
  }
  if (inputfile) {
      for ( int i=0; (c = getc(inputfile)) != EOF; i++){
          a[i] = c - '\0';
          putchar(a[i]);
          largo++;
      }
      fclose(inputfile);
  }

  printf("El largo de la mierda es %i\n", largo);


  free(a);
  return 0;
}