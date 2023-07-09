/** 
 * @file Bigrama.cpp
 * @author DECSAI
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;

Bigrama::Bigrama(){
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char* Bigrama::getBigrama() const{
    return _bigrama;
}

int Bigrama::getFrecuencia() const{
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[]){
    int tamano = 0;
    
    for(tamano=0; cadena[tamano] != '\0'; tamano++){}
    
    if(tamano == 2){
        _bigrama[0] = cadena[0];
        _bigrama[1] = cadena[1];
        _bigrama[2] = '\0';                               
    }
}

void Bigrama::setFrecuencia(int frec){
    if(frec >= 0)
        _frecuencia=frec;
}

void ordenaAscFrec(Bigrama *v, int n){
    Bigrama aux;
    
    for(int i=0; i<n-1; i++)
        for(int j=i; j<n; j++)
            if(v[j].getFrecuencia() < v[i].getFrecuencia()){
                aux = v[i];
                v[i]=v[j];
                v[j]=aux;
            }
}

bool ComparaAscBigr(const Bigrama& b1, const Bigrama& b2){
    bool b1menor = false;
    
    if(b1.getBigrama()[0] < b2.getBigrama()[0])
        b1menor = true;
    else
        if(b1.getBigrama()[0] == b2.getBigrama()[0] && b1.getBigrama()[1] < b2.getBigrama()[1])
            b1menor = true;
    
    return b1menor;
}

void ordenaAscBigr(Bigrama *v, int n){
    Bigrama aux;
    
    for(int i=0; i<n-1; i++)
        for(int j=i; j<n; j++)
            if(!ComparaAscBigr(v[i],v[j])){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void imprimeBigramas(const Bigrama *v, int n){
    cout << "Lista de " << n << " bigramas:" << endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama() << "-" << v[i].getFrecuencia() << ", "; // << endl;
}

void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *&res, int & nres){
    for(int i=0; i<nres; i++){
        res[i].setBigrama(v1[i].getBigrama());
        for(int j=0; j<nv2; j++)
            if(res[i].getBigrama()[0] == v2[j].getBigrama()[0] && res[i].getBigrama()[1] == v2[j].getBigrama()[1]) // strcmp()
                res[i].setFrecuencia(v1[i].getFrecuencia() + v2[j].getFrecuencia());
    }
} 

std::ostream & operator<<(std::ostream & os, const Bigrama & bigramita){
    os << bigramita._bigrama << " " << bigramita._frecuencia;
    return os;
}

std::istream & operator>>(std::istream & is, Bigrama & bigramita){
    is >> bigramita._bigrama >> bigramita._frecuencia;
}