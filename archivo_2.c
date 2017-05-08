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

  printf("El largo es: %i\n\n", largo);


  /* Desde aquí empieza el proceso de busqueda del número de 4 digitos que más se repite */
    int *hexarray = (int*)malloc(10000*sizeof(int)); // crea un arreglo que va del 0 al 9999
    char key[2]; // key guarda temporalmente un strig de 4 caracteres del arreglo
    int count = 0,i;
    for (i = 0; i < largo-4; i++) {
      strncpy(key, a, 4); // se copia un string de largo 4 del largo a a key
      hexarray[i] = strtol(key, NULL, 16); // se tranforma el string obtenido a int hexadecimal
//      printf("hexarray[%i] = %04X\n", i,hexarray[i] );
      count++;
      a+=1; // se avanza en 1 el punto del arreglo a, así se va a avanzando de posición en 1 en a.
    }

	// Ordenamiento por Insercion

	int temp, j;

	for (i = 1; i < largo-4; i++)
	{
		temp = hexarray[i];
		j = i - 1;
		while ( (hexarray[j] > temp) && (j >= 0) )
		{
			hexarray[j + 1] = hexarray[j];
			j--;
		}
		hexarray[j + 1] = temp;
	}


	// Mostrar Orden

	 printf("\n\nOrdenado por Inserción\n\n");

	for (i = 0; i < largo-4; i++)
	{
		printf("hexarray[%i] = %04X\n", i,hexarray[i] );
	}

	// Mostrar cantidad de repeticiones

	printf("\n\nCantidad de Repeticiones\n\n");

	int cont=1;

	printf("\nSecuencia \t	Frecuencia.\n");
	printf("\nRepetida\n");

	temp=0;
	for (i = 0; i < largo-3; i++)
	{

		if(hexarray[i]!=temp && cont>1 )
		{
//			printf("n%04X-"/*"\n%04X \t %i"*/, hexarray[i-1]/*,cont */);	// Muestra lisatdo de frecuencias que se repiten (para informe)
			printf("\n%04X	\t	%i", hexarray[i-1],cont );
			cont=1;

		}

		if ( temp==hexarray[i] && i!=0 )
		{
			cont++;
		}
		else
		{
			cont=1;
		}

		temp=hexarray[i];

	}





    free(hexarray);
  return 0;
}
