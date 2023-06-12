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
        string iDepisodio;
        string nombreEpisodio;

    public:
        Episodio(string iD1, string nombre1, int duracion1, string genero1,
                 float calificacion1, string fechaEstreno1,  string iDepisodio1, string nombreEpisodio1,
                 int temporada1, int numEpisodio1);
        
        void mostrarDatos() const;
        int getTemporada() const;
        int getNumEpisodio() const;
        string getIdEp() const;
        string getNombreEpisodio() const;
};

#endif
