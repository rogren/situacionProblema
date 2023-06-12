#include "Series.h"

Series::Series(string iDSer1, string nombreSerie1, string genero1)
{
    iDSer = iDSer1;
    nombreSerie = nombreSerie1;
    genero = genero1;
}

string Series::getiDSer() const
{
    return iDSer;
}
string Series::getNombreSerie() const
{
    return nombreSerie;
}

void Series::agregarEp(Episodio *episodio)
{
    episodios.push_back(episodio);
}

/*
void Series::mostrarDatos() const
{
    cout << "ID: " << iDSer << endl;
    cout << "Nombre: " << nombreSerie << endl;
    cout << "Episodios: " << endl;

    for (Episodio *episodio : episodios)
    {
        episodio->mostrarDatos();
    }
}
*/

vector<Episodio *> &Series::getEpisodios()
{
    return episodios;
}
