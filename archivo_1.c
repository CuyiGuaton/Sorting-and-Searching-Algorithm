#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char const *argv[]) {

/* Se Abre el archivo  */
  FILE *inputfile;
  char c;
  int largo = 0;
  char *array = (char *)malloc(50000*sizeof(char *));
  inputfile = fopen("archivo_1.tex", "r");
  if (inputfile == NULL) {
      fprintf(stderr, "Failed to open the file.\n");
      exit(1);
  }
  if (inputfile) {
      for ( int i=0; (c = getc(inputfile)) != EOF; i++){
          array[i] = c;
          //putchar(a[i]);
          largo++;
      }
      fclose(inputfile);
  }

  clock_t start_t, end_t, total_t;
  start_t = clock();

/* Desde aquí empieza el proceso de busqueda del número de 4 digitos que más se repite */

  int *arrayFreq = (int*)calloc(10000, sizeof(int)); // crea un arreglo que va del 0 al 9999
  char key[2]; // key guarda temporalmente un strig de 4 caracteres del arreglo
  int number; // convierte el string obtenido en número
  int mayor = 0; // para obtener el mayor de los elementos
  for (size_t i = 0; i < largo; i++) {
    strncpy(key, array, 4); // se copia un string de largo 4 del largo a a key
    number = atoi(key); // se tranforma el string obtenido a int
    arrayFreq[number] +=1; // se suma aumenta en 1 la posición del arreglo obtenidn.
    if(arrayFreq[number] >= mayor) // calcula la mayor frecuencia obtenida en todo el proceso
      mayor = arrayFreq[number];
    array+=1; // se avanza en 1 el punto del arreglo a, así se va a avanzando de posición en 1 en a.
  }
  for (int i = 0; i < 10000; i++) {
    if( arrayFreq[i] == mayor ) // se busca el lemento de mayor frecuencia en a.
      printf("El número que más se repite es %i con %i repeticiones\n", i,arrayFreq[i] );
  }

  end_t = clock();

  printf("\n time: %f segundos",  (double)(end_t - start_t) / CLOCKS_PER_SEC);

  free(arrayFreq);
  return 0;
}
