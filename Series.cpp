#include "Series.h"
#include <iostream>
using namespace std;


Series::Series(string iDSer1, string nombreSerie1, string genero1)
{
    // Asignar valores a variables 
    iDSer = iDSer1;
    nombreSerie = nombreSerie1;
    genero = genero1;
}

// getters para obtener ID de serie, nombre, genero
string Series::getiDSer() const
{
    return iDSer;
}
string Series::getNombreSerie() const
{
    return nombreSerie;
}
string Series::getGeneroSerie()
{
    return genero;
}

// Funcion que agrega episodios a serie 
void Series::agregarEp(Episodio *episodio)
{
    episodios.push_back(episodio);  // agregar puntero al vector de episodios
}

vector<Episodio *> &Series::getEpisodios()
{
    return episodios; // devuelve una referencia que se puede manipular sin necesidad de realizar una copia del vector 
}
