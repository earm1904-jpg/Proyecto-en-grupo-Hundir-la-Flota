
#ifndef JUEGO_H
#define JUEGO_H

// Constantes de juego
#define TAM_TABLERO 12
#define AGUA 'A'
#define IMPACTO 'X'
#define FALLA '0'
int TotNavs=6;// Variable Global para saber la cantidad de naves del juego

// crear tablero
typedef struct
{
    char espacio[TAM_TABLERO][TAM_TABLERO];
} tablero;

typedef struct
{
   char nombarco;
   int tamNave;
   int InicialFilas;
   int InicialColum;
   int CantidadNAvs;
   char orientacion; //Horizontal'H' o Vertical 'v'
   int ParteBarco; // 1 para POPA y 0 para PROA
   //int direction;// 1 UP, right 0 Down, left
   
} Naves;


// funciones
void IniciarTableros(tablero *tab);
void UbicarNavesPlayer(Naves *Nav);

//void UbicarNavesContr(Naves Nav);
//void DisparoJugador(int C1, int i);
//void DisparoJugador(int C1, int C2, int comprobar_tablero);
//void DisparoMaquina();




#endif