#include "Series.h"

Series::Series(string iDSer1, string nombreSerie1, string genero1)
{
    iDSer = iDSer1;
    nombreSerie = nombreSerie1;
    genero = genero1;
}

string Series::getiDSer() const {
    return iDSer;
}
string Series::getNombreSerie() const {
    return nombreSerie;
}
string Series::getGenero() const {
    return genero;
}

void Series::mEpisodios(Episodio* episodio) {
    episodios.push_back(episodio);
    cout << "Episodios: " << nombreSerie << endl;
    for (Episodio* ep : episodios) {
        cout << "ID de episodio " << ep->getIdEp() << " Nombre " << ep->getNombreEpisodio() << endl;
    }
}

vector<Episodio*> Series::getEpisodios() const {
    return episodios;
}

    
