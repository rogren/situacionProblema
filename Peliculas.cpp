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

void Peliculas::mostrarDatos() const
{
        cout << "========================================================================" << endl;
        cout << "ID: " << getID(); //obtener ID
        cout << " Nombre: " << getNombre() << endl; //obtener nombre
        cout << "========================================================================" << endl;
        cout << "Genero: " << getGenero() << endl; //obtener genero
        cout << "Calificacion: " << getCalificacion() << endl; //obtener calificacion
        cout << "Fecha de Estreno: " << getFechaEstreno() << endl;// obtener fecha de estreno
        cout << endl;
}

void Peliculas::setCalificacion(float calificacionNueva) // setter para actualizar califiacion de una pelicula
{
        Video::setCalificacion(calificacionNueva);      // llamado a metodo setter de clase base
}