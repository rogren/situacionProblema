/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define header clase Video
*/
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
using namespace std;

class Video{
    private:
        string iD;
        string nombre;
        string genero;
        int calificacion;
        float duracion;
        int fechaEstreno;

    public:
        Video(string iD1, string nombre1, string genero1, int calificacion1,
        float duracion1, int fechaEstreno1 );
};

#endif