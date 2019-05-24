#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "orquesta.h"
#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int IdOrquesta;
    int IdInstrumento;
}Musico;

int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);
int musico_alta(Musico array[], int size, int* contadorID,Orquesta arrayOrquesta[], int sizeOrquesta);
int musico_baja(Musico array[], int sizeArray);
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray,Orquesta arrayOrquesta[],int sizeOrquesta);
int musico_ordenarPorApellido(Musico array[],int size);
int musico_listar(Musico array[], int size);
#endif // MUSICO_H_INCLUDED
