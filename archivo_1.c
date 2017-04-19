#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  FILE *inputfile;
  int c;
  char a[50001];
  inputfile = fopen("archivo_1.tex", "r");

  if (inputfile == NULL) {
      fprintf(stderr, "Failed to open %s.\n", inputfile);
      exit(1);
  }
  if (inputfile) {
      for ( int i=0; (c = getc(inputfile)) != EOF; i++){
          a[i] = c - '\0';
          putchar(a[i]);
      }
      fclose(inputfile);
  }


  return 0;
}
