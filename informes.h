#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"

/** \brief  Muestra la orquesta con mas de 5 musicos.indicando ID de orquesta,  nombre
*           tipo y lugar
* \param  arrayOrquesta Orquesta Array de orquesta
* \param  arrayMusicos Musico Array de musico
* \param sizeOrquesta int tamano del array
* \param sizeMusico int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_mostrarOrquestaMasCincoMusicos(Orquesta *arrayOrquesta, int sizeOrquesta,
                                           Musico *arrayMusicos, int sizeMusico);

/** \brief  Muestra los musicos con mas de 30 años.indicando ID de musico, nombre
*           apellido, edad, nombre del instrumento y tipo
* \param  arrayOrquesta Orquesta Array de orquesta
* \param  arrayMusicos Musico Array de musico
* \param  arrayInstrumento Musico Array de instrumento
* \param sizeOrquesta int tamano del array
* \param sizeMusico int tamano del array
* \param sizeInstrumento int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_mostrarMusicoMastreintaAno(Musico *arrayMusicos, int sizeMusico,
                                        Orquesta *arrayOrquesta, int sizeOrquesta,
                                        Instrumento *arrayInstrumento, int sizeInstrumento);

/** \brief  Al ingresar un lugar muetra todas las orquestas que estan en ese lugar.
*           indicando ID de orquesta,nombre, tipo y lugar
* \param  arrayOrquesta Orquesta Array de orquesta
* \param sizeOrquesta int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_imprimirPorLugar(Orquesta *arrayOrquesta, int sizeOrquesta);

/** \brief  Muestra las orquestas calificadas como "Completas". Indicando
            ID de orquesta.
* \param  arrayOrquesta Orquesta Array de orquesta
* \param  arrayMusicos Musico Array de musico
* \param  arrayInstrumento Musico Array de instrumento
* \param sizeOrquesta int tamano del array
* \param sizeMusico int tamano del array
* \param sizeInstrumento int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_mostrarOrquestaCompleta(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico,
                                    Instrumento *arrayInstrumento, int sizeInstrumento);

/** \brief  Muestra todos los musicos de una orquesta ingresada por ID. indicando
*           nombre y apellido, edad, nombre y tipo de instrumento.
* \param  arrayOrquesta Orquesta Array de orquesta
* \param  arrayMusicos Musico Array de musico
* \param  arrayInstrumento Musico Array de instrumento
* \param sizeOrquesta int tamano del array
* \param sizeMusico int tamano del array
* \param sizeInstrumento int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_mostarMusicoPorUnaOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico,
                                       Instrumento *arrayInstrumento, int sizeInstrumento);

/** \brief  Muestra la/las orquesta con mas musicos. Indicando todos los datos de la orquesta y
            la cantidad de musicos que tiene.
* \param  arrayOrquesta Orquesta Array de orquesta
* \param  arrayMusicos Musico Array de musico
* \param sizeOrquesta int tamano del array
* \param sizeMusico int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_orquestaMasMusicos(Orquesta *arrayOrquesta, int sizeOrquesta,
                                    Musico *arrayMusicos, int sizeMusico);

/** \brief  Muestra todos los musicos de cuerdas ordenados por apellido. Indicando
            nombre y apellido, edad, nombre y tipo de instrumento que toca.
* \param  arrayMusicos Musico Array de musico
* \param  arrayInstrumento Musico Array de instrumento
* \param sizeMusico int tamano del array
* \param sizeInstrumento int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_musicosDeCuerdas(Musico *arrayMusico, int sizeMusico,
                             Instrumento *arrayInstrumento, int sizeInstrumento);

/** \brief  informa la cantidad de musicos por orquesta.
* \param  arrayOrquesta Orquesta Array de orquesta
* \param  arrayMusicos Musico Array de musico
* \param sizeOrquesta int tamano del array
* \param sizeMusico int tamano del array
* \return int Return (-1) Si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int informe_promedioMusicosPorOrquesta(Orquesta *arrayOrquesta,int sizeOrquesta,
                                       Musico *arrayMusico,int sizeMusico);

#endif // INFORMES_H_INCLUDED
