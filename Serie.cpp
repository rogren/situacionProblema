/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructores clase Serie
*/

#include <iostream>
#include <string>
#include "Serie.h"

using namespace std;


Serie::Serie(string nombre1)
{
    nombreSer = nombre1;
}

void Serie::agregarEpisodio(const Episodio& episodio){
    episodios.push_back(episodio);
}