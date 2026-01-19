// Código C actualizado con las mejoras solicitadas.
// (Plantilla en construcción. Completaré cada sección luego.)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #include <windows.h>   // WinApi header (comentado para Linux)


// Prototipos
int validar_entrada_y_vecino(int *fila, int *columna, int casillas, int board[casillas][casillas]);
int es_adyacente(int fila, int columna, int casillas, int board[casillas][casillas]);
int puede_colocar_barco(int fila0, int col0, int tam, int dir, int casillas, int board[casillas][casillas]);
void colocar_barco_en_tablero(int fila0, int col0, int tam, int dir, int casillas, int board[casillas][casillas]);
void colocar_barcos_auto(int casillas, int board[casillas][casillas], int estrcjueg[][2], size_t tipobarcos);
void colocar_barcos_usuario(int casillas, int board[casillas][casillas], int estrcjueg[][2], size_t tipobarcos);
void imprimir_tableros(int casillas,int jugador[casillas][casillas],int impactos[casillas][casillas]) ;
int disparar_usuario(int casillas, int comp_board[casillas][casillas]);// int hits_board[casillas][casillas]);
int disparo_maquina_aleatorio(int casillas, int player_board[casillas][casillas]);

void marcar_como_hundido(int f, int c, int casillas, int board[casillas][casillas]);
int contar_partes_vivas(int f, int c, int casillas, int board[casillas][casillas], int visitado[casillas][casillas]);
// --------------------------------------------------
// MAIN (comentado - el main está en menu.c)
// --------------------------------------------------
/*
int main(void)
{
    unsigned seed = (unsigned)(time(NULL) * 100000);
    srand(seed);

    int casillas;
    printf("¡Bienvenido a Barcos! ¿Con cuántas casillas quieres jugar? (1-25)");
    while (1) {
        if (scanf("%d", &casillas) != 1) { while(getchar() != '\n'); printf("Introduce un número: "); continue; }
        if (casillas >= 1 && casillas <= 25) break;
        printf("Introduce un número entre 1 y 25:");
    }

    int player_board[casillas][casillas];     // 0 = agua, 1 = barco
    int comp_board[casillas][casillas];       // tablero real del ordenador (oculto)
   
    for (int i = 0; i < casillas; i++)
        for (int j = 0; j < casillas; j++)
            player_board[i][j] = comp_board[i][j]=0; //he eliminado hits_board

    int estrcjueg[4][2] = {{1,4},{2,3},{3,2},{4,1}}; // {cantidad, tamaño}
    size_t tipobarcos = sizeof(estrcjueg) / sizeof(estrcjueg[0]);

    printf("Elige modo de colocación para EL JUGADOR:");
    printf("1) Semimanual (tú eliges inicio+orientación)");
    printf("2) Automático (el programa coloca los barcos)");
    int modo_usuario = 0;
    while (1) {
        if (scanf("%d", &modo_usuario) != 1) { while(getchar()!='\n'); continue; }
        if (modo_usuario == 1 || modo_usuario == 2) break;
        printf("Elige 1 o 2:");
    }

    // Colocar barcos del jugador
    if (modo_usuario == 2) {
        colocar_barcos_auto(casillas, player_board, estrcjueg, tipobarcos);
        printf("Barcos del jugador colocados automáticamente.");
    } else {
        colocar_barcos_usuario(casillas, player_board, estrcjueg, tipobarcos);
    }

    // Colocar barcos del ordenador (siempre automático)
    colocar_barcos_auto(casillas, comp_board, estrcjueg, tipobarcos);
    printf("Barcos del ordenador colocados (oculto).");

    // Bucle de juego: turnos alternos (1 jugador, 2 ordenador)
    int turno = 1; // 1 = jugador, 2 = ordenador
    int jugador_gana = 0, maquina_gana = 0;

    while (!jugador_gana && !maquina_gana) {
        if (turno == 1) {
            printf("--- Turno del JUGADOR --");
            imprimir_tableros(casillas, player_board,comp_board);
            if (disparar_usuario(casillas, comp_board)){
                // comprobar si todos los barcos de la maquina han sido hundidos
                int quedan = 0;
                for (int i = 0; i < casillas; i++)
                    for (int j = 0; j < casillas; j++)
                        if (comp_board[i][j] == 1) quedan++;
                if (quedan == 0) { jugador_gana = 1; break; }
                printf("Has acertado, dispara de nuevo.");
                // jugador sigue (en este diseño, podría seguir disparando; para alternancia estricta, comentar lo anterior)
                // turno = 2; // comentar si quieres que siga disparando al acertar
            } else {
                turno = 2;
            }
        } else {
            printf("--- Turno de la MÁQUINA ---");
            if (disparo_maquina_aleatorio(casillas, player_board)) {
                // comprobar si quedan barcos jugador
                int quedan = 0;
                for (int i = 0; i < casillas; i++)
                    for (int j = 0; j < casillas; j++)
                        if (player_board[i][j] == 1) quedan++;
                if (quedan == 0) { maquina_gana = 1; break; }
                printf("La máquina acertó y dispara de nuevo.");
                // maquina sigue; si prefieres alternancia estricta, cambia turno = 1
            } else {
                turno = 1;
            }
        }
    }

    if (jugador_gana) printf("¡FELICIDADES! Has hundido toda la flota enemiga.");
    if (maquina_gana) printf("HAS PERDIDO. La máquina hundió tu flota.");

    printf("Tablero del jugador:"); imprimir_tableros(casillas, player_board,comp_board);
    printf("Tablero real del ordenador (oculto durante el juego, mostrado ahora):"); imprimir_tableros(casillas, comp_board,comp_board);
    

    return 0;
}
*/

// --------------------------------------------------
// Lee y valida entrada del usuario y verifica adyacencia
// Esta función fusiona la validación de entrada y la comprobación
// de adyacencia (versipisa_vecino) que pediste.
// Devuelve 1 si la entrada es válida (formato, rango, libre y sin vecinos), 0 en caso contrario.
// fila/columna deben pasarse por puntero (valores 1..casillas)
// --------------------------------------------------
int validar_entrada_y_vecino(int *fila, int *columna, int casillas, int board[casillas][casillas])
{
    if (scanf(" %d %d", fila, columna) != 2) {
        printf("Error de formato. Usa 'fila columna'.");
        while (getchar() != '\n');
        return 0;
    }

    if (*fila < 1 || *fila > casillas || *columna < 1 || *columna > casillas) {
        printf("Coordenadas fuera de rango. Introduce valores entre 1 y %d.", casillas);
        return 0;
    }

    int f = *fila - 1;
    int c = *columna - 1;

    if (board[f][c] == 1) {
        printf("Esa casilla (%d, %d) ya está ocupada.", *fila, *columna);
        return 0;
    }

    if (es_adyacente(f, c, casillas, board)) {
        printf("Error: No puedes colocar un barco adyacente a uno existente.");
        return 0;
    }

    return 1;
}

// --------------------------------------------------
// Comprueba si hay un barco adyacente (8 vecinos)
// fila/columna aquí están en índices 0-based
// --------------------------------------------------
int es_adyacente(int fila, int columna, int casillas, int board[casillas][casillas])
{
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int nf = fila + di;
            int nc = columna + dj;
            if (nf >= 0 && nf < casillas && nc >= 0 && nc < casillas) {
                if (board[nf][nc] == 1) return 1;
            }
        }
    }
    return 0;
}

// --------------------------------------------------
// Comprueba si un barco de tamaño tam puede colocarse
// en (fila0,col0) con dirección dir (1=H,2=V)
// fila0/col0 son 
// --------------------------------------------------
int puede_colocar_barco(int fila0, int col0, int tam, int dir, int casillas, int board[casillas][casillas])
{
    for (int k = 0; k < tam; k++) {
        int nf = fila0 + (dir == 2 ? k : 0);
        int nc = col0 + (dir == 1 ? k : 0);

        if (nf < 0 || nf >= casillas || nc < 0 || nc >= casillas) return 0; // sale del tablero
        if (board[nf][nc] == 1) return 0; // solapa con otro barco
        if (es_adyacente(nf, nc, casillas, board)) return 0; // adyacente a otro
    }
    return 1;
}

// --------------------------------------------------
// Coloca un barco en el tablero (sin comprobar)
// fila0/col0 índices 0-based
// --------------------------------------------------
void colocar_barco_en_tablero(int fila0, int col0, int tam, int dir, int casillas, int board[casillas][casillas])
{
    for (int k = 0; k < tam; k++) {
        int nf = fila0 + (dir == 2 ? k : 0);
        int nc = col0 + (dir == 1 ? k : 0);
        board[nf][nc] = 1;
    }
}

// --------------------------------------------------
// Colocación automática: prueba posiciones aleatorias hasta que encaje
// --------------------------------------------------
void colocar_barcos_auto(int casillas, int board[casillas][casillas], int estrcjueg[][2], size_t tipobarcos)
{
    for (size_t i = 0; i < tipobarcos; i++) {
        int cantidad = estrcjueg[i][0];
        int tam = estrcjueg[i][1];

        for (int j = 0; j < cantidad; j++) {
            int intentos = 0;
            while (1) {
                intentos++;
                int fila0 = rand() % casillas;
                int col0 = rand() % casillas;
                int dir = (tam == 1) ? 1 : (rand() % 2) + 1; // 1=H,2=V

                if (puede_colocar_barco(fila0, col0, tam, dir, casillas, board)) {
                    colocar_barco_en_tablero(fila0, col0, tam, dir, casillas, board);
                    break;
                }
                if (intentos > 10000) { // protección anti-bucle infinito
                    fprintf(stderr, "No se pudo colocar un barco automáticamente (demasiados intentos).");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}

// --------------------------------------------------
// Colocación semimanual por parte del usuario
// Si modo_semimanual == 1: pide inicio + orientación
// --------------------------------------------------
void colocar_barcos_usuario(int casillas, int board[casillas][casillas], int estrcjueg[][2], size_t tipobarcos)
{
    printf("=== COLOCACIÓN DE BARCOS (USUARIO) ===");

    for (size_t i = 0; i < tipobarcos; i++) {
        int cantidad = estrcjueg[i][0];
        int tam = estrcjueg[i][1];

        for (int j = 0; j < cantidad; j++) {
            printf("Coloca barco tipo %zu (tamaño %d) — nº %d de %d", i+1, tam, j+1, cantidad);

            while (1) {
                int fila, columna;
                printf("Introduce fila y columna inicial: ");
                if (!validar_entrada_y_vecino(&fila, &columna, casillas, board)) continue;

                int f0 = fila - 1;
                int c0 = columna - 1;
                int dir = 1; // horizontal por defecto

                if (tam > 1) {
                    printf("Horizontal (1) o Vertical (2)? ");
                    if (scanf("%d", &dir) != 1) { while(getchar()!='\n'); printf("Entrada inválida."); continue; }
                    if (dir != 1 && dir != 2) { printf("Dirección inválida."); continue; }
                }

                if (!puede_colocar_barco(f0, c0, tam, dir, casillas, board)) {
                    printf("No se puede colocar el barco en esa posición (sale, solapa o está adyacente).");
                    continue;
                }

                colocar_barco_en_tablero(f0, c0, tam, dir, casillas, board);
                printf("Barco colocado.");
                break;
            }
        }
    }
}

// --------------------------------------------------
// Imprime un tablero. Si oculto==1, muestra '.' en lugar de los barcos (útil para el tablero del ordenador)
// Valores: 0=agua, 1=barco, 2=agua marcado, 3=impacto
// --------------------------------------------------
void imprimir_tableros(int casillas, int jugador[casillas][casillas], int impactos[casillas][casillas]) 
{
    printf("\n   TU TABLERO %*s TABLERO DEL ORDENADOR (TUS DISPAROS)\n\n",
           casillas * 3, "");

    // Encabezado columnas
    printf("    ");
    for (int c = 1; c <= casillas; c++) printf("%2d ", c);
    printf("        ");
    for (int c = 1; c <= casillas; c++) printf("%2d ", c);
    printf("\n");

    for (int f = 0; f < casillas; f++) {

        // --- TABLERO DEL JUGADOR ---
        printf("%2d | ", f + 1);
        for (int c = 0; c < casillas; c++) {
            char ch = jugador[f][c] + '0';
            
            if (jugador[f][c] == 0) {
                // Azul clarito (no tocado)
                
            } else if (jugador[f][c] == 2) {
                // Azul oscuro (agua)
                ch = 'A';
            } else if (jugador[f][c] == 3) {
                // Amarillo (tocado)
                ch = 'X';
            }

            printf("%c  ", ch);
        }

        printf("   ");  // Separación

        // --- TABLERO DE DISPAROS (IMPACTOS) ---
        printf("%2d | ", f + 1);
        for (int c = 0; c < casillas; c++) {
            char ch = '0';
            int valor = impactos[f][c];

            if (valor == 0 || valor==1) {
                // Azul clarito (mar vacío)
                //ch = '';
            } else if (valor == 2) {
                // Azul oscuro (agua)
                ch = 'A';
            } else if (valor == 3) {
                // Amarillo (tocado)
                ch = 'X';
            } else if (valor == 4) {
                // Rojo (hundido)
                ch = 'H';
            }

            printf("%c  ", ch);
        }
        printf("\n");
    }
    printf("\n");
}


// --------------------------------------------------
// Disparo del usuario contra el tablero del ordenador
// Actualiza hits_board: 2=agua, 3=impacto
// Devuelve 1 si ha sido impacto, 0 si agua
// --------------------------------------------------
int disparar_usuario(int casillas, int comp_board[casillas][casillas])
{
    int fila, columna;
    while (1) {
        printf("Introduce fila y columna para disparar: ");
        if (scanf(" %d %d", &fila, &columna) != 2) { while(getchar()!='\n'); printf("Formato incorrecto."); continue; }
        if (fila < 1 || fila > casillas || columna < 1 || columna > casillas) { printf("Fuera de rango (1-%d).", casillas); continue; }
        int f = fila - 1;
        int c = columna - 1;
        if (comp_board[f][c] != 0 && comp_board[f][c]!= 1) { printf("Ya has disparado ahí."); continue; }

        if (comp_board[f][c] == 1) {
            //printf("¡TOCADO!");
            //hits_board[f][c] = 3;
            comp_board[f][c] = 3; // marcar como hundido parcial (o quita el barco)
            // Preparamos matriz de visitados para la comprobación
            int visitado[casillas][casillas];
                for(int i=0; i<casillas; i++) 
                    for(int j=0; j<casillas; j++) visitado[i][j] = 0;

                // 1. Comprobamos si quedan partes vivas (1)
                if (contar_partes_vivas(f, c, casillas, comp_board, visitado) == 0) {
                    printf("¡BARCO HUNDIDO!\n");
                // 2. Si no quedan vivas, transformamos los 3 en 4
                    marcar_como_hundido(f, c, casillas, comp_board);
                    // --- CRUCIAL: Sincronizar TODO el barco hundido en hits_board ---
                    /*for(int i=0; i<casillas; i++) {
                        for(int j=0; j<casillas; j++) {
                            if (comp_board[i][j] == 4) {
                                hits_board[i][j] = 4;
                            }
                            if (comp_board[i][j] == 2) {
                                hits_board[i][j] = 2;
                            }
                        }
                    }*/
                } 
                else {
                    printf("Tocado\n");
                    //hits_board[f][c] = 3;
                }
            
            return 1;
        

        } else {
            printf("Agua.");
            //hits_board[f][c] = 2;
            comp_board[f][c] = 2;
            return 0;
        }
    }
}

// --------------------------------------------------
// Disparo aleatorio de la máquina contra el tablero del jugador
// Devuelve 1 si impacto, 0 si agua
// --------------------------------------------------
int disparo_maquina_aleatorio(int casillas, int player_board[casillas][casillas])
{
    int f, c;
    while (1) {
        f = rand() % casillas;
        c = rand() % casillas;
        if (player_board[f][c] == 2 || player_board[f][c] == 3) continue; // ya disparado (usamos 2/3 para marcar)
        break;
    }

    if (player_board[f][c] == 1) {
        printf("La máquina dispara en (%d,%d) — ¡TOCADO!", f+1, c+1);
        player_board[f][c] = 3; // marcar como tocado/quitar
        return 1;
    } else {
        printf("La máquina dispara en (%d,%d) — Agua.", f+1, c+1);
        player_board[f][c] = 2; // marcar que ahí ya disparó y fue agua
        return 0;
    }
}
//dos funciones mas contar partes vivas y marcar 4 hundido

int contar_partes_vivas(int f, int c, int casillas, int board[casillas][casillas], int visitado[casillas][casillas]) {
    // Si salimos del tablero, es agua (0) o ya visitado, paramos
    if (f < 0 || f >= casillas || c < 0 || c >= casillas || board[f][c] == 0 || board[f][c] == 2 || visitado[f][c]) {
        return 0;
    }

    visitado[f][c] = 1; // Marcamos para no entrar en bucle infinito
    int vivas = (board[f][c] == 1) ? 1 : 0;

    // Solo buscamos en cruz (arriba, abajo, izquierda, derecha), los barcos no son diagonales
    vivas += contar_partes_vivas(f + 1, c, casillas, board, visitado);
    vivas += contar_partes_vivas(f - 1, c, casillas, board, visitado);
    vivas += contar_partes_vivas(f, c + 1, casillas, board, visitado);
    vivas += contar_partes_vivas(f, c - 1, casillas, board, visitado);  
    printf(" partes vivas %d \n",vivas);
    return vivas;
}
// marcar
void marcar_como_hundido(int f, int c, int casillas, int board[casillas][casillas]) {
    // Si la casilla está fuera, no es un 3 (tocado), o ya es 4 (hundido), salimos
    if (f < 0 || f >= casillas || c < 0 || c >= casillas || board[f][c] != 3) {
        return;
    }

    // Cambiamos el Tocado (3) por Hundido (4)
    board[f][c] = 4;
    for (int df = -1; df <= 1; df++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nf = f + df;
                int nc = c + dc;
                // Si la celda vecina está dentro del tablero y es agua (0), marcar como 2
                if (nf >= 0 && nf < casillas && nc >= 0 && nc < casillas) {
                    if (board[nf][nc] == 0) {
                        board[nf][nc] = 2;

                    }
                }
            }
     }


    // Expandimos en cruz para buscar el resto de piezas del barco
    marcar_como_hundido(f + 1, c, casillas, board);
    marcar_como_hundido(f - 1, c, casillas, board);
    marcar_como_hundido(f, c + 1, casillas, board);
    marcar_como_hundido(f, c - 1, casillas, board);
}