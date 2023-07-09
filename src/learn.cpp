/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "Idioma.h"
#include "ContadorBigramas.h"

using namespace std;

/**
 * @brief Imprime mensaje de ayuda
*/
void pinta_mensaje(){
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-t|-b] [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el codigo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
    cout << "-c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)" << endl;
    cout << "-l nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (salida.bgx por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}

/*
 * @brief Crea un nuevo fichero de bigramas
 * @param valid: Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
 * @param argv: vector de argumentos que recibe el main
 * @param argc: numero de argumentos que recibe el main
 * @param nombreIdioma: indica el nombre del idioma del que se aprende(unknown por defecto)
 * @param ficheroSalida: indica el nombre del fichero de salida <.bgr> (out.bgr por defecto)
 * @param posicion: primera posicion en la que hay un fichero
 */
void ficheroc(string valid, char *argv[], int argc, const char nombreIdioma[], const char ficheroSalida[], int posicion){
    Idioma idiomita;
    ContadorBigramas contadorcito(valid);
    
    for(int i=posicion; i<argc; i++)
        contadorcito.calcularFrecuenciasBigramas(argv[i]);
    
    cout << "";
    idiomita = contadorcito.toIdioma();
    idiomita.setIdioma(nombreIdioma);
    idiomita.salvarAFichero(ficheroSalida);
}

/*
 * @brief Crea un nuevo fichero de bigramas
 * @param valid: Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
 * @param argv: vector de argumentos que recibe el main
 * @param argc: numero de argumentos que recibe el main
 * @param nombreIdioma: indica el nombre del idioma del que se aprende(unknown por defecto)
 * @param ficheroSalida: indica el nombre del fichero de salida <.bgr> (out.bgr por defecto)
 * @param posicion: primera posicion en la que hay un fichero
 */
void ficheroa(string valid, char *argv[], int argc, const char nombreIdioma[], const char ficheroSalida[], int posicion){
    Idioma idiomita;
    ContadorBigramas contadorcito(valid);
    
    idiomita.cargarDeFichero(ficheroSalida);
    contadorcito.fromIdioma(idiomita);

    for(int i=posicion; i<argc; i++)
        contadorcito.calcularFrecuenciasBigramas(argv[i]);

    cout << "";
    idiomita = contadorcito.toIdioma();
    idiomita.setIdioma(nombreIdioma);
    idiomita.salvarAFichero(ficheroSalida);
}

int main(int argc, char *argv[]){
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
    
    if(argc >= 3 && (strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"-a") == 0 )){
        if(strcmp(argv[1],"-c") == 0){
            if(strcmp(argv[2],"-l") == 0){
                if(argc >= 5){
                    if(strcmp(argv[4],"-f") == 0)
                        if(argc >= 7)
                            ficheroc(valid, argv, argc, argv[3],argv[5],6);
                        else{
                            cerr << "Error en la introduccion de los parametros" << endl;
                            pinta_mensaje();
                        }
                    else
                        ficheroc(valid, argv, argc, argv[3],"out.bgr",4);
                }else{
                    cerr << "Error en la introduccion de los parametros" << endl;
                    pinta_mensaje();
                }
            }else{
                if(strcmp(argv[2],"-f") == 0){
                    if(argc >= 5)
                        ficheroc(valid, argv, argc, "unknown",argv[3],4);
                    else{
                        cerr << "Error en la introduccion de los parametros" << endl;
                        pinta_mensaje();
                    }
                }else
                    ficheroc(valid, argv, argc, "unknown", "out.bgr", 2);
                
            }
        }else{
            if(strcmp(argv[2],"-l") == 0){
                if(argc >= 5){
                    if(strcmp(argv[4],"-f") == 0){ 
                        if(argc >= 7)
                            ficheroa(valid,argv, argc,argv[3],argv[5],6);    
                        else{
                            cerr << "Error en la introduccion de los parametros" << endl;
                            pinta_mensaje();
                        }
                    }else
                        ficheroa(valid, argv,argc,argv[3],"out.bgr",4);
                  
                }else{
                    cerr << "Error en la introduccion de los parametros" << endl;
                    pinta_mensaje();
                }
            }else{
                if(strcmp(argv[2],"-f") == 0){
                    if(argc >= 5)
                        ficheroa(valid, argv,argc,"unknown",argv[3],4);
                    else{
                        cerr << "Error en la introduccion de los parametros" << endl;
                        pinta_mensaje();
                    }
                }else{
                    ficheroa(valid, argv,argc,"unknown","out.bgr",2);
                }
            }
        }        
    }else{
        cerr << "Error en la introduccion de los parametros" << endl;
        pinta_mensaje();
    }
    
    return 0; 
}