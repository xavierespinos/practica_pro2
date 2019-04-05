/** @file Inventari.hh
    @brief Especificación de la clase inventari
*/

#ifndef _INVENTARI_
#define _INVENTARI_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;


 /** @class producto
  *  @brief Representa un producto
*/

class Inventari {

	// Descripción: Contiene la estructura producto y sus funciones asociadas.


private:

	map<string, int> inventari;


public:

	// Constructora

	/** @brief Creadora por defecto
		\pre Cierto
		\post El resultado es un producto sin identificador y con cantidad 0
	*/
	Inventari();

	// Consultoras

    /** @brief Consultora de la existencia de un producto
        \pre El producto existe
        \post Devuelve cierto si existe
    */
	bool producto_existe(const string &s);

    /** @brief Consultora de la cantidad de un producto
        \pre El producto existe
        \post Devuelve la cantidad del producto
    */
	void cantidad(const string &s);

	// Modificadoras

    /** @brief Modificadora del identificador de un producto
        \pre El producto existe
        \post Añade un identificador a un producto
    */
	void anadir_prod(const string &s);

    /** @brief Modificadora que elimina un producto
        \pre El producto existe
        \post Quita un producto
    */
	void quitar_prod(const string &s);

    /** @brief Modificadora que aumenta la cantidad de un producto.
     *  \pre
     *  \post 
    */

    void anadir_cantidad(const string &id, const int &n);

    /** @brief Modificadora que disminuye la cantidad de un producto.
     *  \pre
     *  \post 
    */

    void quitar_cantidad(const string &id, const int &n);

    // Entrada/Salida

	    /** @brief Operación escriutra del inventario del almacen
        \pre Cierto
        \post Se escriben los productos del almacen
    */  

    void escriure_inventari();
    

};
#endif




