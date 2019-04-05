#include "Sala.hh"

Sala::Sala(){

    num_prod = 0;
    f = 0;
    c = 0;

}

Sala::Sala(const int &fil, const int &col){

    num_prod = 0;
    f = fil;
    c = col;
     
    estanteria = estant(f, row(c, "NULL"));

}


bool Sala::es_vacia(){

    return (num_prod == 0);

}

string Sala::consultar_pos(const int &fil, const int &col){

    return estanteria[f-fil][col-1];

}

int Sala::poner_items(const string &id, int n){

    int n_aux = n;

    bool acabat = false;

        while(not acabat){

             for (int i = 0; i < f; ++i){

                for (int j = 0; j < c; ++j){

                    if (estanteria[i][j] == "NULL"){

                        estanteria[i][j] = id;
                        --n;
                        inventari_sala[id] = inventari_sala[id] + 1;
                        ++num_prod;
                        if (n == 0) return n;
                    }
                }
            }
            acabat = true;
        }

        if (n_aux == n) inventari_sala.erase(id);

    return n;

}

int Sala::quitar_items(const string &id, int n){

    map<string, int>::iterator it = inventari_sala.find(id);

    if (it != inventari_sala.end()){

        for (int i = 0; i < f and n > 0; ++i){

            for (int j = 0; j < c and n > 0; ++j){

                if (estanteria[i][j] == id){

                    estanteria[i][j] = "NULL";
                    --n;
                    --it->second;
                    --num_prod;
                    if (it->second == 0) inventari_sala.erase(id);
                        
                }
            }
        }

    }

    return n;
   

}

void Sala::reorg(){ 

    if (num_prod != 0){
        map<string, int>::const_iterator it = inventari_sala.begin();
     
        int cant = it->second;
    

        for (int i = 0; i < f; ++i){

            for (int j = 0; j < c; ++j){

                if(it != inventari_sala.end()){
                    
                    estanteria[i][j] = it->first;
                    --cant;
                    if (cant == 0){
                        ++it;
                        if (it!= inventari_sala.end()) cant = it->second;
                    } 

                }
                else estanteria[i][j] = "NULL";
            }
        }
    }
}

void Sala::redim(const int &fil, const int &col){

    if (num_prod <= fil*col){

        estant estanteria_aux(fil, row(col, "NULL"));

        int k, t;
        k = 0;
        t = 0;
        
        for (int i = 0; i < f and k < fil; ++i){

            for (int j = 0; j < c; ++j){

                if (estanteria[i][j] != "NULL"){

                    estanteria_aux[k][t] = estanteria[i][j];
                    ++t;
                    if (t == col){

                        ++k;
                        t = 0;

                    }
                    
                }
            }
        }
        f = fil;
        c = col;
        estanteria = estanteria_aux;
    }

    else cout << "  error" << endl;

}

void Sala::compact(){

    if (num_prod < f*c){

        int i_aux = 0;
        int j_aux = 0;
        bool swap = false;

        for (int i = 0; i < f; ++i){

            for (int j = 0; j < c; ++j){

                if (estanteria[i][j] == "NULL" and not swap){

                    i_aux = i;
                    j_aux = j;
                    swap = true;

                }

                else if (estanteria[i][j] != "NULL" and not swap) ++j_aux;

                else if (estanteria[i][j] != "NULL" and swap){

                    estanteria[i_aux][j_aux] = estanteria[i][j];
                    estanteria[i][j] = "NULL";
                    ++j_aux;

                
                }
                

                if (j_aux == c){

                        j_aux = 0;
                        ++i_aux;
                }
            }
        }
    }
}


void Sala::escribir(){

    for (int i = f- 1; i >= 0; --i){
        
        cout << " ";
        for (int j = 0; j < c; ++j){ 

            cout << " " << estanteria[i][j];

        }

        cout << endl;

    }

    cout << "  " << num_prod << endl;

    map<string, int>::const_iterator it;

    for (it = inventari_sala.begin(); it != inventari_sala.end(); ++it){

        cout << "  " << it->first << " " << it->second << endl;
    }

}