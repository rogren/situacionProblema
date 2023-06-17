/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructores clase Video
*/

#include "Video.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Video::Video(string iD1, string nombre1, int duracion1, string genero1,
             float calificacion1, string fechaEstreno1)
{
    // Asignar valores a variables
    iD = iD1;
    nombre = nombre1;
    genero = genero1;
    calificacion = calificacion1;
    duracion = duracion1;
    fechaEstreno = fechaEstreno1;
}

void Video::mostrarDatos() const
{
    // funcion virtual pura vacia, la implementacion se realiza en las clases derivadas Peliculas y Episodios
}
void Video::setCalificacion(float calificacionNueva) 
{
    int calMAX = 7; //valor maximo que se puede dar de calificacion
    if (calificacionNueva >= 0 && calificacionNueva <= calMAX)  // revisar si el valor dado esta dentro del limite que pone calMAX
    {
        calificacion = calificacionNueva; //actualiza la calificacion
    }
    else
    {
        cout << endl
             << "Error: La calificacion debe estar en el rango de 0 a 7." << endl; // si el valor no esta dentro del rango del calMAX arroja un mensaje de error
    }
}
string Video::getID() const
{
    return iD;
}

string Video::getNombre() const
{
    return nombre;
}

string Video::getGenero() const
{
    return genero;
}

float Video::getCalificacion() const
{
    return calificacion;
}

int Video::getDuracion() const
{
    return duracion;
}

string Video::getFechaEstreno() const
{
    return fechaEstreno;
}
