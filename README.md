# Bigram Analyzer

Práctica final de la asignatura de **Metodología de Programación**.

## Descripción

El programa se encarga de analizar el número de bigramas de un texto pasado como argumento y organizarlos en un archivo de salida para permitir su estudio y  comparación con otros ficheros de idiomas, para así detectar el idioma en el que está escrito. 

### Nota :
El programa no está terminado pues el análisis sí que lo realiza al completo, pero faltaría comparar ese análisis con los resultados de cada idioma e identificarlo con el resultado más parecido. Así, el programa daría como resultado simplemente el idioma en que un fichero está escrito.

## Compilación y Ejecución

* Para compilarlo en **Linux**, desde la carpeta en la que tenemos los archivos del repositorio, introducir en la terminal el siguiente comando :

    `make`

    este comando creará dos nuevas carpetas llamadas **build** y **data** con sus archivos correspondientes dentro. 

* Para ejecutarlo, podemos aprovechar la ejecución de prueba proporcionada por el makefile usando el siguiente comando :

    `make exec`

    Aunque las ejecuciones son mucho más variadas, pudiendole pasar al programa cualquier archivo de texto con distintos argumentos para obtener el fichero final.

    Podemos por tanto, ejecutarlo de la siguiente forma :

    `./dist/Debug/GNU-Linux/learn {-c|-a} [-t|-b] [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt ...`

    cuyos parámetros son :

        -c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)
        -l nombreIdioma: idioma (unknown por defecto)
        -f ficheroSalida:  nombre del fichero de salida (salida.bgx por defecto)
        texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)

Finalmente recordemos que podemos hacer uso de :

`make clean` : para limpiar los archivos creados.

`make zip` : para generar un archivo .zip del programa.

`make testv` : para comprobar los errores del programa usando valgrind.