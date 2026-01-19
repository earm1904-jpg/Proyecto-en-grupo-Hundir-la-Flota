#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "juego.h"
#include "turno.h"
#include "Validar_ubicacion_barco.h"


int ImpactoNav(Nave *Nav, tablero *tab, tablero *tabDisp){
    Nav->ImpacNav=Nav->tamNave; //falta determinar de qué forma inicialziar la variable

    printf("Digita las coordenas de disparo, recueda que son números enteros cero y once\n");
    printf("Digita la coordenada de las fila\n");
    scanf(" %d",CoorImpFilas);
    printf("Digita la coordenada de las columna\n");
    scanf(" %d", CoorImpColumn);

     if(CoorImpColumn>=0&&CoorImpColumn<TAM_TABLERO && CoorImpFilas>=0&&CoorImpFilas< TAM_TABLERO){

     for (int i = 0; i < TAM_TABLERO; i++)
        {

        for (int j = 0; j < TAM_TABLERO; j++)
            {
                if(tab->espacio[i][j]!=AGUA){
                    if(CoorImpFilas==i && CoorImpColumn==j){
                        Nav->ImpacNav=Nav->ImpacNav-1;
                        tab->espacio[CoorImpFilas][CoorImpColumn]='X';
                        tabDisp->espacio[CoorImpFilas][CoorImpColumn]='X';
                         printf("Has impactado una nave\n");
                         return 1;
                        if(Nav->ImpacNav==0){ //HUNDIDO
                            hundidos=hundidos+1;
                            printf("Has hundido una nave\n");
                            return 1;
                        }
                        

                    }
                    else{
                            tabDisp->espacio[CoorImpFilas][CoorImpColumn]='0';
                           printf("Ninguna nave inpactada\n");
                        }

                     
                }
            
            }
         }
        }
        else{
                 printf("Coordenadas no validas\n");
             }
    
        return 0;
}


void turnosPlayers(Nave *Nav, tablero *tabPlayer, tablero *tabPC){
 turno=ImpactoNav(&Nav,&tabPlayer,&tabPlayer);

    if(turno==1){
        
        disparos=disparos+1;
        ImpactoNav(&Nav,&tabPlayer,&tabPlayer);

        }
        else{
            turno++;
            disparos++;
        }


}
/*//Devuelve 1 si impactas en un barco y 0 si has fallado o ya habias dicho las coordenadas.

int ImpactoNav(Nave *Nav, tablero *tab, tablero *tabDisp){
    printf("Dime las coordenadas de disparo.\n", TAM_TABLERO -1);
    printf("Dime la coordenada de la fila: ");

//Los dos primeros if es para comprobar que lo que se introduce son números y no letras o símbolos
    if (scanf("%d", &CoorImpFilas)!= 1)
        return 0;
    
    printf("Dime la coordenada de la columna: ");
    if (scanf("%d", &CoorImpColumn)!= 1)
        return 0;
// Este if es para comprobar que las coordenadas están dentro del tablero.
    if (CoorImpFilas < 0 || CoorImpFilas >= TAM_TABLERO || CoorImpColumn < 0 || CoorImpColumn >= TAM_TABLERO){
        printf ("Coordenadas no válidas\n");
        return 0;
    }
//Este if es para ver si ya habías introducido estas coordenadas.
    if (tabDisp->espacio[CoorImpFilas][CoorImpColumn]== IMPACTO || tabDisp->espacio[CoorImpFilas][CoorImpColumn] == FALLA)
    {
        printf("Ya has disparado en esta posición. \n");
        return 0;
    }
//Como no hace falta recorrer todo el tablero, vamos a hacer una comprobación directa en la coordenada puesta
    if (tab->espacio[CoorImpFilas][CoorImpColumn]!= AGUA)
    {
        if (Nav != NULL && Nav->ImpacNav <= 0)
        {
            Nav->ImpacNav = Nav->tamNave;
        }
            
        if (Nav != NULL)
        {
            Nav->ImpacNav--;
        }

        tab->espacio[CoorImpFilas][CoorImpColumn] = IMPACTO;
        tabDisp->espacio[CoorImpFilas][CoorImpColumn] = IMPACTO;

        if (Nav != NULL && Nav->ImpacNav == 0)
        {
            hundidos++;
            printf("Has hundido un barco. \n");
        }
        else
        {
            printf("Has impoactado un barco. \n");
        }
        return 1; 
        //Devuelve uno porque ha sido un acierto
    }
    tabDisp->espacio[CoorImpFilas][CoorImpColumn] = FALLA;
    printf("No le has dado a ningún barco. \n");
    return 0;
}
//Funcion para contar los turnos.
void turnosPlayers(Nave *Nav, tablero *tabPlayer, tablero *tabPC){
    int acierto = ImpactoNav(Nav, tabPC, tabPlayer);
    disparos++;
    //Si aciertas repites
    if (acierto)
    {
        acierto = ImpactoNav(Nav, tabPC, tabPlayer);
        disparos++;
    }
    //si fallas cambias turno.
    else
    {
        turno++;
    }
    
}*/