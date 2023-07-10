#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char delimitador[]={";"};
char caracter[6];
struct archivo{
int nombre[50];
float promedio;
};
FILE *archivo;
archivo=fopen("alumnos.txt", "r+");
while (!feof(archivo))
    {
        caracter[6] = fgetc(archivo);
        putchar(caracter);
        printf("%c", caracter);
    }

fclose(archivo);
return 0;
}

