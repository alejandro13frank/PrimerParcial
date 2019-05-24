#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>0)
    {
        for(i=0;i<size;size++)
        {
            array[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID, Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int retorno=-1;
    int posicion;
    int auxOrquesta;
    int auxPosIdOrquesta;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese edad: ","\nError",1,sizeof(int),1,200,5,&array[posicion].edad);
            orquesta_listar(arrayOrquesta,sizeOrquesta);
            utn_getUnsignedInt("\nIngrese ID de orquesta: ","\nError",1,sizeof(int),0,30000,1,&auxOrquesta);
            if (orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxOrquesta,&auxPosIdOrquesta)==-1)
            {
                printf("\nID incorrecto.");
            }
            else
            {
                array[posicion].IdOrquesta = auxOrquesta;

            utn_getUnsignedInt("\nIngrese tipo: \n1-Cuerdas\n2-viento-madera\n3-Viento-metal\n4-percusion\n ","\nError",1,sizeof(int),1,4,1,&array[posicion].IdInstrumento);
            utn_getName("Ingrese nombre\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getName("Ingrese apellido\n: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            printf("\n Posicion: %d\n ID: %d\n edad: %d\n IdOrquesta: %d\n IdInstrumento: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idUnico,
                   array[posicion].edad,
                   array[posicion].IdOrquesta,
                   array[posicion].IdInstrumento,
                   array[posicion].nombre,
                   array[posicion].apellido);
            retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),0,30000,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].IdOrquesta==valorBuscado)
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray,Orquesta arrayOrquesta[],int sizeOrquesta)
{
    int retorno=-1;
    int posicion;
    int auxIdOrquesta;
    int aux;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),0,30000,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n edad: %d\n IdOrquesta: %d\n IdInstrumento: %d\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idUnico,
                   array[posicion].edad,
                   array[posicion].IdOrquesta,
                   array[posicion].IdInstrumento,
                   array[posicion].nombre,
                   array[posicion].apellido);
                utn_getChar("\nModificar: \nA:Modificar edad \nB:Modificar id de orquesta\nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nIngrese Edad: ","\nError",1,sizeof(int),1,200,1,&array[posicion].edad);
                        break;
                    case 'B':
                        orquesta_listar(arrayOrquesta,sizeOrquesta);
                        utn_getUnsignedInt("\nIngrese ID de orquesta: ","\nError",1,sizeof(int),0,30000,1,&auxIdOrquesta);
                        if (orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxIdOrquesta,&aux)==-1)
                        {
                            printf("\nNo existe este ID de orquesta");
                        }
                        else
                        {
                            array[posicion].IdOrquesta = auxIdOrquesta;
                        }
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
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*//*
int musico_ordenarPorString(Musico array[],int size)
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

            bufferInt=array[i].edad;
            bufferFloat=array[i].varFloat1;
            strcpy(bufferString2,array[i].apellido);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString1,array[j].nombre)<0)
            {
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edad=array[j].edad;
                array[j + 1].varFloat1=array[j].varFloat1;
                strcpy(array[j + 1].apellido,array[j].apellido);

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString1);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edad=bufferInt;
            array[j + 1].varFloat1=bufferFloat;
            strcpy(array[j + 1].apellido,bufferString2);
        }
        retorno=0;
    }
    return retorno;
}
*/
//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\n edad: %d\n IdOrquesta: %d\n IdInstrumento: %d\n nombre: %s\n apellido: %s",
                       i, array[i].idUnico,
                       array[i].edad,
                       array[i].IdOrquesta,
                       array[i].IdInstrumento,
                       array[i].nombre,array[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}













