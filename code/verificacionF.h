#ifndef VERIFICACIONF_H
#define VERIFICACIONF_H
#include "juego.h"

// Función para contar cuántos impactos (X) hay en el tablero enemigo
// Retorna: cantidad total de 'X' (impactos)
int ContarImpactos(tablero *tab);

// Función para verificar si el juego ha terminado
// Retorna 1 si todas las naves fueron hundidas, 0 en caso contrario
int JuegoTerminado(tablero *tabEnemigas, tablero *tabDisparos);

// Función para determinar el ganador
// Retorna: 1 si el jugador ganó, 0 si la máquina ganó, -1 si aún hay juego
int DeterminarGanador(tablero *TabPlayer, tablero *TabContr, tablero *TabDisparosPlayer, tablero *TabDisparosPC);

#endif