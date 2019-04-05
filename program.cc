#include "Almacen.hh"
#include "Sala.hh"
#include "Inventari.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;


int main()
{
    
    int n;       //numero de sales
    cin >> n;
    Almacen m(n);
    m.llegir();
    m.afegir_sales(n);
    string op;   //codig operacio
    Inventari Inventari; 
    while (cin >> op and op != "fin"){
        
        if (op == "poner_prod"){

            string id;
            cin >> id;
            cout << "poner_prod " << id << endl;
            Inventari.anadir_prod(id);



        }
        
        if (op == "quitar_prod"){

            string id;
            cin >> id;
            cout << "quitar_prod " << id << endl;
            Inventari.quitar_prod(id);

 

        }
        
        if (op == "poner_items"){


            string id;
            int sa, q, res;

            cin >> sa >> id >> q; 
            cout << "poner_items " << sa << " " << id << " " << q << endl;

            if (not Inventari.producto_existe(id)) cout << "  error" << endl;
            else {res = m.poner_items(sa, id, q);
                Inventari.anadir_cantidad(id, q-res);
                cout << "  " << res << endl;
            }
        }
        
        if (op == "quitar_items"){

            string id;
            int q, sala, res;

            cin >> sala >> id >> q; 
            cout << "quitar_items " << sala << " " << id << " " << q << endl;
            res = m.quitar_items(sala, id, q);
            if (not Inventari.producto_existe(id)) cout << "  error" << endl;
            else {
                
                Inventari.quitar_cantidad(id, q-res);
                cout << "  " << res << endl;
            }

        }
        
        if (op == "distribuir"){


            string id;
            int n, res;

            cin >> id >> n;

            cout << "distribuir " << id << " " << n << endl;


            if (not Inventari.producto_existe(id)) cout << "  error" << endl;
            else {
                res = m.distribuir(id, n);
                cout << "  " << res << endl;
                Inventari.anadir_cantidad(id, n-res);
            }


        }
        
        if (op == "compactar"){


            int n;
            cin >> n;
            m.compactar(n);

            cout << "compactar " << n << endl;

        }
        
        if (op == "reorganizar"){

            int n;
            cin >> n;
            m.reorganizar(n);

            cout << "reorganizar " << n << endl;

        }
        
        if (op == "redimensionar"){

            int n, f, c;
            cin >> n >> f >> c;
            cout << "redimensionar " << n << " " << f << " " << c << endl;
            m.redimensionar(n, f, c);

             

        }
        
        if (op == "inventario"){

            cout << "inventario" << endl;
            Inventari.escriure_inventari();

        }
        
        if (op == "escribir"){

            int sala;
            cin >> sala;

            cout << "escribir " << sala << endl;
            m.escribir_sala(sala);

        }
        
        if (op == "consultar_pos"){

            int sala, f, c;

            cin >> sala >> f >> c;


            cout << "consultar_pos " << sala << " " << f << " " << c << endl;
            cout << "  " << m.consultar_posicion(sala, f, c) << endl;


        }
        
        else if (op == "consultar_prod"){

            string id;
            cin >> id;
            
            cout << "consultar_prod " << id << endl;

            Inventari.cantidad(id);


        }
        
    }

    cout << "fin" << endl;

    
}

