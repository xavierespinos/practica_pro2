#include "Inventari.hh"


Inventari::Inventari(){


}

bool Inventari::producto_existe(const string &s){

    map<string, int>::const_iterator it = inventari.find(s);
    if(it == inventari.end())  return false;
    else return true;
}


void Inventari::cantidad(const string &s){

    map<string, int>::const_iterator it = inventari.find(s);
    if (it == inventari.end()) cout << "  error" << endl;
    else cout << "  " << it->second << endl;

}

void Inventari::anadir_prod(const string &s){

    map<string, int>::const_iterator it = inventari.find(s);

    if (it != inventari.end()){

        cout << "  error" << endl;

    }

    else inventari.insert(make_pair(s, 0));
    
}

void Inventari::quitar_prod(const string &s){

    map<string, int>::const_iterator it = inventari.find(s);
    if (it == inventari.end() or it->second != 0){

        cout << "  error" << endl;
        
    }
    else {

        inventari.erase(it);
    }
}

void Inventari::anadir_cantidad(const string &id, const int &n){

    map<string, int>::iterator it = inventari.find(id);
    it->second = it->second + n;

}

void Inventari::quitar_cantidad(const string &id, const int &n){
    
    map<string, int>::iterator it = inventari.find(id);
    it->second = it->second - n;

}

void Inventari::escriure_inventari(){

    map<string, int>::const_iterator it;
    for(it = inventari.begin(); it != inventari.end(); ++it){

        cout << "  " << it->first << " " << it->second << endl;
    }
    
}

