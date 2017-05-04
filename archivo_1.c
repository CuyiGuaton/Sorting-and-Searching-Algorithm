#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char const *argv[]) {

/* Se Abre el archivo  */
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

/* Desde aquí empieza el proceso de busqueda del número de 4 digitos que más se repite */

  int *b = (int*)calloc(10000, sizeof(int)); // crea un arreglo que va del 0 al 9999
  char key[2]; // key guarda temporalmente un strig de 4 caracteres del arreglo
  int number; // convierte el string obtenido en número
  int mayor = 0; // para obtener el mayor de los elementos
  for (size_t i = 0; i < largo; i++) {
    strncpy(key, a, 4); // se copia un string de largo 4 del largo a a key
    number = atoi(key); // se tranforma el string obtenido a int
    b[number] +=1; // se suma aumenta en 1 la posición del arreglo obtenidn.
    if(b[number] >= mayor) // calcula la mayor frecuencia obtenida en todo el proceso
      mayor = b[number];
    a+=1; // se avanza en 1 el punto del arreglo a, así se va a avanzando de posición en 1 en a.
  }
  for (int i = 0; i < 10000; i++) {
    if( b[i] == mayor ) // se busca el lemento de mayor frecuencia en a.
      printf("b[%i] = %i\n", i,b[i] );
  }

  end_t = clock();

  printf("\n time: %f segundos",  (double)(end_t - start_t) / CLOCKS_PER_SEC);

  free(b);
  return 0;
}
