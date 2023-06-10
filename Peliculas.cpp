/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructores clase Peliculas
*/

#include "Video.h"
#include "Peliculas.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Peliculas::Peliculas(string iD1, string nombre1, int duracion1, string genero1,
                 float calificacion1, string fechaEstreno1 ): Video( iD1, nombre1, 
        duracion1, genero1, calificacion1, fechaEstreno1)
{

}


