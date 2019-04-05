/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/

#ifndef _ALMACEN_
#define _ALMACEN_

#include "Sala.hh"


#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#endif
using namespace std;

 /** @class Almacen
     @brief Representa un almacen
*/

class Almacen {

	// Descripció: Contiene la estructura del almacen y las operaciones asociadas.


private:

    vector<Sala> almacen;
	BinTree<int> dist_almacen;
	int salas;

	
public:


	// Constructora

	/** @brief Creadora por defecto
		\pre Cierto
		\post El resultado es un almacen vacío, con 0 salas
	*/
	Almacen(const int &n);

	// Consultores



	// Modificadores

    void afegir_sales(const int &n);

	    /** @brief Modificadora que añade una cantidad de un producto a la sala
        \pre La sala y el producto existen
        \post El resultado es la sala con la cantidad del producto añadida, se devuelve la cantidad que no ha cabido
    */
    int poner_items(const int &s, const string &id, const int &n);

	    /** @brief Modificadora que quita una cantidad de un producto a la sala
        \pre La sala y el producto existen
        \post El resultado es la sala con la cantidad de un producto quitada, se devuelve la cantidad que no se ha podido quitar
    */
    int quitar_items(const int &s, const string &id, const int &n);

	/** @brief Modificadora que distribuye el producto por el almacen
		\pre El producto existe
		\post El resultado es el almacen con la cantidad especificada del producto distribuido 
		\por las salas, se devuelve el número que indica cuantas unidades no se han podido distribuir
	*/	
	int distribuir(const string &s, int n);

    int distribuir_magatzem(BinTree<int> &a, const string &s, int n);

    /** @brief Modificadora que redimensiona una sala
        \pre Se introduce un numero de sala válido y el nuevo tamaño de la estantería.
        \post Si los productos no caben en la nueva estantería se produce un error, en caso contrarío se cambia el tamaño de la estantería y se compacta
    */
    void redimensionar(const int &s, int f, int c);
    
    /** @brief Modificadora que compacta la estantería de una sala
        \pre La sala existe
        \post El resultado es la sala con la estantería compactada, todos los productos juntos
    */
    void compactar(const int &s);
    
    /** @brief Modificadora que reorganiza la estantería de una sala
        \pre La sala existe
        \post El resultado es la sala con la estantería reorganizada
    */    
    void reorganizar(const int &s);

	    /** @brief Consultora del producto en una posición
        \pre La sala, la fila y la columna son válidas
        \post Devuelve el producto en dicha posición
    */
    string consultar_posicion(const int &s, const int &f, const int &c);

	// Entrada / Salida

	/** @brief Operación de lectura
		\pre n > 0
		\post El resultado es un almacen con n salas 
	*/	
	void llegir();


    void llegir_magatzem(BinTree<int>& a, const int &marca);


	    /** @brief Operación escriutra
        \pre La sala existe
        \post Se escriben los productos de la sala
    */    
    void escribir_sala(const int &s);


};
#endif


