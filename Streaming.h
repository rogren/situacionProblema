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
            vector<Series*> series;
            vector<string> separar(string linea);
        public:
            Streaming();
            bool CargaExcel(const string& archivo);
            //void mEpisodios();
            void mPeliculas();
            void mSeries() ;
            
};
#endif
