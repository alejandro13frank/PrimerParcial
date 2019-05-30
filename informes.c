#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"
#include <stdio_ext.h>

int informe_mostrarOrquestaMasCincoMusicos(Orquesta *arrayOrquesta, int sizeOrquesta, Musico *arrayMusicos, int sizeMusico)
{
    int retorno =-1;
    int i;
    int j;
    int contador=0;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        printf("\n");
        for(i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                contador=0;
                for(j=0;j<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayOrquesta[i].idUnico==arrayMusicos[j].IdOrquesta)
                    {
                        contador++;
                    }
                }
                if (contador>=5)
                {
                    printf("\n");
                    printf("\n Id orquesta tiene mas de 5 music: %d",arrayOrquesta[i].idUnico);
                    printf("\n nombre orquesta: %s",arrayOrquesta[i].nombre);
                    printf("\n lugar orquesta: %s",arrayOrquesta[i].lugar);
                    orquesta_mostrarTipo(arrayOrquesta[i].tipo);

                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_mostrarMusicoMastreintaAno(Musico *arrayMusicos, int sizeMusico,
                                        Orquesta *arrayOrquesta, int sizeOrquesta,
                                        Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno =-1;
    int i;
    int j;
    int k;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        for(i=0;i<sizeMusico;i++)
        {
            if (!arrayMusicos[i].isEmpty && arrayMusicos[i].edad>30)
            {
                printf("\n");
                printf("\n id Musico mas de 30: %d",arrayMusicos[i].idUnico);
                printf("\n nombre Musico mas de 30: %s",arrayMusicos[i].nombre);
                printf("\n apelle Musico mas de 30: %s",arrayMusicos[i].apellido);
                printf("\n edad Musico mas de 30: %d",arrayMusicos[i].edad);
                orquesta_buscarID(arrayOrquesta,sizeOrquesta,arrayMusicos[i].IdOrquesta,&j);
                printf("\n orquesta Musico mas de 30: %s",arrayOrquesta[j].nombre);
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusicos[i].IdInstrumento,&k);
                printf("\n instrumento Musico mas de 30: %s",arrayInstrumento[k].nombre);
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_imprimirPorLugar(Orquesta *arrayOrquesta, int sizeOrquesta)
{
    int retorno =-1;
    int i;
    char auxLugar[20];
    if (arrayOrquesta!=NULL && sizeOrquesta>0)
    {
        printf("\n");
        utn_getTexto("\nIngrese el lugar de la orquesta a buscar: ","\nError",1,20,1,auxLugar);

        for(i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && strncmp(arrayOrquesta[i].lugar,auxLugar,sizeof(arrayOrquesta[i].lugar))==0)
            {
                printf("\n");
                printf("\n Id orquesta: %d",arrayOrquesta[i].idUnico);
                printf("\n nombre orquesta: %s",arrayOrquesta[i].nombre);
                printf("\n lugar orquesta: %s",arrayOrquesta[i].lugar);
                orquesta_mostrarTipo(arrayOrquesta[i].tipo);
            }
        }
        retorno =0;
    }
    return retorno;
}

int informe_mostrarOrquestaCompleta(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico,
                                    Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno =-1;
    int i;
    int j;
    int posicionInstrumento;
    int cantCuerdas;
    int cantViento;
    int cantPercusion;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        for (i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                cantCuerdas=0;
                cantViento=0;
                cantPercusion=0;
                for(j=0;j<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayOrquesta[i].idUnico==arrayMusicos[j].IdOrquesta)
                    {
                        instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusicos[j].IdInstrumento,&posicionInstrumento);
                        switch(arrayInstrumento[posicionInstrumento].tipo)
                        {
                            case CUERDAS:
                                cantCuerdas++;
                                break;
                            case VIENTO_MADERA:
                                cantViento++;
                                break;
                            case VIENTO_METAL:
                                cantViento++;
                                break;
                            case PERCUSION:
                                cantPercusion++;
                                break;
                        }
                    }
                }
                if (cantCuerdas>=5 && cantViento>=3 && cantPercusion>=2)
                {
                    printf("\n ID orquesta completa: %d",arrayOrquesta[i].idUnico);
                }
            }
        }
        retorno =0;
    }
    return retorno;
}

int informe_orquestaMasMusicos(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico)
{
    int retorno =-1;
    int i;
    int j;
    int cantMaxMusicos;
    int cantMusicos;
    int flag=0;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        for (i=0;i<sizeOrquesta;i++)
        {
            cantMusicos=0;
            if(!arrayOrquesta[i].isEmpty)
            {
                for (j=0;j<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayMusicos[j].IdOrquesta==arrayOrquesta[i].idUnico)
                    {
                        cantMusicos++;
                    }
                }
                arrayOrquesta[i].cantidadMusicos=cantMusicos;
                if (flag==0 || cantMaxMusicos<cantMusicos)
                {
                    cantMaxMusicos=cantMusicos;
                    flag=1;
                }
            }
        }
        for(i=0;i<sizeOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && arrayOrquesta[i].cantidadMusicos==cantMaxMusicos)
            {
                printf("\n");
                printf("\n Id orquesta mas Musicos: %d",arrayOrquesta[i].idUnico);
                printf("\n nombre orquesta: %s",arrayOrquesta[i].nombre);
                printf("\n lugar orquesta: %s",arrayOrquesta[i].lugar);
                printf("\n Cantidad de musicos: %d",arrayOrquesta[i].cantidadMusicos);
                orquesta_mostrarTipo(arrayOrquesta[i].tipo);
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_musicosDeCuerdas(Musico *arrayMusico, int sizeMusico,
                             Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int auxIdInstrumento;
    if (arrayMusico!=NULL && sizeMusico>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        printf("\n");
        musico_ordenarPorApellido(arrayMusico,sizeMusico);
        for (i=0;i<sizeMusico;i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].IdInstrumento,&auxIdInstrumento);
                if (arrayInstrumento[auxIdInstrumento].tipo==CUERDAS)
                {
                    printf("\n");
                    printf("\nToca cuerdas :");
                    printf("\n Nombre: %s",arrayMusico[i].nombre);
                    printf("\n Apellido: %s",arrayMusico[i].apellido);
                    printf("\n Edad: %d",arrayMusico[i].edad);
                    printf("\n Nombre instrumento: %s",arrayInstrumento[auxIdInstrumento].nombre);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int informe_promedioMusicosPorOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico)
{
    int retorno=-1;
    int cantidadDeMusicos;
    int cantidadDeOrquestas;
    if (arrayOrquesta!=NULL && arrayMusico!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        printf("\n");
        cantidadDeMusicos=musico_cantidadDeMusicos(arrayMusico,sizeMusico);
        cantidadDeOrquestas=orquesta_cantidadDeOrquestas(arrayOrquesta,sizeOrquesta);
        if (cantidadDeOrquestas==0)
        {
            printf("\nNo hay orquestas.");
            retorno=-1;
        }
        else
        {
           printf("\n El promedio de musicos por orquesta es %.2f", (float)cantidadDeMusicos/cantidadDeOrquestas);
           retorno=0;
        }

    }
    return retorno;
}

int informe_mostarMusicoPorUnaOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico,
                                       Instrumento *arrayInstrumento, int sizeInstrumento)
{
    int retorno=-1;
    int i;
    int auxIdOrquesta;
    int posicionOrquesta;
    int auxIdInstrumento;
    if (arrayOrquesta!=NULL && arrayMusico!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        orquesta_listar(arrayOrquesta,sizeOrquesta);
        utn_getUnsignedInt("\nIngrese el ID de la orquesta: ","idIncorrecto",1,sizeof(int),0,30000,1,&auxIdOrquesta);
        if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxIdOrquesta,&posicionOrquesta)==0)
        {
            for (i=0;i<sizeMusico;i++)
            {
                if (!arrayMusico[i].isEmpty && arrayMusico[i].IdOrquesta==auxIdOrquesta)
                {
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].IdInstrumento,&auxIdInstrumento);
                printf("\n");
                printf("\n Nombre : %s",arrayMusico[i].nombre);
                printf("\n Apellido: %s",arrayMusico[i].apellido);
                printf("\n Edad: %d",arrayMusico[i].edad);
                printf("\n Nombre instrumento: %s",arrayInstrumento[auxIdInstrumento].nombre);
                instrumento_mostrarTipo(arrayInstrumento[auxIdInstrumento].tipo);
                }
            }
        }
        else
        {
            printf("\n Orquesta no encontrada.");
        }
    }
    return retorno;
}













