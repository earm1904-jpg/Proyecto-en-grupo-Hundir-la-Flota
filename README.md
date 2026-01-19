# Proyecto en grupo: HUNDIR LA FLOTA

Somos el grupo formado por:
- Edwin Armando Ramirez Monroy
- Jon Ugalde Urrutia
- Nicole Pastran Lindo
- Johan Henao Mora
- Pablo Giner Bernat

## Descripción General del Funcionamiento

El juego se estructura en las siguientes fases:

1. **Inicialización**
   - Creación e inicialización de los tableros.
   - Definición de las naves y sus tamaños.

2. **Colocación de barcos**
   - Validación de posiciones.
   - Comprobación de solapamientos y límites del tablero.

3. **Desarrollo de la partida**
   - Introducción de coordenadas por parte del jugador.
   - Validación del disparo.
   - Detección de agua, impacto y hundimiento.
   - Actualización de tableros y contadores.
   - Gestión de turnos.

4. **Finalización**
   - La partida termina cuando todas las naves han sido hundidas.
   - Se muestra la puntuación final.

## ORGANIZACIÓN DEL PROYECTO

El proyecto se ha diseñado siguiendo un enfoque **modular**, dividiendo la funcionalidad del juego en distintos archivos fuente (`.c`) y cabeceras (`.h`).  
Este planteamiento ha permitido facilitar la lectura del código y simplificar el proceso de depuración.

Durante el desarrollo cada módulo se encargaba de una responsabilidad concreta del juego.

### MÓDULOS UTILIZADOS DURANTE EL DESARROLLO

- **`menu.c / menu.h`**  
  Contiene el menú principal del juego y gestiona la interacción inicial con el usuario.  
  Permite seleccionar opciones como iniciar partida o salir del programa, actuando como punto de entrada al flujo del juego.

- **`juego.c / juego.h`**  
  Incluye la lógica general del juego:
  - Inicialización de los tableros.
  - Control del estado de la partida.
  - Coordinación entre los distintos módulos.
  Este archivo actúa como núcleo del programa.

- **`turno.c / turno.h`**  
  Gestiona el sistema de turnos y disparos:
  - Solicitud y validación de coordenadas.
  - Comprobación de impactos, fallos y hundimientos.
  - Actualización de los tableros.
  - Control del cambio de turno entre jugador y ordenador.
  
  En este módulo se corrigieron errores lógicos importantes (uso de bucles innecesarios, control de retornos y validación de disparos repetidos).

- **`barcos.c`**  
  Define las características de las naves:
  - Tipos de barcos.
  - Tamaños.
  - Inicialización de sus valores.
  
  Este módulo permite centralizar toda la información relacionada con las naves del juego.

- **`Validar_ubicacion_barco.c / .h`**  
  Encargado de comprobar que la colocación de los barcos es válida:
  - No se salen del tablero.
  - No se solapan con otros barcos.
  - Respetan las reglas del juego.
  
  Esta validación es fundamental para evitar errores durante la partida.

- **`ShowTablero.c / ShowTablero.h`**  
  Se ocupa exclusivamente de la visualización del tablero por consola.
  Permite mostrar de forma clara el estado del juego al usuario, separando la lógica del juego de la presentación.

- **`puntuaciones.c / puntuaciones.h`**  
  Gestiona el cálculo y almacenamiento de las puntuaciones finales de las partidas.
  Permite registrar resultados y mostrar información al finalizar el juego.