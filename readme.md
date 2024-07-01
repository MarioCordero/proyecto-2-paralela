 # Algoritmo PageRank, implementado en C++
## Descripción
Este proyecto consiste en la implementación del algoritmo PageRank propuesto por Larry Page y Sergey Brin para clasificar la importancia de las páginas web. El algoritmo define la importancia de una página web en función del número de enlaces entrantes que recibe.

## Como usar


Ejecutar con:
```bash
    make ARGS="-src [Archivo] -dst [Destino]"
    make ARGS="-src prueba.txt -dst /home"
```

## Miembros del equipo
- Mario Cordero Aguilar C22306
- Nathalie Alfaro Quesada B90221
- Geiner Montoya Barrientos C25063

### Aportes de cada miembro
- **Mario Cordero**
  - Coordinación y gerencia del proyecto.
  - Creación y configuración del Makefile.
  - Implementación clase controladora.


- **Nathalie Alfaro**
  - Implementación de la clase FileManager.
  - Implementación de archivo prueba.txt
  - Documentacion interna.
  - Darle formato al codigo.

- **Geiner Montoya**
  - Explicación de algoritmo.
  - Corrección general de compatibilidades.
  - Implementación de paralelismo.
  - Implementación de formula de pageRank.
  - Implementación clase pageRank.