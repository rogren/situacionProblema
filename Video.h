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
    private:            // atributos de un Video
        string iD;  // ID
        string nombre; // nombre
        string genero; // genero
        float calificacion; // calificacion
        int duracion; // duracion
        string fechaEstreno; //fecha de estreno

    public:
        Video(string iD1, string nombre1, int duracion1, string genero1,
                 float calificacion1, string fechaEstreno1);

        virtual void setCalificacion(float calificacionNueva) = 0;  // funcion virtual pura para asignar calificacion a un video
        // Getters para obtener informacion con metodo de acceso privado
        string getID() const;
        string getNombre() const;
        string getGenero() const;
        float getCalificacion() const;
        int getDuracion() const;
        string getFechaEstreno() const;
};
#endif
