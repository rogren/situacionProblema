/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Streaming
*/
#ifndef STREAMING_H
#define STREAMING_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Peliculas.h"
#include "Episodio.h"
#include "Series.h"
using namespace std;


class Streaming{
        private:
            vector<Peliculas*> peliculas; // Vector para almacenar las películas
            vector<Episodio*> episodios; // Vector para almacenar los episodios
            vector<Series*> series;     // vector para almacenar series 
            vector<string> separar(string linea);   // funcion que separa linea en elementos individuales (tokens)
        public:
            Streaming();    // constructor de clase 
            bool CargaExcel(const string& archivo); // funcion que carga datos desde un archivo de excel
            void mPeliculas();      // funcion que muestra todas las peliculas 
            void mSeries() ;        // funcion que muestra todas las series
            bool mostrarCalifPel(float valor) const;    //funcion que filtra peliculas por calificacion
            bool mostrarCalifVid(float valor) const;    //funcion que filtra TODOS los videos (peliculas y episodios de serie) por calificacion
            bool filtrarSerie(const string& nombreSerie) const; //funcion donde tecleas una serie y aparecen los episodios
            void calificacionV();                           //funcion que permite asignar una nueva calificacion a un video
            float promedioCalificacion(const string& nombreSerie) const;    //funcion que obtiene promedio de calificacion de todos los episodios de una serie
            void filtrarGenero(string& genero);             //funcion para filtrar peliculas por genero
};
#endif
