/** 
 * @file ContadorBigramas.cpp
 * @author Juan Manuel Mateos Pérez
*/
#include <iostream>
#include <fstream>
#include <cctype>
#include "ContadorBigramas.h"
 
using namespace std;

void ContadorBigramas::reservarMemoria(int n){
    _bigramas = new int*[n];
    
    for(int i=0; i<n; i++){
        _bigramas[i] = new int[n];
        for(int j=0; j<n; j++)
            _bigramas[i][j] = 0;
    }
}

void ContadorBigramas::liberarMemoria(){
    for(int i=0; i<getSize();i++)
        delete [] _bigramas[i];
            
    delete [] _bigramas;
    _bigramas = 0;
}

void ContadorBigramas::copiar(const ContadorBigramas & otro){
    reservarMemoria(otro.getSize());
    for(int i=0; i<otro.getSize(); i++)
        for(int j=0; j<otro.getSize(); j++)
            _bigramas[i][j] = otro._bigramas[i][j]; 
}

ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos){
    _caracteresValidos = caracteresValidos;
    reservarMemoria(getSize());
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig){
    copiar(orig);
}

ContadorBigramas::~ContadorBigramas(){
    liberarMemoria();
}

int ContadorBigramas::getSize() const{
    return _caracteresValidos.size();
}

int ContadorBigramas::getBigramasActivos() const{
    int aux=0;
    
    for(int i=0; i<getSize(); i++)
        for(int j=0; j<getSize(); j++)
            if(_bigramas[i][j] > 0)
                aux++;
    return aux;
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia){
    bool addbigrama = false;
    int pos_i = -1, pos_j = -1;
    
    for(int i=0; i<getSize() && pos_i == -1; i++)
        if(cadena[0] == _caracteresValidos[i])
            pos_i = i;
    
    for(int i=0; i<getSize() && pos_j == -1; i++)
        if(cadena[1] == _caracteresValidos[i])
            pos_j = i;
    
    if(pos_i != -1 && pos_j != -1) {
        addbigrama = true;
        _bigramas[pos_i][pos_j] += frecuencia;
    }
    
    return addbigrama;
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig){
    copiar(orig);
    return *this;
}

ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas& rhs){
    for(int i=0; i<getSize(); i++)
        for(int j=0; j<getSize(); j++)
            _bigramas[i][j] += rhs._bigramas[i][j];
}

void ContadorBigramas::ExtraerBigramas(string& palabra){
    char bigrama[3];
    bigrama[2] = '\0';
    
    for(int i=0; i<palabra.size(); i++)
        if(isupper(palabra[i]))
            palabra[i] = tolower(palabra[i]);
    
    for(int i=0; i<palabra.size()-1; i++){
        bigrama[0] = palabra[i];
        bigrama[1] = palabra[i+1];
        addBigrama(bigrama);
    }
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero){
    bool contador;
    string palabrita;
    
    ifstream lectura;
    lectura.open(nfichero);
    
    contador = lectura;
    if(contador){
        while(lectura >> palabrita){
            ExtraerBigramas(palabrita);
        }
    }else{
        cerr << "Error al abrir el fichero " << nfichero << endl;
    }
        
    lectura.close();
    return contador;
}

Idioma ContadorBigramas::toIdioma() const{
    Idioma idiomita;
    int  cont=0;
    Bigrama bigramita;
    char cadena[2];
    
    for(int i=0; i<_caracteresValidos.size(); i++){
        for(int j=0; j<_caracteresValidos.size(); j++){
            if(_bigramas[i][j] > 0){
                bigramita.setFrecuencia(_bigramas[i][j]);

                cadena[0] = _caracteresValidos[i];
                cadena[1] = _caracteresValidos[j];
                bigramita.setBigrama(cadena);

                idiomita.setPosicion(cont,bigramita);
                cont++; 
            }
        }
    }
    
    idiomita.ordenar();
    return idiomita;
}

void ContadorBigramas::fromIdioma(const Idioma &id){
    liberarMemoria();
    reservarMemoria(_caracteresValidos.size());
    char letra1, letra2;
    int pos_f, pos_c;
    
    for(int i=0; i<id.getSize(); i++){
        pos_f = pos_c = -1;
        
        letra1 = id.getPosicion(i).getBigrama()[0];
        letra2 = id.getPosicion(i).getBigrama()[1];
        
        for(int j=0; j<_caracteresValidos.size() && pos_f==-1; j++)
            if(_caracteresValidos[j] == letra1)
                pos_f = j;
          
        if (pos_f != -1){
            for(int j=0; j<_caracteresValidos.size() && pos_c==-1; j++)
                if(_caracteresValidos[j] == letra2)
                    pos_c = j;
            
            if(pos_c != -1)
                _bigramas[pos_f][pos_c] = id.getPosicion(i).getFrecuencia();
        }
    }
}