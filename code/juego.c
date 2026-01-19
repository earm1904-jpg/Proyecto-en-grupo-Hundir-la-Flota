#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "juego.h"
#include "Validar_ubicacion_barco.h"
#include "turno.h"
//Commit 3

// Variables globales para contar barcos colocados
int portavionesColocados = 0;
int crucerosColocados = 0;
int patullerosColocados = 0;

// Rellenando el tablero con la letra 'A' Agua
void IniciarTableros(tablero *tab)
{
    for (int i = 0; i < TAM_TABLERO; i++)
{

    for (int j = 0; j < TAM_TABLERO; j++)
    {
       tab->espacio[i][j] = AGUA; // ->Esto indica que es un paso por referencia: la dirección de memoria de la variable original, no una copia.
    }
}

}

void UbicarNavesPlayer(tablero *tab, Naves *Nav)
{
  
    
    //TotNavs=6 Variable global total de naves
    while(TotNavs!=0){ //Una vez ubique todas las naves se saldrá del bucle
    
    printf("¿Cuál barco quieres ubicar?\n");
    printf("P Portaviones (quedan: %d)\n", 1 - portavionesColocados);
    printf("C Cruceros (quedan: %d)\n", 2 - crucerosColocados);
    printf("T Patrullero (quedan: %d)\n", 3 - patullerosColocados);
    scanf(" %c", &Nav->nombarco);
    Nav->nombarco = toupper(Nav->nombarco);

    

    //----Portaviones-----///
    if (Nav->nombarco=='P'){ 
        if (portavionesColocados >= 1) {
            printf("Ya has colocado el máximo de Portaviones (1).\n");
            continue;
        }
        Nav->tamNave=4;
        Nav->CantidadNAvs=1;

            while(Nav->CantidadNAvs!=0){

                printf("¿Cómo quieres ubicar el barco, desde Proa  o Popa?\n");
                printf("1) Proa\n");
                printf("0) Popa\n");
                scanf(" %d", &Nav->ParteBarco);
                
                if (Nav->ParteBarco != 1 && Nav->ParteBarco != 0) {
                    printf("Número inválido. Por favor, ingresa 1 (Proa) o 0 (Popa)\n");
                    continue;
                }

                printf("Digita las coordenas para ubicar tu barco, recueda que son números enteros cero y once\n");
                printf("Digita la coordenada de las filas\n");
                scanf(" %d", &Nav->InicialFilas);
                printf("Digita la coordenada de las columnas\n");
                scanf(" %d", &Nav->InicialColum);

            if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
            {
                 printf("¿En qué horientación vas a ubicar el barco?\n");
                 printf("H Horizontal\n");
                 printf("V Vertical\n");
                 scanf(" %c", &Nav->orientacion);
                 Nav->orientacion = toupper(Nav->orientacion);
                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab,Nav)==0){
                            UbicarBarco(tab, Nav);
                            portavionesColocados++;
                             Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        else{
                            printf("Hay un barco adyacente. Intenta de nuevo.\n");
                            continue;
                        }
                    }
                    else{
                        printf("El barco está fuera del mapa. Intenta de nuevo.\n");
                        continue;
                    }
                    

                 }
                 else{
                    printf("¿Escoge una opción valida?\n");
                    printf("¿En qué horientación vas a ubicar el barco?\n");
                    printf("H Horizontal\n");
                    printf("V Vertical\n");
                    scanf(" %c", &Nav->orientacion);
                 Nav->orientacion = toupper(Nav->orientacion);
                    continue;
                 }

            }
            
        }
        
        //printf("Ya no tienes más Portaviones\n");

        }
        //----Cruceros-----///
    else if(Nav->nombarco=='C'){
        if (crucerosColocados >= 2) {
            printf("Ya has colocado el máximo de Cruceros (2).\n");
            continue;
        }
            Nav->tamNave=3;
            Nav->CantidadNAvs=2;

            while(Nav->CantidadNAvs!=0){

                printf("¿Cómo quieres ubicar el barco, desde Proa  o Popa?\n");
                printf("1) Proa\n");
                printf("0) Popa\n");
                scanf(" %d", &Nav->ParteBarco);
                
                if (Nav->ParteBarco != 1 && Nav->ParteBarco != 0) {
                    printf("Número inválido. Por favor, ingresa 1 (Proa) o 0 (Popa)\n");
                    continue;
                }

                printf("Digita las coordenas para ubicar tu barco, recueda que son números enteros cero y once\n");
                printf("Digita la coordenada de las filas\n");
                scanf(" %d", &Nav->InicialFilas);
                printf("Digita la coordenada de las columnas\n");
                scanf(" %d", &Nav->InicialColum);

                if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
                {
                 printf("¿En qué horientación vas a ubicar el barco?\n");
                 printf("H Horizontal\n");
                 printf("V Vertical\n");
                 scanf(" %c", &Nav->orientacion);
                 Nav->orientacion = toupper(Nav->orientacion);
                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab,Nav)==0){
                            UbicarBarco(tab, Nav);
                            crucerosColocados++;
                            Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        else{
                            printf("Hay un barco adyacente. Intenta de nuevo.\n");
                            continue;
                        }
                    }
                    else{
                        printf("El barco está fuera del mapa. Intenta de nuevo.\n");
                        continue;
                    }
                    

                 }
                 else{
                    printf("¿Escoge una opción valida?\n");
                    printf("¿En qué horientación vas a ubicar el barco?\n");
                    printf("H Horizontal\n");
                    printf("V Vertical\n");
                    scanf(" %c", &Nav->orientacion);
                 Nav->orientacion = toupper(Nav->orientacion);
                    continue;
                 }

            }


            }

        }


        //----Pratrulleros-----///
    else if(Nav->nombarco=='T'){
        if (patullerosColocados >= 3) {
            printf("Ya has colocado el máximo de Patrulleros (3).\n");
            continue;
        }

            Nav->tamNave=2;
            Nav->CantidadNAvs=3;

            while(Nav->CantidadNAvs!=0){

                printf("¿Cómo quieres ubicar el barco, desde Proa  o Popa?\n");
                printf("1) Proa\n");
                printf("0) Popa\n");
                scanf(" %d", &Nav->ParteBarco);
                
                if (Nav->ParteBarco != 1 && Nav->ParteBarco != 0) {
                    printf("Número inválido. Por favor, ingresa 1 (Proa) o 0 (Popa)\n");
                    continue;
                }

                printf("Digita las coordenas para ubicar tu barco, recueda que son números enteros cero y once\n");
                printf("Digita la coordenada de las filas\n");
                scanf(" %d", &Nav->InicialFilas);
                printf("Digita la coordenada de las columnas\n");
                scanf(" %d", &Nav->InicialColum);

                if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
                {
                 printf("¿En qué horientación vas a ubicar el barco?\n");
                 printf("H Horizontal\n");
                 printf("V Vertical\n");
                 scanf(" %c", &Nav->orientacion);
                 Nav->orientacion = toupper(Nav->orientacion);
                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab,Nav)==0){
                            UbicarBarco(tab, Nav);
                            patullerosColocados++;
                            Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        else{
                            printf("Hay un barco adyacente. Intenta de nuevo.\n");
                            continue;
                        }
                    }
                    else{
                        printf("El barco está fuera del mapa. Intenta de nuevo.\n");
                        continue;
                    }
                    

                 }
                 else{
                    printf("¿Escoge una opción valida?\n");
                    printf("¿En qué horientación vas a ubicar el barco?\n");
                    printf("H Horizontal\n");
                    printf("V Vertical\n");
                    scanf(" %c", &Nav->orientacion);
                 Nav->orientacion = toupper(Nav->orientacion);
                    continue;
                 }

            }

            }

        }
        else{
            printf("¿Escoge una opción valida?\n");
            continue;
        }
    }
    printf("\n¡Has ubicado todas tus NAVES!\n\n");

}


void UbicarNavesPC(tablero *tab,Naves *Nav)
{

    int nDirec; // Variable para el randon de la dirección de las naves 0->Horizontal, 1->Vertical

    while(TotNavs!=0){
        Nav->ParteBarco= rand()% 2;
        nDirec=Nav->ParteBarco; 
        
        //Portaviones PC
        if (Nav->nombarco=='P'){ 
            Nav->tamNave=4;
            Nav->CantidadNAvs=1;

            while(Nav->CantidadNAvs!=0){
                    
                // Valores randon para la posición incial de cada nave de 0-11
                    Nav->InicialFilas=rand()% 12;
                    Nav->InicialColum=rand()% 12;

                if (Nav->ParteBarco==1|| Nav->ParteBarco==0 ){//PROA 1 / 0 POPA

                    if(nDirec==1){
                        Nav->orientacion='V';

                    }
                    else{
                        Nav->orientacion='H';
                    }

                    if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                        if(FueradelMapa(Nav)==0){

                            if(BarcoAdyacente(tab,Nav)==0){
                                UbicarBarco(tab, Nav);
                                Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                                TotNavs=TotNavs-1;
                            }

                        }
                    }
                }
            }
        }
        
        //Cruceros PC
        else if (Nav->nombarco=='C'){ 
        Nav->tamNave=3;
        Nav->CantidadNAvs=2;

            while(Nav->CantidadNAvs!=0){

              // Valores randon para la posición incial de cada nave de 0-11
                Nav->InicialFilas=rand()% 12;
                Nav->InicialColum=rand()% 12;

            if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
            {
                 if(nDirec==1){
                    Nav->orientacion='V';

                 }
                 else{
                    Nav->orientacion='H';
                 }

                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab,Nav)==0){
                            UbicarBarco(tab, Nav);
                             Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        
                    }
                    

                 }
                 
            }
            
        }
        
        }

        //Patrulleros PC
        else if (Nav->nombarco=='T'){ 
        Nav->tamNave=2;
        Nav->CantidadNAvs=3;

            while(Nav->CantidadNAvs!=0){

              // Valores randon para la posición incial de cada nave de 0-11
                Nav->InicialFilas=rand()% 12;
                Nav->InicialColum=rand()% 12;

            if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
            {
                 if(nDirec==1){
                    Nav->orientacion='V';

                 }
                 else{
                    Nav->orientacion='H';
                 }

                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab,Nav)==0){
                            UbicarBarco(tab, Nav);
                             Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        
                    }
                    

                 }
                 
            }
            
        }
        
        }
    }
}




