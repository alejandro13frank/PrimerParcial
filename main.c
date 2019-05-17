#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"
#include <stdio_ext.h>


#define QTY_INSTRUMENTO 20
#define QTY_MUSICO 1000
#define QTY_ORQUESTA 50


int main()
{
    int auxIdBorrado;
    int opcion;
    int contadorIdOrquesta=0;
    int contadorIdMusico=0;
    int contadorIdInstrumento=0;

    Orquesta arrayOrquesta[QTY_ORQUESTA];
    Musico arrayMusico[QTY_MUSICO];
    Instrumento arrayInstrumento[QTY_INSTRUMENTO];
    orquesta_Inicializar(arrayOrquesta,QTY_ORQUESTA);
    musico_Inicializar(arrayMusico,QTY_MUSICO);
    instrumento_Inicializar(arrayInstrumento,QTY_INSTRUMENTO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta orquesta\n2) Eliminar Orquesta \n3)Listar Orquesta \n4) Musico Alta \n5) Musico modificar\n6) Musico baja\n7) Imprimir musicos\n8) ALta instrumento\n9) Listar instrumentos \n10) Salir\n",
                      "\nError",1,sizeof(int),1,60,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta Orquesta
                orquesta_alta(arrayOrquesta,QTY_ORQUESTA,&contadorIdOrquesta);
                break;

            case 2: //baja orquesta
                orquesta_baja(arrayOrquesta,QTY_ORQUESTA,&auxIdBorrado);
                musico_bajaValorRepetidoInt(arrayMusico,QTY_MUSICO,auxIdBorrado);
                break;

            case 3: //imprimir orquesta
                orquesta_listar(arrayOrquesta,QTY_ORQUESTA);
                break;

            case 4://agregar musico
                musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico,arrayOrquesta,QTY_ORQUESTA);
                break;

            case 5://modificar musico
                musico_modificar(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA);
                break;
            case 6://eliminar musico
                musico_baja(arrayMusico,QTY_MUSICO);
                break;
            case 7://imprimir musicos
                musico_listar(arrayMusico,QTY_MUSICO);
                break;
            case 8://alta instrumento
                instrumento_alta(arrayInstrumento,QTY_INSTRUMENTO,&contadorIdInstrumento);
                break;
            case 9://imprimir musicos
                instrumento_listar(arrayInstrumento,QTY_INSTRUMENTO);
                break;
            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
        fflush(stdin);
    }
    while(opcion!=10); //
    return 0;
}
