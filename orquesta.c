#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese tipo de instrumento \n1-sinfonica\n2-filarmonica\n3-camara \n","\nError",1,sizeof(int),1,3,1,&array[posicion].tipo);
            utn_getTexto("\nIngrese nombre de orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese lugar de orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
            printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n lugar: %s",
                   posicion, array[posicion].idUnico,
                   array[posicion].tipo,
                   array[posicion].nombre,array[posicion].lugar);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray,int *idBorrado)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        orquesta_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),0,30000,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            *idBorrado = posicion;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*//*
int orquesta_modificar(Orquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        orquesta_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n lugar: %s",
                   posicion, array[posicion].idUnico,
                   array[posicion].tipo,
                   array[posicion].nombre,array[posicion].lugar);
                utn_getChar("\nModificar: \nA \nB \nC \nD \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&array[posicion].tipo);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&array[posicion].varInt2);
                        break;
                    case 'C':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&array[posicion].varInt3);
                        break;
                    case 'D':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat1);
                        break;
                    case 'E':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat2);
                        break;
                    case 'F':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat3);
                        break;
                    case 'G':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'H':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
                        break;
                    case 'I':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString3);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}*/

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*//*
int orquesta_ordenarPorString(Orquesta array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString1[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
    float bufferFloat;
    char bufferString2[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString1,array[i].nombre);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].tipo;
            bufferFloat=array[i].varFloat1;
            strcpy(bufferString2,array[i].lugar);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString1,array[j].nombre)<0)
            {
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].tipo=array[j].tipo;
                array[j + 1].varFloat1=array[j].varFloat1;
                strcpy(array[j + 1].lugar,array[j].lugar);

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString1);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].tipo=bufferInt;
            array[j + 1].varFloat1=bufferFloat;
            strcpy(array[j + 1].lugar,bufferString2);
        }
        retorno=0;
    }
    return retorno;
}*/

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                printf("\n Posicion: %d\n ID: %d\n nombre: %s\n lugar: %s",
                       i, array[i].idUnico,
                       array[i].nombre,
                       array[i].lugar);
                orquesta_mostrarTipo(array[i].tipo);
            }
        }
        retorno=0;
    }
    return retorno;
}
int orquesta_mostrarTipo(int tipoOrquesta)
{
    printf("\n");
    switch (tipoOrquesta)
    {
        case SINFONICA:
            printf("Tipo :Sinfonica");
            break;
        case FILARMONICA:
            printf("Tipo :Filarmonica");
            break;
        case CAMARA:
            printf("Tipo :Camara");
            break;
    }
    return 0;
}
