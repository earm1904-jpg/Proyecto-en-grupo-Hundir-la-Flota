#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "juego.h"
#include "turno.h"
#include "Validar_ubicacion_barco.h"
#include "verificacionF.h"

// Función para contar cuántos impactos (X) hay en el tablero enemigo
// Retorna: cantidad total de 'X' (impactos)
int ContarImpactos(tablero *tab)
{
    int impactos = 0;
    
    for (int i = 0; i < TAM_TABLERO; i++)
    {
        for (int j = 0; j < TAM_TABLERO; j++)
        {
            if (tab->espacio[i][j] == IMPACTO)  // IMPACTO = 'X'
            {
                impactos++;
            }
        }
    }
    
    return impactos;
}

// Retorna: 1 si todas las 16 partes de barcos fueron impactadas, 0 en caso contrario
int JuegoTerminado(tablero *tabEnemigas, tablero *tabDisparos)
{
    // El juego termina cuando se han hecho 16 impactos 
    int TOTAL_PARTES_BARCOS = 16;
    
    int impactos = ContarImpactos(tabDisparos);
    
    if (impactos >= TOTAL_PARTES_BARCOS)
    {
        return 1;  // Juego terminado - todos los barcos hundidos
    }
    
    return 0;  // Juego aún en curso
}

/* Función: DeterminarGanador
// Propósito: Determinar quién ganó basándose en los tableros de disparos
// Retorna:
//   1 = El jugador ganó (hundió todos los barcos del PC)
//   -1 = La máquina ganó (hundió todos los barcos del jugador)
//   0 = El juego aún no ha terminado
int DeterminarGanador(tablero *TabPlayer, tablero *TabContr, tablero *TabDisparosPlayer, tablero *TabDisparosPC)
{
    // Verificar si el jugador ganó (hundió todos los barcos del PC)
    if (JuegoTerminado(TabContr, TabDisparosPlayer))
    {
        printf("╔════════════════════════════════════════╗\n");
        printf("║  ¡¡¡ FELICIDADES! ¡¡¡                  ║\n");
        printf("║  ¡¡¡ ¡GANASTE! ¡¡¡                     ║\n");
        printf("║  Hundiste todos los barcos del PC      ║\n");
        printf("╚════════════════════════════════════════╝\n");
        return 1;
    }
    
    // Verificar si la máquina ganó (hundió todos los barcos del jugador)
    if (JuegoTerminado(TabPlayer, TabDisparosPC))
    {
        printf("╔════════════════════════════════════════╗\n");
        printf("║  ¡La máquina ganó!                     ║\n");
        printf("║  Todos tus barcos fueron hundidos      ║\n");
        printf("╚════════════════════════════════════════╝\n");
        return -1;
    }
    
    // El juego aún no ha terminado
    return 0;
}
*/
