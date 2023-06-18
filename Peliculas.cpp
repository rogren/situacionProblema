/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructores clase Peliculas
*/

#include "Video.h" //inclusion clase base
#include "Peliculas.h"
#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

// declaracion constructor
Peliculas::Peliculas(string iD1, string nombre1, int duracion1, string genero1,
                     float calificacion1, string fechaEstreno1) : Video(iD1, nombre1,
                                                                        duracion1, genero1, calificacion1, fechaEstreno1)
{}
void Peliculas::setCalificacion(float calificacionNueva) // setter para actualizar califiacion de una pelicula
{
        Video::setCalificacion(calificacionNueva);      // llamado a metodo setter de clase base
}

// Sobrecarga del operador <<
ostream& operator<<(ostream& os, const Peliculas& pelicula) {
    os << "========================================================================" << endl;
    os << "ID: " << pelicula.getID() << " Nombre: " << pelicula.getNombre() << endl;
    os << "========================================================================" << endl;
    os << "Genero: " << pelicula.getGenero() << endl;
    os << "Calificacion: " << pelicula.getCalificacion() << endl;
    os << "Fecha de Estreno: " << pelicula.getFechaEstreno() << endl;
    os << endl;

    return os;
}