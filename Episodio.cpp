/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructor clase Episodio
*/
#include "Episodio.h"
#include <iostream>
#include <string>
using namespace std;

Episodio::Episodio(string iD1, string nombre1, int duracion1, string genero1,
                 float calificacion1, string fechaEstreno1,  string iDepisodio1, string nombreEpisodio1,
                 int temporada1, int numEpisodio1) : Video(iD1, nombre1,
                    duracion1, genero1, calificacion1, fechaEstreno1){
    temporada = temporada1;
    numEpisodio = numEpisodio1;
    iDepisodio = iDepisodio1;
    nombreEpisodio = nombreEpisodio1;

}

int Episodio:: getTemporada() const{
    return temporada;
}
string Episodio:: getIdEp() const{
    return iDepisodio;
}
string Episodio:: getNombreEpisodio() const{
    return nombreEpisodio;
}

