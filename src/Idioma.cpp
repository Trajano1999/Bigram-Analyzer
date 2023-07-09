/** 
 * @file Idioma.cpp
 * @author DECSAI
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include "Idioma.h"

using namespace std;

void Idioma::reservarMemoria(int n){
    if(_conjunto != 0){
        delete [] _conjunto;
        _conjunto = 0;
    }

    _conjunto = new Bigrama [n];
    _nBigramas = n;
}   

void Idioma::liberarMemoria(){
    delete [] _conjunto;
    _conjunto = 0;
    _nBigramas = 0;
}

void Idioma::copiar(const Idioma& otro){                                       
    _idioma = otro._idioma;
    _nBigramas = otro._nBigramas;
    _conjunto = new Bigrama[otro._nBigramas];
    for(int i=0; i<otro._nBigramas; i++)    
        _conjunto[i] = otro.getPosicion(i);
}

Idioma::Idioma(){
    _idioma = ' ';
    _conjunto = 0;
    _nBigramas = 0;
}

Idioma::Idioma(int nbg){
    _idioma = ' ';
    _conjunto = 0;
    _nBigramas = nbg;
}

Idioma::Idioma(const Idioma& orig){
    copiar(orig);
}

Idioma::~Idioma(){
    liberarMemoria();
}

Idioma& Idioma::operator=(const Idioma& orig){
    copiar(orig);
}

std::string Idioma::getIdioma() const{
    return _idioma;
}

void Idioma::setIdioma(const std::string& id){
    _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const{
    if(p >= 0 && p < _nBigramas)
        return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama & bg){
    ampliarMemoria(1);
    
    for(int i=_nBigramas-2; i>p; i--)
        _conjunto[i+1]=_conjunto[i];
    
    _conjunto[p] = bg;
}

int Idioma::getSize() const{
    return _nBigramas;
}

void Idioma::ampliarMemoria(int n){
    Bigrama *aux=new Bigrama [_nBigramas + n];

    for(int i=0; i<_nBigramas && i<_nBigramas + n; i++)
        aux[i] = _conjunto[i];

    delete [] _conjunto;
    _conjunto = aux;    
    _nBigramas = _nBigramas+n;
    aux = 0;
}

int Idioma::findBigrama(const std::string& bg) const{
    int numero=-1;
    
    for(int i=0; i<_nBigramas && numero==-1; i++)
        if( strcmp( _conjunto[i].getBigrama(),bg.c_str() ) == 0 )
            numero = i;
        
    return numero;
}

//double distancia(const Idioma& otro) const;

void Idioma::ordenar(){
    Bigrama aux;
    
    for(int i=0; i<_nBigramas-1; i++)
        for(int j=i+1; j<_nBigramas; j++)
            if(_conjunto[i].getFrecuencia() < _conjunto[j].getFrecuencia()){
                aux = _conjunto[i];
                _conjunto[i] = _conjunto[j];
                _conjunto[j] = aux;
            }
}

bool Idioma::salvarAFichero(const char *fichero) const{
    bool salvado;
    
    ofstream fsalida;
    fsalida.open(fichero);
    
    salvado = fsalida;
    if(salvado){
        fsalida << *this;
        salvado = fsalida;
        if(!salvado)
            cerr << "Error al grabar el fichero " << fichero << endl;
    }else
        cerr << "Error al abrir el fichero " << fichero << endl;
    
    fsalida.close();
    return salvado;
}

bool Idioma::cargarDeFichero(const char *fichero){
    bool cargado;
    
    ifstream lectura;
    lectura.open(fichero);
    
    cargado = lectura;
    if(cargado){
        lectura >> *this;
        cargado = lectura;
        if(!cargado)
            cerr << "Error al grabar el fichero " << fichero << endl;
    }else
        cerr << "Error al abrir el fichero " << fichero << endl;
    
    lectura.close();
    return cargado;
}

std::ostream & operator<<(std::ostream & os, const Idioma & i){
    os << "MP-BIGRAMAS_IDIOMA-T-1.0" << endl;
    os << i._idioma << endl << i._nBigramas << endl;
    
    for(int j=0; j<i._nBigramas; j++)
        os << i._conjunto[j] << endl;
    
    return os;
}

std::istream & operator>>(std::istream & is, Idioma & i){
    string primera;
    is >> primera;
    
    if(primera == "MP-BIGRAMAS_IDIOMA-T-1.0"){
        is >> i._idioma >> i._nBigramas;
        i.reservarMemoria(i._nBigramas);
        for(int j=0; j<i._nBigramas; j++)
            is >> i._conjunto[j];
    }
    return is;
}