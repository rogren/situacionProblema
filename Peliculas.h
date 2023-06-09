/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Peliculas
*/

#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

class Peliculas:public Video{
    public:
        Peliculas(string iD1, string nombre1, string genero1, int calificacion1,
                  float duracion1, int fechaEstreno1);
};

#endif
