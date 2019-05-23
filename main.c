#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
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

    arrayInstrumento[1].idUnico=1;
    arrayInstrumento[1].isEmpty=0;
    strncmp(arrayInstrumento[1].nombre,"inst1",sizeof(arrayInstrumento[1].nombre));
    arrayInstrumento[1].tipo=1;

    arrayInstrumento[2].idUnico=2;
    arrayInstrumento[2].isEmpty=0;
    strncmp(arrayInstrumento[2].nombre,"inst2",sizeof(arrayInstrumento[2].nombre));
    arrayInstrumento[2].tipo=2;

    arrayInstrumento[3].idUnico=3;
    arrayInstrumento[3].isEmpty=0;
    strncmp(arrayInstrumento[3].nombre,"inst3",sizeof(arrayInstrumento[3].nombre));
    arrayInstrumento[3].tipo=2;

    arrayInstrumento[4].idUnico=4;
    arrayInstrumento[4].isEmpty=0;
    strncmp(arrayInstrumento[4].nombre,"inst4",sizeof(arrayInstrumento[4].nombre));
    arrayInstrumento[4].tipo=3;

    arrayInstrumento[5].idUnico=5;
    arrayInstrumento[5].isEmpty=0;
    strncmp(arrayInstrumento[5].nombre,"inst5",sizeof(arrayInstrumento[5].nombre));
    arrayInstrumento[5].tipo=3;

    arrayOrquesta[1].idUnico=1;
    arrayOrquesta[1].isEmpty=0;
    strncpy(arrayOrquesta[1].nombre,"Orquesta1",sizeof(arrayOrquesta[1].nombre));
    strncpy(arrayOrquesta[1].lugar,"Lugar1",sizeof(arrayOrquesta[4].lugar));
    arrayOrquesta[1].tipo=1;

    arrayOrquesta[2].idUnico=2;
    arrayOrquesta[2].isEmpty=0;
    strncpy(arrayOrquesta[2].nombre,"Orquesta2",sizeof(arrayOrquesta[1].nombre));
    strncpy(arrayOrquesta[2].lugar,"Lugar1",sizeof(arrayOrquesta[4].lugar));
    arrayOrquesta[2].tipo=2;

    arrayOrquesta[3].idUnico=3;
    arrayOrquesta[3].isEmpty=0;
    strncpy(arrayOrquesta[3].nombre,"Orquesta3",sizeof(arrayOrquesta[1].nombre));
    strncpy(arrayOrquesta[3].lugar,"Lugar2",sizeof(arrayOrquesta[4].lugar));
    arrayOrquesta[3].tipo=3;

    arrayOrquesta[4].idUnico=4;
    arrayOrquesta[4].isEmpty=0;
    strncpy(arrayOrquesta[4].nombre,"Orquesta4",sizeof(arrayOrquesta[1].nombre));
    strncpy(arrayOrquesta[4].lugar,"Lugar2",sizeof(arrayOrquesta[4].lugar));
    arrayOrquesta[4].tipo=3;

    strncpy(arrayMusico[1].apellido,"Amus1",sizeof(arrayMusico[1].apellido));
    strncpy(arrayMusico[1].nombre,"Mus1",sizeof(arrayMusico[6].nombre));
    arrayMusico[1].edad=30;
    arrayMusico[1].IdInstrumento=2;
    arrayMusico[1].IdOrquesta=1;
    arrayMusico[1].idUnico=1;

   strncpy(arrayMusico[2].apellido,"Amus2",sizeof(arrayMusico[1].apellido));
    strncpy(arrayMusico[2].nombre,"Mus2",sizeof(arrayMusico[6].nombre));
    arrayMusico[2].edad=20;
    arrayMusico[2].IdInstrumento=5;
    arrayMusico[2].IdOrquesta=2;
    arrayMusico[2].idUnico=2;

    strncpy(arrayMusico[3].apellido,"Amus3",sizeof(arrayMusico[1].apellido));
    strncpy(arrayMusico[3].nombre,"Mus3",sizeof(arrayMusico[6].nombre));
    arrayMusico[3].edad=25;
    arrayMusico[3].IdInstrumento=2;
    arrayMusico[3].IdOrquesta=4;
    arrayMusico[3].idUnico=3;

    strncpy(arrayMusico[4].apellido,"Amus4",sizeof(arrayMusico[1].apellido));
    strncpy(arrayMusico[4].nombre,"Mus4",sizeof(arrayMusico[6].nombre));
    arrayMusico[4].edad=27;
    arrayMusico[4].IdInstrumento=1;
    arrayMusico[4].IdOrquesta=4;
    arrayMusico[4].idUnico=4;

    strncpy(arrayMusico[5].apellido,"Amus5",sizeof(arrayMusico[1].apellido));
    strncpy(arrayMusico[5].nombre,"Mus5",sizeof(arrayMusico[6].nombre));
    arrayMusico[5].edad=22;
    arrayMusico[5].IdInstrumento=3;
    arrayMusico[5].IdOrquesta=1;
    arrayMusico[5].idUnico=5;

    strncpy(arrayMusico[6].apellido,"Amus6",sizeof(arrayMusico[1].apellido));
    strncpy(arrayMusico[6].nombre,"Mus6",sizeof(arrayMusico[6].nombre));
    arrayMusico[6].edad=35;
    arrayMusico[6].IdInstrumento=4;
    arrayMusico[6].IdOrquesta=3;
    arrayMusico[6].idUnico=6;


    do
    {
        utn_getUnsignedInt("\n\n1) Alta orquesta\n2) Eliminar Orquesta \n3)Listar Orquesta \n4) Musico Alta \n5) Musico modificar\n6) Musico baja\n7) Imprimir musicos\n8) ALta instrumento\n9) Listar instrumentos\n11) Informes\n \n10) Salir\n",
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
            case 11://INFORMES
                    informe_mostrarOrquestaMasCincoMusicos(arrayOrquesta,QTY_ORQUESTA,arrayMusico,QTY_MUSICO);
                    informe_mostrarMusicoMastreintaAno(arrayMusico,QTY_MUSICO,
                                        arrayOrquesta,QTY_ORQUESTA,
                                        arrayInstrumento,QTY_INSTRUMENTO);
                    informe_imprimirPorLugar(arrayOrquesta, QTY_ORQUESTA);
                    informe_mostrarOrquestaCompleta(arrayOrquesta,QTY_ORQUESTA,
                                    arrayMusico,QTY_MUSICO,
                                    arrayInstrumento,QTY_INSTRUMENTO);
                    informe_orquestaMasMusicos(arrayOrquesta,QTY_ORQUESTA,
                                    arrayMusico,QTY_MUSICO);
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
