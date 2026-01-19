#include <stdio.h>
#include "juego.h"
#include "Validar_ubicacion_barco.h"

//Commit 1
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
//---------------------------------------------------------------------------------------------------------//
//Esta función verifica si hay un barco superpuesto en el tablero del jugador//
//---------------------------------------------------------------------------------------------------------//
int BarcoAdyacente(tablero *tabJu_Or, Naves *NavPL_OR)
{
    // Obtenemos las coordenadas que ocupará el barco
    int filaInicio = NavPL_OR->InicialFilas;
    int colInicio = NavPL_OR->InicialColum;
    int tamano = NavPL_OR->tamNave;
    char orientacion = NavPL_OR->orientacion;
    
    // Recorremos todas las posiciones que ocupará el barco
    for (int k = 0; k < tamano; k++) {
        int fila, col;
        
        if (orientacion == 'H') {
            // Barco horizontal: avanza en columnas
            fila = filaInicio;
            col = colInicio + k;
        } else {
            // Barco vertical: avanza en filas
            fila = filaInicio + k;
            col = colInicio;
        }
        
        // Verificar si la posición actual está fuera del mapa
        if (fila < 0 || fila >= TAM_TABLERO || col < 0 || col >= TAM_TABLERO) {
            return 1; // Fuera del mapa
        }
        
        // Verificar si hay un barco en esa posición (superposición)
        if (tabJu_Or->espacio[fila][col] != AGUA) {
            printf("La posicion (%d,%d) esta ocupada por una nave\n", fila, col);
            return 1;
        }
    }
    
    return 0; // Posición válida
}

//------------------------------------------------------------------------------//
//Confirma y ubica los barcos según las condiciones de las funciones anteriores//
//-----------------------------------------------------------------------------//

void UbicarBarco(tablero *tabJu_Or, Naves *NavPL_OR)
{

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
    
    // Mensaje de confirmación
    char *nombreBarco = "";
    if (NavPL_OR->nombarco == 'P') {
        nombreBarco = "Portaviones";
    } else if (NavPL_OR->nombarco == 'C') {
        nombreBarco = "Crucero";
    } else if (NavPL_OR->nombarco == 'T') {
        nombreBarco = "Patrullero";
    }
    
    printf("\n¡%s colocado exitosamente en coordenadas (%d,%d) - Orientación %c!\n\n", 
           nombreBarco, NavPL_OR->InicialFilas, NavPL_OR->InicialColum, NavPL_OR->orientacion);
}
