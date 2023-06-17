/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Episodio
*/
#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
#include "Video.h" //incluir clase base
using namespace std;

class Episodio : public Video
{ // clase derivada de Video
private:
    // nuevos atributos propios de un episodio
    int temporada;         // numero de temporada
    int numEpisodio;       // numero de episodio
    string iDepisodio;     // ID de episodio
    string nombreEpisodio; // nombre del episodio

public:
    Episodio(string iD1, string nombre1, int duracion1, string genero1,
             float calificacion1, string fechaEstreno1, string iDepisodio1, string nombreEpisodio1,
             int temporada1, int numEpisodio1);

    void mostrarDatos() const; // funcion virtual pura de Video para mostrar datos de episodio
    // getters para acceder a variables con metodo de acceso privado
    int getTemporada() const;
    int getNumEpisodio() const;
    string getIdEp() const;
    string getNombreEpisodio() const;
    void setCalificacion(float calificacionNueva);
};

#endif
