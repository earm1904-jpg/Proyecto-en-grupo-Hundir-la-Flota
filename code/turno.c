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
                            hundido=hundido+1;
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