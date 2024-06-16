# README

## Implementación del Algoritmo PageRank

Este proyecto consiste en la implementación del algoritmo PageRank propuesto por Larry Page y Sergey Brin para clasificar la importancia de las páginas web. El algoritmo define la importancia de una página web en función del número de enlaces entrantes que recibe.

## Miembros del equipo
- Mario Cordero Aguilar C22306
- Nathalie Alfaro Quesada B90221
- Geiner

## Partes elaboradas por cada miembro
### Mario Cordero
- Hola

### Nathalie Alfaro
- Hola

### Requisitos
- Archivo de entrada especificado con la bandera `-src`
- Archivo de salida especificado con la bandera `-dst`
- El archivo de salida debe estar ordenado alfabéticamente por URL
- Se debe utilizar la computación en paralelo en cada iteración para acelerar el cálculo

### Implementación
1. **Lectura del Archivo de Entrada**: El programa debe leer correctamente el archivo de entrada que contiene el formato `URL origen -> URL destino`.
2. **Escritura del Archivo de Salida**: El programa debe escribir correctamente el archivo de salida con una lista de URLs de origen ordenadas alfabéticamente, seguidas por el valor calculado de PageRank.
3. **Salida Correcta**: La salida debe ser precisa y reflejar los valores de PageRank para cada URL.
4. **Ejecución en Paralelo**: El programa debe paralelizar la ejecución de manera efectiva, escalando linealmente con un aumento en el número de núcleos.
5. **Gestión de Memoria**: No debe haber fugas de memoria ni accesos inválidos detectados por Valgrind.