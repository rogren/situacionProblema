/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructores clase Video
*/

#include "Video.h"
#include <iostream>
#include <string>
using namespace std;

Video::Video(string iD1, string nombre1, string genero1, int calificacion1,
        float duracion1, int fechaEstreno1 )
{
    iD = iD1;
    nombre = nombre1;
    genero = genero1;
    calificacion = calificacion1;
    duracion = duracion1;
    fechaEstreno = fechaEstreno1;
}