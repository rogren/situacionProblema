/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Episodio
*/
#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

class Episodio : public Video {
    private:
        int temporada;
        int numEpisodio;

    public:
        Episodio(string iD1, string nombre1, string genero1, int calificacion1,
             float duracion1, int fechaEstreno1, int temporada1, int numeroEpisodio1);
        int getTemporada() const;
        int getNumEpisodio() const;
};

#endif
