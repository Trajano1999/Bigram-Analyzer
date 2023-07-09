/**
 * @file Bigrama.h
 * @author DECSAI
 */

#ifndef BIGRAMA_H
#define BIGRAMA_H

/**
 * @class Bigrama
 * @brief Gestión individual de bigramas: pares de letras consecutivas de un texto y su frecuencia asociada dentro del texto   
 */
class Bigrama{
    private:
        char _bigrama[3]; /// Bigrama almacenado, incluyendo el '\0'. Ojo a desbordamientos
        int _frecuencia; /// Frecuencia almacenada
        
    public:
        /// @brief Constructor base
        Bigrama();

        /**
         * @brief Devuelve el bigrama almacenado
         * @return el bigrama
         */
        const char* getBigrama() const;

        /**
         * @brief Devuelve la frecuencia almacenada
         * @return la frecuencia
         */
        int getFrecuencia() const;

        /**
         * @brief Actualiza el bigrama, siempre que sea de la longitud adecuada, 
         *  en otro caso, no se actualiza, para evitar desbordamientos del vector
         * @param cadena El nuevo valor del bigrama
         */
        void setBigrama(const char cadena[]);

        /**
         * @brief Actualiza la frecuencia almacenada
         * @param frec La nueva frecuencia
         */
        void setFrecuencia(int frec);
        
        friend std::ostream & operator<<(std::ostream & os, const Bigrama & bigramita);
        friend std::istream & operator>>(std::istream & is, Bigrama & bigramita);
};

/**
 * @brief Ordena un vector de bigramas de forma ascendente por frecuencias
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void ordenaAscFrec(Bigrama *v, int n);

/*
 * @brief Compara si dos bigramas e indica cual es el menor.
 * @param b1 Primer bigrama a comparar
 * @param b2 Segundo bigrama a comparar
 * @return Devuelve true si el primer bigrama es menor, false en caso contrario
 */
bool ComparaAscBigr(const Bigrama& b1, const Bigrama& b2);

/**
 * @brief Ordena un vector de bigramas de forma ascendente por bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void ordenaAscBigr(Bigrama *v, int n);

/**
 * @brief Imprime un vector de bigramas
 * @param v El vector de bigramas
 * @param n Tamaño de @a v
 */
void imprimeBigramas(const Bigrama *v, int n);

/**
 * @brief Suma dos listas de bigramas y devuelve el resultado
 * @param v1 Primer vector de bigramas
 * @param nv1 Tamaño de @a v1
 * @param v2 Segundo vector de bigramas
 * @param nv2 Tamaño de @a v2
 * @param res Vector resultado creado en memoria dinámica
 * @param nres Tamaño de @a res
 * @pre @a v1 y @a v2 deben tener el mismo tamaño y los mismos bigramas aunque las frecuencias sean distintas
 */
void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *&res, int & nres);

/**
 * @brief Serialización de un bigrama para su inserción en un flujo de salida
 * @param os Flujo de salida
 * @param bigramita: Bigrama a serializar
 * @return El mismo flujo de salida para inserciones consecutivas
 */
std::ostream & operator<<(std::ostream & os, const Bigrama & bigramita);

/**
 * @brief Reconstruye un Bigrama a partir de una serialización
 * @param is Flujo de entrada desde el que se extrae la serialización
 * @param bigramita Bigrama reconstruido
 * @return El mismo flujo de entrada para extracciones consecutivas
 */
std::istream & operator>>(std::istream & is, Bigrama & bigramita);

#endif /* BIGRAMA_H */
