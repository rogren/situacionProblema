/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Peliculas
*/

#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>
#include <string>
#include "Video.h" //Incluir clase base
using namespace std;

class Peliculas : public Video
{ // constructor derivado de clase base
public:
    Peliculas(string iD1, string nombre1, int duracion1, string genero1,
              float calificacion1, string fechaEstreno1);
    void setCalificacion(float calificacionNueva); // delcaracion de funcion virtual pura declarada en clase base
    friend ostream &operator<<(ostream &os, const Peliculas &pelicula); // Sobrecarga del operador <<

};

#endif
