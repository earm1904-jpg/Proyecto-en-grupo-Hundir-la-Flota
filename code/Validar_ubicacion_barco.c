#include <stdio.h>
#include "juego.h"
#include "Validar_ubicacion_barco.h"

int FueradelMapa(Naves *Nav)
{
    int k=0; //variable encargada guardar el número de casillas a las que está el punto de inicio con respecto a los puntos de inicio del tablero para colocar el barco

    
    if(Nav->InicialColum <0 || Nav->InicialColum> TAM_TABLERO-1 ||Nav->InicialFilas <0||Nav->InicialFilas >TAM_TABLERO-1){ //Comprobar si la nave cabe dentro del tablero
        printf("El barco no puede ubicarse porque queda fuera del tablero");
        return 1;
    }

    //------------------------------------------------------------------------------//
    //Condicional que determina si un barco puede ubicarse en Orientación Vertical //
    //-----------------------------------------------------------------------------//                   

if (Nav->orientacion=='V'){
    for(int i=0;i<TAM_TABLERO; i++){

        for(int j=0;j<TAM_TABLERO; j++){

         if(Nav->InicialFilas==i&&Nav->InicialColum==j){//Comprobar si el barco cabe de forma horizontal o vertical
            k=i+1;
                if(Nav->tamNave>k){
                    printf("Escoge la ubicacion de Proa\n");
                     return 1;
                }
            }   
    } 
    }
    }

    //------------------------------------------------------------------------------//
    //Condicional que determina si un barco puede ubicarse en Orientación Horizontal//
    //------------------------------------------------------------------------------// 

if (Nav->orientacion=='H'){
    for(int i=0;i<TAM_TABLERO; i++){

        for(int j=0;j<TAM_TABLERO; j++){

         if(Nav->InicialFilas==i&&Nav->InicialColum==j){//Comprobar si el barco cabe de forma horizontal o vertical
            k=j+1; //variable encargada guardar el número de casillas a las que está el punto de inicio con respecto a los puntos de inicio del tablero para colocar el barco
                if(Nav->tamNave>k){
                    printf("Escoge la ubicacion de Proa\n");
                     return 1;
                }
            }   
    }
    
    }
    }
   
   return 0;
}
//---------------------------------------------------------------------------------------------------------//
//Esta funcióbn puede servir tanto para verificar los adyacentes del tablero del playero como de la máquina//
//---------------------------------------------------------------------------------------------------------//
int BarcoAdyacente(tablero *tabJu_Or, Naves *NavPL_OR)
    {
  
    for (int i = 0; i < TAM_TABLERO; i++)
    {
        for (int j = 0; i < TAM_TABLERO; j++)
        {
            if (tabJu_Or->espacio[i][j]!= AGUA) // Revisa si hay barcos en todas las posiciones del mapa en el tablero del Player (*tabJu_Or) 
            {
                if(NavPL_OR->InicialFilas==i && NavPL_OR->InicialColum==j){ //verifica las coordenada del barco en la posición que encotró el anterior IF

                    printf("La posición (%d,%d) que seleccionaste ya se ecnuentra ocupada por una nave\n", NavPL_OR->InicialFilas,NavPL_OR->InicialColum);
                    return 1;

                 } 
            }
            else{
                // Comprueba si hay un barco adyacente (8 vecinos)
                // fila/columna aquí están en índices 0-based

                for (int di = -1; di <= 1; di++) {
                     for (int dj = -1; dj <= 1; dj++) {
                         if (di == 0 && dj == 0) continue;
                         int nf = NavPL_OR->InicialFilas + di;
                        int nc = NavPL_OR->InicialColum + dj;
                        if (nf >= 0 && nf < TAM_TABLERO && nc >= 0 && nc < TAM_TABLERO) {
                            if (tabJu_Or->espacio[nf][nc]== AGUA) return 1;
                        }
                            }
                        }
            
                    }
        
            }

    }
    
    return 0;
}

//------------------------------------------------------------------------------//
//Confirma y ubica los barcos según las condiciones de las funciones anteriores//
//-----------------------------------------------------------------------------//

void UbicarBarco(tablero *tabJu_Or, Naves *NavPL_OR)
{

    /* Validar que el barco no esté fuera del mapa
    if (FueradelMapa(NavPL_OR) == 1) {
        printf("No se puede colocar el barco: fuera del mapa\n");
        return;
    }
    */
    /* Validar que no haya barcos adyacentes
    if (BarcoAdyacente(tabJu_Or, NavPL_OR) == 1) {
        printf("No se puede colocar el barco: posición ocupada o adyacente a otro barco\n");
        return;
    }
    */
    // Si cumple todas las condiciones, colocar el barco en el tablero
    if (NavPL_OR->orientacion == 'V') {
        // Barco vertical
        for (int i = 0; i < NavPL_OR->tamNave; i++) {
            tabJu_Or->espacio[NavPL_OR->InicialFilas + i][NavPL_OR->InicialColum] = NavPL_OR->nombarco;
        }
 
    } 
    else if (NavPL_OR->orientacion == 'H') {
        // Barco horizontal
        for (int i = 0; i < NavPL_OR->tamNave; i++) {
            tabJu_Or->espacio[NavPL_OR->InicialFilas][NavPL_OR->InicialColum + i] = NavPL_OR->nombarco;
        }
    }
}



