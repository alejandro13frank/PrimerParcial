#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"

int informe_mostrarOrquestaMasCincoMusicos(Orquesta *arrayOrquesta, int sizeOrquesta,
                                           Musico *arrayMusicos, int sizeMusico);

int informe_mostrarMusicoMastreintaAno(Musico *arrayMusicos, int sizeMusico,
                                        Orquesta *arrayOrquesta, int sizeOrquesta,
                                        Instrumento *arrayInstrumento, int sizeInstrumento);

int informe_imprimirPorLugar(Orquesta *arrayOrquesta, int sizeOrquesta);

int informe_mostrarOrquestaCompleta(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico,
                                    Instrumento *arrayInstrumento, int sizeInstrumento);

int informe_mostarMusicoPorUnaOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico,
                                       Instrumento *arrayInstrumento, int sizeInstrumento);

int informe_orquestaMasMusicos(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico);

int informe_musicosDeCuerdas(Musico *arrayMusico, int sizeMusico,
                             Instrumento *arrayInstrumento, int sizeInstrumento);

int informe_promedioMusicosPorOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico);

#endif // INFORMES_H_INCLUDED
