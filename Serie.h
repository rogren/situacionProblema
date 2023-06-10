/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Video
*/
#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include <string>
#include <vector>
#include "Episodio.h"
using namespace std;

class Serie {
    private:
        string nombreSer;
        vector<Episodio> episodios;
    public:
        Serie(string nombre1);
        void agregarEpisodio(const Episodio& episodio);

};
#endif