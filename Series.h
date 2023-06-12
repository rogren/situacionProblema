/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Series
*/
#ifndef SERIES_H
#define SERIES_H

#include <iostream>
#include <string>
#include <vector>
#include "Episodio.h"
using namespace std;

class Series
{
private:
    string iDSer;
    string nombreSerie;
    string genero;
    vector<Episodio *> episodios;

public:
    Series(string iDSer1, string nombreSerie1, string genero1);

    string getiDSer() const;
    string getNombreSerie() const;
    string getGeneroSerie() const;
    void agregarEp(Episodio* episodio);
    vector<Episodio*>&getEpisodios();

};
#endif