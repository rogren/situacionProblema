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
    string iDSer; // ID de Serie
    string nombreSerie; // nombre de serie
    string genero;  // genero de serie
    vector<Episodio *> episodios; // vector de punteros para almacenar episodios

public:
    Series(string iDSer1, string nombreSerie1, string genero1);
    // getters para obtener variables
    string getiDSer() const;
    string getNombreSerie() const;
    string getGeneroSerie();
    
    void agregarEp(Episodio* episodio); //  funcion para agregar episodios a una serie
    vector<Episodio*>&getEpisodios();   // getter para acceder al vector de episoios

};
#endif