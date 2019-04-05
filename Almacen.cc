#include "Almacen.hh"



Almacen::Almacen(const int &n){

    salas = n;

}

void Almacen::afegir_sales(const int &n){

    int i = 0;
    int f, c;

    while(i < n){

        cin >> f >> c;
        Sala s(f, c);
        almacen.push_back(s);
        ++i;
    }
}

int Almacen::poner_items(const int &s, const string &id, const int &n){

 
    return almacen[s-1].poner_items(id, n);

}

int Almacen::quitar_items(const int &s, const string &id, const int &n){

    return almacen[s-1].quitar_items(id, n);

}

int Almacen::distribuir(const string &s, int n){

    return distribuir_magatzem(dist_almacen, s, n);

}

int Almacen::distribuir_magatzem(BinTree<int> &a, const string &s, int n){

    int items = almacen[a.value() -1].poner_items(s, n);

    if (items == 0) return 0;


    else {

        if (not a.left().empty()){

            int items_e;
            int items_d;
            
            BinTree<int> sala_d = a.right();
            BinTree<int> sala_e = a.left();

            if (items == 1){

                items_e = distribuir_magatzem(sala_e, s, 1);
                items_d = 0;

            }

            else if (items%2 == 0){

                items_d = distribuir_magatzem(sala_d, s, items/2);
                items_e = distribuir_magatzem(sala_e, s, items/2);

            }   

            else{
                
                items_e = distribuir_magatzem(sala_e, s, items/2 +1);
                items_d = distribuir_magatzem(sala_d, s, items/2);

            }
            

            items = items_d + items_e;

        }

        return items;

    }

}

void Almacen::redimensionar(const int &s, int f, int c){

    almacen[s-1].redim(f, c);

}

void Almacen::compactar(const int &s){

    almacen[s-1].compact();

}

void Almacen::reorganizar(const int &s){

    almacen[s-1].reorg();

}

string Almacen::consultar_posicion(const int &s, const int &f, const int &c){

    return almacen[s-1].consultar_pos(f, c);
}

void Almacen::llegir(){

    llegir_magatzem(dist_almacen, 0);

}

void Almacen::llegir_magatzem(BinTree<int>& a, const int &marca){

    int x;
    cin >> x;
    if (x!=marca){
	    BinTree<int> l;
	    llegir_magatzem(l,marca);
	    BinTree<int> r;
	    llegir_magatzem(r,marca);
	    a=BinTree<int>(x,l,r);
  }

}


void Almacen::escribir_sala(const int &s){

    almacen[s-1].escribir();

}