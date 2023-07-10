#include <stdio.h>
#include <stdlib.h>

// Definición de estructura para representar a cada estudiante
typedef struct {
    int codigo;
    char nombre[50];
    float promedio;
} Estudiante;

// Función para comparar dos estudiantes por su código
int compararEstudiantes(const void *est1, const void *est2) {
    Estudiante *e1 = (Estudiante *)est1;
    Estudiante *e2 = (Estudiante *)est2;

    if (e1->codigo > e2->codigo) {
        return -1;
    } else if (e1->codigo < e2->codigo) {
        return 1; // Indica que el primer estudiante es mayor al segundo
    } else {
        return 0; // Indica que los estudiantes son iguales
    }
}

// Función para leer los datos de los estudiantes desde un archivo
Estudiante *leerEstudiantesDesdeArchivo(const char *alumnos, int *numEstudiantes) {
    FILE *archivo = fopen("alumnos.txt", "r+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    fscanf(archivo, "%d", numEstudiantes);

    Estudiante *estudiantes = (Estudiante *)malloc(*numEstudiantes * sizeof(Estudiante));
    if (estudiantes == NULL) {
        printf("No se pudo asignar memoria para los estudiantes.\n");
        fclose(archivo);
        return NULL;
    }

    for (int i = 0; i < *numEstudiantes; i++) {
        fscanf(archivo, "%d %s %f", &estudiantes[i].codigo, estudiantes[i].nombre, &estudiantes[i].promedio);
    }

    fclose(archivo);
    return estudiantes;
}

// Función para escribir los datos de los estudiantes en un archivo
void escribirEstudiantesEnArchivo(const char *alumnos, Estudiante *estudiantes, int numEstudiantes) {
    FILE *archivo = fopen("alumnos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%d\n", numEstudiantes);

    for (int i = 0; i < numEstudiantes; i++) {
        fprintf(archivo, "%d %s %.2f\n", estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].promedio);
    }

    fclose(archivo);
}

int main() {
    int numEstudiantes=5;
    Estudiante *estudiantes = leerEstudiantesDesdeArchivo("alumnos.txt", &numEstudiantes);
    if (estudiantes == NULL) {
        return 1;
    }

    // Ordenar los estudiantes por código
    qsort(estudiantes, numEstudiantes, sizeof(Estudiante), compararEstudiantes);

    // Calcular la nota promedio
    float sumaPromedios = 0.0;
    for (int i = 0; i < numEstudiantes; i++) {
        sumaPromedios += estudiantes[i].promedio;
    }
    float promedio = sumaPromedios / numEstudiantes;

    // Actualizar el promedio en cada estudiante
    for (int i = 0; i < numEstudiantes; i++) {
        estudiantes[i].promedio = promedio;
    }

    escribirEstudiantesEnArchivo("estudiantes_ordenados.txt", estudiantes, numEstudiantes);

    free(estudiantes);

    return 0;
}
