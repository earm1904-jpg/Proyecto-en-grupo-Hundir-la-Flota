
#ifndef JUEGO_H
#define JUEGO_H

// Constantes de juego
#define TAM_TABLERO 12
#define AGUA 'A'
#define IMPACTO 'X'
#define FALLA '0'
int TotNavs=6;// Variable Global para saber la cantidad de naves del juego
int disparos=0;
int hundidos=0;
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
   char orientacion; //Horizontal'H' o Vertical 'v' Para el rand() del PC 0->Horizontal 1->Vertical
   int ParteBarco; // 1 para POPA y 0 para PROA
   //int direction;// 1 UP, right 0 Down, left
   int ImpacNav;

   
} Naves;


// funciones
void IniciarTableros(tablero *tab);
void UbicarNavesPlayer(tablero *tab,Naves *Nav);
void UbicarNavesPC(tablero *tab,Naves *Nav);

//void UbicarNavesContr(Naves Nav);
//void DisparoJugador(int C1, int i);
//void DisparoJugador(int C1, int C2, int comprobar_tablero);
//void DisparoMaquina();




#endif