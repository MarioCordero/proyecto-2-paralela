# Algoritmo PageRank en C++


### Descripción

Este proyecto consiste en la implementación del algoritmo PageRank propuesto por Larry Page y Sergey Brin para clasificar la importancia de las páginas web. El algoritmo define la importancia de una página web en función del número de enlaces entrantes que recibe.


### Comandos

Ejecutar con:
```bash
    make ARGS="-src [Archivo] -dst [Destino]"
```

Ejemplo:
```bash
    make ARGS="-src prueba.txt -dst /home"
```


### Funcionalidad

Este algoritmo PageRank fue implementado en el lenguaje de programación C++ y se maneja con Makefile. A la hora de ejecutar el comando nos solicita un archivo de salida con los datos a analizar y un archivo donde escribir los resultados de calcularle la fórmula de PageRank.


El archivo que se está analizando es el de pruebas.txt, este archivo contiene varias líneas de números de la forma "2:3" indicando que el nodo dos se asocia con el nodo tres. Este archivo se procesa para calcularle el PageRank utilizando paralelismo con OpenMP y luego se escriben los resultados en la ruta de destino de manera alfabeticamente.


Para calcular el PageRank se obtiene la lista de nodos desde FileManager, se recopilan todos los IDs de los nodos en un vector nodeIDs, se establecen las constantes necesarias para el algoritmo, como el número máximo de iteraciones, el factor de amortiguación (dampingFactor), el PageRank inicial, y el de convergencia (threshold).


Se inicializa el PageRank de cada nodo tanto para el valor actual como para el valor previo. Se entra en un ciclo de iteración hasta que se cumpla el criterio de convergencia o se alcance el número máximo de iteraciones:
  - Para cada nodo, se calcula el nuevo PageRank sumando las contribuciones de los PageRanks previos de los nodos que apuntan a él, ajustado por el factor de amortiguación.
  - Se verifica si la diferencia entre el PageRank actual y el nuevo calculado es menor que el umbral, para determinar la convergencia.
  - Se actualiza el valor previo del PageRank con el valor actual para la siguiente iteración.
Una vez que el algoritmo converge, se imprime el número de iteraciones que tomó para converger.


### Límites y errores conocidos

- No se prueba con archivos muy grandes, los archivos muy grandes podrían requerir mucha memoria y hacer el programa muy lento y quizás afecte la precisión.
- No se hace verificación de nodos de si tienen nodos entrantes o salientes.
- Podrían haber condiciones de carrera.
- No se hace validación para que el archivo a leer sea "int:int".
- Leer el archivo es lento, para grandes archivos.


### Miembros del equipo
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
  - Documentación interna y externa.
  - Darle formato al código.


- **Geiner Montoya**
  - Explicación de algoritmo.
  - Corrección general de compatibilidades.
  - Implementación de paralelismo.
  - Implementación de la clase PageRank.