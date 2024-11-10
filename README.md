# Bigram Analyzer

Práctica final de la asignatura de **Metodología de Programación** del Doble Grado en Ingeniería Informática y Matemáticas de la Universidad de Granada.

## Descripción

El programa tiene como función analizar la cantidad de bigramas presentes en un texto proporcionado como argumento y organizarlos en un archivo de salida, lo que facilita su estudio y comparación con otros documentos lingüísticos, con el fin de determinar el idioma en el que está redactado.

## Compilación y Ejecución

- Para compilar el programa en **Linux**, debe introducirse el siguiente comando en la terminal:

    ``make``

    Este comando generará dos nuevas carpetas, denominadas ``build`` y ``data``, junto con los archivos correspondientes dentro de ellas.

- Para ejecutarlo, podemos aprovechar la ejecución de prueba proporcionada por el makefile usando el siguiente comando:

    ``make exec``

    También se puede indicar al programa un archivo de texto junto con los argumentos correspondientes para generar el archivo de salida de la siguiente manera:

    ``./dist/Debug/GNU-Linux/learn {-c|-a} [-t|-b] [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt ...``

    Cuyos parámetros son:

    - ``-c|-a``: especifica la operación a realizar, ya sea crear un archivo de idioma (-c) o añadir a un archivo de idioma existente (-a).
    - ``-l nombreIdioma``: define el idioma (por defecto, "unknown").
    - ``-f ficheroSalida``: indica el nombre del archivo de salida (por defecto, "salida.bgx").
    - ``texto1.txt texto2.txt ...``: referencia a los archivos de entrada (se requiere al menos uno).

Finalmente, es importante recordar que se puede hacer uso de los siguientes comandos:

- ``make clean``: limpia los archivos creados.
- ``make zip``: genera un archivo ``.zip`` del programa.
- ``make testv``: comprueba los errores del programa utilizando **Valgrind**.
