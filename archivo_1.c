#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  FILE *inputfile;
  int c;
  int largo = 0;
  char *a = (char *)malloc(50000*sizeof(char *));;
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

  int key[4] = {0,0,0,0};
  int aux = 0;
  for (size_t i = 0; i < 1000; i++) {
    /*
      key[0]= i/1000 >=1 ? i/1000 : 0 ;
      key[1]= i/100 >=1 ? i/100 : 0 ;
      key[2]= i/10 >=1 ? i/10 : 0 ;
      key[3]= i % 10;
      */
      aux = i;
      key[3]= aux/10 <100 ? aux%10 : 0 ;
      aux/=10;
      key[2]= aux/10 <10 ? aux%10 : 0 ;
      aux/=10;
      key[1]= aux/10 <1 ? aux%10 : 0 ;
      key[0]= aux%10;

      for (size_t j = 0; j < 4; j++) {
        printf("%i", key[j]);
      }
      printf("\n");
  }


  free(a);
  return 0;
}
