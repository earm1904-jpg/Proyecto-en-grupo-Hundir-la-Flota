#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "juego.h"
#include "turno.h"
#include "Validar_ubicacion_barco.h"


int ImpactoNav(Nave *Nav, tablero *tab, tablero *tabDisp){
    // NO se reinicia Nav->ImpacNav aquí, se mantiene su valor anterior
    
    printf("Digita las coordenas de disparo, recueda que son números enteros cero y once\n");
    printf("Digita la coordenada de las fila\n");
    scanf(" %d",&CoorImpFilas);
    printf("Digita la coordenada de las columna\n");
    scanf(" %d", &CoorImpColumn);

     if(CoorImpColumn>=0&&CoorImpColumn<TAM_TABLERO && CoorImpFilas>=0&&CoorImpFilas< TAM_TABLERO){

        // Verificar si ya se disparó en esta posición
        if(tabDisp->espacio[CoorImpFilas][CoorImpColumn]=='X' || tabDisp->espacio[CoorImpFilas][CoorImpColumn]=='0'){
            printf("Ya disparaste en esta posición\n");
            return 0;
        }

        // Verificar directamente si hay barco en la coordenada ingresada
        if(tab->espacio[CoorImpFilas][CoorImpColumn]!=AGUA){
            // Hay un barco
            Nav->ImpacNav=Nav->ImpacNav-1;
            tab->espacio[CoorImpFilas][CoorImpColumn]='X';
            tabDisp->espacio[CoorImpFilas][CoorImpColumn]='X';
            
            if(Nav->ImpacNav==0){ //HUNDIDO
                hundidos=hundidos+1;
                printf("Has hundido una nave\n");
            }
            else{
                printf("Has impactado una nave\n");
            }
            return 1;
        }
        else{
            // Es agua - no hay barco
            tabDisp->espacio[CoorImpFilas][CoorImpColumn]='0';
            printf("Ninguna nave impactada\n");
            return 0;
        }
        }
        else{
                 printf("Coordenadas no validas\n");
             }
    
        return 0;
}


void turnosPlayers(Nave *Nav, tablero *tabPlayer, tablero *tabPC){
 turno=ImpactoNav(Nav,tabPlayer,tabPlayer);

    if(turno==1){
        
        disparos=disparos+1;
        ImpactoNav(Nav,tabPlayer,tabPlayer);

        }
        else{
            turno++;
            disparos++;
        }


}

// FUNCIÓN PARA QUE LA PC ATAQUE
int AtaquePC(tablero *tabPlayer, tablero *tabDisparosPC){
    int fila, columna;
    
    do {
        fila = rand() % TAM_TABLERO;
        columna = rand() % TAM_TABLERO;
    } while(tabDisparosPC->espacio[fila][columna] != AGUA);
    
    printf("\nLa PC dispara a: Fila %d, Columna %d\n", fila, columna);
    
    if(tabPlayer->espacio[fila][columna] != AGUA){
        tabPlayer->espacio[fila][columna] = 'X';
        tabDisparosPC->espacio[fila][columna] = 'X';
        printf("¡La PC ha impactado uno de tus barcos!\n");
        return 1;
    }
    else{
        tabDisparosPC->espacio[fila][columna] = '0';
        printf("La PC ha disparado a agua.\n");
        return 0;
    }
}

// FUNCIÓN PARA CONTAR BARCOS RESTANTES
int ContarBarcosRestantes(tablero *tab){
    int impactos = 0;
    for(int i = 0; i < TAM_TABLERO; i++){
        for(int j = 0; j < TAM_TABLERO; j++){
            // Contar los impactos (X) - cuando un barco es impactado
            if(tab->espacio[i][j] == 'X'){
                impactos++;
            }
        }
    }
    // Total de casillas de barcos: 1 Portaviones (4) + 2 Cruceros (3+3) + 3 Patrulleros (2+2+2) = 16
    // Si hay 16 impactos, todos los barcos están hundidos
    int totalBarcosHundidos = 16;
    
    if(impactos >= totalBarcosHundidos){
        return 0; // No hay barcos restantes
    }
    return 1; // Hay barcos restantes
}
