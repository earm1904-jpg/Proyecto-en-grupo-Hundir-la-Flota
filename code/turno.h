#ifndef TURNO_H
#define TURNO_H
#include "juego.h"

int CoorImpFilas,CoorImpColumn,turno;

int ImpactoNav(Nave *Nav, tablero *tab, tablero *tabDisp);
void turnosPlayers(Nave *Nav, tablero *tabPlayer, tablero *tabPC);
#endif