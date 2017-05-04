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
        //  putchar(a[i]);
          largo++;
      }
      fclose(inputfile);
  }

  printf("El largo de la mierda es %i\n", largo);

  /* Desde aquí empieza el proceso de busqueda del número de 4 digitos que más se repite */
    int *hexarray = (int*)malloc(10000*sizeof(int)); // crea un arreglo que va del 0 al 9999
    char key[2]; // key guarda temporalmente un strig de 4 caracteres del arreglo
    int count = 0;
    for (int i = 0; i < largo-4; i++) {
      strncpy(key, a, 4); // se copia un string de largo 4 del largo a a key
      hexarray[i] = strtol(key, NULL, 16); // se tranforma el string obtenido a int hexadecimal
      printf("hexarray[%i] = %04X\n", i,hexarray[i] );
      count++;
      a+=1; // se avanza en 1 el punto del arreglo a, así se va a avanzando de posición en 1 en a.
    }


    free(hexarray);
  return 0;
}
