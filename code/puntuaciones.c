#include "puntuaciones.h"
#include <string.h>
#include <stdio.h>

/* --------------------------------------------------
   Inicializa la estructura de puntuación
-------------------------------------------------- */
void InicializarPuntuacion(Puntuacion *p, const char *nombre)
{
    strcpy(p->nombre, nombre);
    p->disparos = 0;
    p->impactos = 0;
    p->hundidos = 0;
    p->puntos = 0;
}

/* --------------------------------------------------
   Registra un disparo realizado
-------------------------------------------------- */
void RegistrarDisparo(Puntuacion *p)
{
    p->disparos++;
}

/* --------------------------------------------------
   Registra un impacto al enemigo
-------------------------------------------------- */
void RegistrarImpacto(Puntuacion *p)
{
    p->impactos++;
}

/* --------------------------------------------------
   Registra un barco hundido
-------------------------------------------------- */
void RegistrarHundido(Puntuacion *p)
{
    p->hundidos++;
}

/* --------------------------------------------------
   Calcula la puntuación final
   - 10 puntos por impacto
   - 20 puntos por barco hundido
   - 50 puntos extra si gana
-------------------------------------------------- */
void CalcularPuntos(Puntuacion *p, int gano)
{
    p->puntos = (p->impactos * 10) + (p->hundidos * 20);

    if (gano)
    {
        p->puntos += 50;
    }
}

/* --------------------------------------------------
   Guarda la puntuación en el archivo de texto
-------------------------------------------------- */
void GuardarPuntuacion(Puntuacion p)
{
    FILE *archivo = fopen(ARCHIVO_PUNTUACIONES, "a");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de puntuaciones.\n");
        return;
    }

    fprintf(archivo, "%s %d %d %d %d\n",
            p.nombre,
            p.disparos,
            p.impactos,
            p.hundidos,
            p.puntos);

    fclose(archivo);
}

/* --------------------------------------------------
   Muestra todas las puntuaciones guardadas
-------------------------------------------------- */
void MostrarPuntuaciones()
{
    FILE *archivo = fopen(ARCHIVO_PUNTUACIONES, "r");
    Puntuacion p;

    if (archivo == NULL)
    {
        printf("No hay puntuaciones registradas.\n");
        return;
    }

    printf("\n--- PUNTUACIONES ---\n");
    printf("JUGADOR\tDISPAROS\tIMPACTOS\tHUNDIDOS\tPUNTOS\n");

    while (fscanf(archivo, "%s %d %d %d %d",
                  p.nombre,
                  &p.disparos,
                  &p.impactos,
                  &p.hundidos,
                  &p.puntos) != EOF)
    {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",
               p.nombre,
               p.disparos,
               p.impactos,
               p.hundidos,
               p.puntos);
    }

    fclose(archivo);
}