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


void Series::mEpisodios() {
    cout << "Episodios: " << nombreSerie << endl;
    for (Episodio* episodio : episodios) {
        cout << "ID de episodio " << episodio->getIdEp() << " Nombre " << episodio->getNombreEpisodio() << endl;
    }
}

void Series::EpisodiosSerie(Episodio* episodio){
    episodios.push_back(episodio);
}


    
