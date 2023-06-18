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
                   float calificacion1, string fechaEstreno1, string iDepisodio1, string nombreEpisodio1,
                   int temporada1, int numEpisodio1) : Video(iD1, nombre1,
                                                             duracion1, genero1, calificacion1, fechaEstreno1)
{
    // asignar valores a variables
    temporada = temporada1;
    numEpisodio = numEpisodio1;
    iDepisodio = iDepisodio1;
    nombreEpisodio = nombreEpisodio1;
}
//sobrecarga operador <<
ostream &operator<<(ostream &os, const Episodio &episodio)
{
    os << "ID de Episodio: " << episodio.getIdEp() << endl;
    os << "Episodio: " << episodio.getNombreEpisodio() << endl;
    os << "Temporada: " << episodio.getTemporada() << endl;
    os << "Episodio: " << episodio.getNumEpisodio() << endl;
    os << "Calificacion: " << episodio.getCalificacion() << endl;
    os << "Genero: " << episodio.getGenero() << endl;
    os << endl;

    return os;
}

void Episodio::setCalificacion(float calificacionNueva)
{
    Video::setCalificacion(calificacionNueva); // llamada a la funcion de la clase base Video setCalificacion que asigna calificaciones nuevas
}

// Getters para obtener Temporada, ID de episodio, nombre de episodio, numero de episodio.
int Episodio::getTemporada() const
{
    return temporada;
}
string Episodio::getIdEp() const
{
    return iDepisodio;
}
string Episodio::getNombreEpisodio() const
{
    return nombreEpisodio;
}
int Episodio::getNumEpisodio() const
{
    return numEpisodio;
}
