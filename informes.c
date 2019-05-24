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
        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty)
            {
                continue;
            }else
            {
                contador=0;
                for(j=0;j<sizeMusico;j++)
                {
                    if (arrayMusicos[j].isEmpty)
                    {
                        continue;
                    }else if (arrayOrquesta[i].idUnico==arrayMusicos[j].IdOrquesta)
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
        for(i=0;i<sizeMusico;i++)
        {
            if (arrayMusicos[i].isEmpty)
            {
                continue;
            }else if (arrayMusicos[i].edad>=30)
            {
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
        utn_getTexto("\nIngrese lugar a buscar: ","\nError",1,20,1,auxLugar);

        for(i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty)
            {
                continue;
            }
            else if (strncmp(arrayOrquesta[i].lugar,auxLugar,sizeof(arrayOrquesta[i].lugar))==0)
            {
                    //printf("\n");
                    //printf("\n Id orquesta: %d",arrayOrquesta[i].idUnico);
                    //printf("\n nombre orquesta: %s",arrayOrquesta[i].nombre);
                    //printf("\n lugar orquesta: %s",arrayOrquesta[i].lugar);
                    //printf("\n Llegue hasta aca1");
                    orquesta_mostrarTipo(arrayOrquesta[i].tipo);
                    printf("\n Llegue hasta aca2");
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
    int cantCuerdas=0;
    int cantViento=0;
    int cantPercusion=0;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0 && sizeInstrumento>0 && arrayInstrumento!=NULL)
    {
        for (i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty)
            {
                continue;
            }
            else
            {
                for(j=0;j<sizeMusico;j++)
                {
                    if (arrayMusicos[j].isEmpty && arrayOrquesta[i].idUnico==arrayMusicos[j].IdOrquesta)
                    {
                        switch(arrayInstrumento[arrayMusicos[j].IdInstrumento].tipo)
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
    int retorno =-1;/*
    int i;
    int j;
    int cantMaxMusicos=0;
    int cantMusicos=0;
    int orquestaMax;
    int flag=0;
    if (arrayOrquesta!=NULL && arrayMusicos!=NULL && sizeMusico>0 && sizeOrquesta>0)
    {
        for (i=0;i<sizeOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty)
            {
                continue;
            }else
            {
                for (j=0;i<sizeMusico;j++)
                {
                    if (!arrayMusicos[j].isEmpty && arrayMusicos[j].IdOrquesta==arrayOrquesta[i].idUnico)
                    {
                        cantMusicos++;
                    }
                }
                if (flag==0 || cantMaxMusicos<cantMusicos)
                {
                    cantMaxMusicos=cantMusicos;
                    orquestaMax=arrayOrquesta[i].idUnico;
                    flag=1;
                }
            }
        }
        printf("\n");
        printf("\n Id orquesta mas Musicos: %d",arrayOrquesta[orquestaMax].idUnico);
        printf("\n nombre orquesta: %s",arrayOrquesta[orquestaMax].nombre);
        printf("\n lugar orquesta: %s",arrayOrquesta[orquestaMax].lugar);
        orquesta_mostrarTipo(arrayOrquesta[orquestaMax].tipo);
        retorno=0;
    }*/
    return retorno;
}

