/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef _SALA_
#define _SALA_

#include "Inventari.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <vector>
#include <string>
#endif
using namespace std;


 /** @class Sala
     @brief Representa una sala
*/

class Sala {

    // Descripción: Contiene la estructura de sala y la funciones asociadas.



private:
 
    int f, c, num_prod;
    map<string, int> inventari_sala;
    typedef vector<string> row;
    typedef vector<row> estant;
    estant estanteria;



public:

    // Constructora
    
    /** @brief Creadora por defecto
        \pre Cierto
        \post El resultado es una sala vacía
    */    
    Sala();

    Sala(const int &fil, const int &col);
    

    // Consultoras


    
    /** @brief Consultora de is la sala está vacía
        \pre La sala existe
        \post Devuelve cierto si está vacía
    */ 
    bool es_vacia();

    /** @brief Consultora del producto en una posición
        \pre La sala, la fila y la columna son válidas
        \post Devuelve el producto en dicha posición
    */
    string consultar_pos(const int &fil, const int &col);



    // Modificadoras


    /** @brief Modificadora que añade una cantidad de un producto a la sala
        \pre La sala y el producto existen
        \post El resultado es la sala con la cantidad del producto añadida, se devuelve la cantidad que no ha cabido
    */
    int poner_items(const string &id, int n);

    /** @brief Modificadora que quita una cantidad de un producto a la sala
        \pre La sala y el producto existen
        \post El resultado es la sala con la cantidad de un producto quitada, se devuelve la cantidad que no se ha podido quitar
    */
    int quitar_items(const string &id, int n);

        /** @brief Modificadora que reorganiza la estantería de una sala
        \pre La sala existe
        \post El resultado es la sala con la estantería reorganizada
    */    
    void reorg();

        /** @brief Modificadora que redimensiona una sala
        \pre Se introduce un numero de sala válido y el nuevo tamaño de la estantería.
        \post Si los productos no caben en la nueva estantería se produce un error, en caso contrarío se cambia el tamaño de la estantería y se compacta
    */

    void redim(const int &fil, const int &col);

        /** @brief Modificadora que compacta la estantería de una sala
        \pre La sala existe
        \post El resultado es la sala con la estantería compactada, todos los productos juntos
    */
    void compact();


    
    
    // Entrada / Salida
    
    /** @brief Operación escriutra
        \pre La sala existe
        \post Se escriben los productos de la sala
    */    
    void escribir();


};
#endif
