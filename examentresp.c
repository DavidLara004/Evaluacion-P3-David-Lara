#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char delimitador[]={";"};
char caracter[6];
struct archivo{
int nombre[50];
float promedio;
}est;
FILE *archivo;
archivo=fopen("alumnos.txt", "r+");
while (!feof(archivo))
    {
        fread(&est, sizeof(est), 2, archivo);

        printf("%c", caracter);
    }

fclose(archivo);
return 0;
}

