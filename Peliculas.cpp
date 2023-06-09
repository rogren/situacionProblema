/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructores clase Peliculas
*/

#include "Video.h"
#include "Peliculas.h"
#include <iostream>
#include <string>
using namespace std;

Peliculas::Peliculas(string iD1, string nombre1, string genero1, int calificacion1,
        float duracion1, int fechaEstreno1 ): Video( iD1, nombre1, 
        genero1, calificacion1, duracion1, fechaEstreno1 )
{

}