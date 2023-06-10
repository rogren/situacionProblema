/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructor clase Episodio
*/
#include "Episodio.h"
#include <iostream>
#include <string>
using namespace std;

Episodio::Episodio(string iD1, string nombre1, string genero1, int calificacion1, float duracion1,
                   int fechaEstreno1, int temporada1, int numEpisodio1) : Video(iD1, nombre1,
                    genero1, calificacion1, duracion1, fechaEstreno1){
    temporada = temporada1;
    numEpisodio = numEpisodio1;
}

