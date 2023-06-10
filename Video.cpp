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
             float calificacion1, string fechaEstreno1 )
{
    iD = iD1;
    nombre = nombre1;
    genero = genero1;
    calificacion = calificacion1;
    duracion = duracion1;
    fechaEstreno = fechaEstreno1;
}

string Video::getID() const{
    return iD;
}

string Video::getNombre() const{
    return nombre;
}

string Video::getGenero() const{
    return genero;
}

float Video::getCalificacion() const{
    return calificacion;
}

int Video::getDuracion() const{
    return duracion;
}

string Video::getFechaEstreno() const{
    return fechaEstreno;
}

