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
        float calificacion;
        int duracion;
        string fechaEstreno;

    public:
        Video(string iD1, string nombre1, int duracion1, string genero1,
                 float calificacion1, string fechaEstreno1);

        virtual void mostrarDatos() const = 0;
        virtual void setCalificacion(float calificacionNueva) = 0;
        string getID() const;
        string getNombre() const;
        string getGenero() const;
        float getCalificacion() const;
        int getDuracion() const;
        string getFechaEstreno() const;
};
#endif
