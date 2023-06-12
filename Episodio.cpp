/*
Autor Roger Vicente Rendon Cuevas
6/7/2023
Define constructor clase Episodio
*/
#include "Episodio.h"
#include <iostream>
#include <string>
using namespace std;

Episodio::Episodio(string iD1, string nombre1, int duracion1, string genero1,
                 float calificacion1, string fechaEstreno1,  string iDepisodio1, string nombreEpisodio1,
                 int temporada1, int numEpisodio1) : Video(iD1, nombre1,
                    duracion1, genero1, calificacion1, fechaEstreno1){
    temporada = temporada1;
    numEpisodio = numEpisodio1;
    iDepisodio = iDepisodio1;
    nombreEpisodio = nombreEpisodio1;

}
void Episodio::mostrarDatos() const
{
    cout << "ID: " << getID() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Duracion: " << getDuracion() << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << endl;
    cout << "Fecha de Estreno: " << getFechaEstreno() << endl;
    cout << "ID de Episodio: " << getIdEp() << endl;
    cout << "Nombre de Episodio: " << getNombreEpisodio() << endl;
    cout << "Temporada: " << getTemporada() << endl;
    cout << "Episodio: " << getNumEpisodio() << endl;
    cout << endl;
}

int Episodio:: getTemporada() const{
    return temporada;
}
string Episodio:: getIdEp() const{
    return iDepisodio;
}
string Episodio:: getNombreEpisodio() const{
    return nombreEpisodio;
}
int Episodio:: getNumEpisodio() const{
    return numEpisodio;
}

