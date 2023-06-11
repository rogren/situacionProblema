#include "Streaming.h"
#include "Peliculas.h"
#include "Episodio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Streaming::Streaming(){

};

vector<string> Streaming::separar(string linea)
{
    vector<string> tokens;

    stringstream entrada(linea);
    string dato;
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato != "")
        {
            tokens.push_back(dato); // Guardar en vector
            numeroTokens++;
        }
    }
    return tokens;
}

bool Streaming::CargaExcel(const string &archivo)
{
    ifstream entrada;
    entrada.open(archivo);
    if (entrada.is_open())
    {
        string linea;
        int numeroLinea = 1;
        while (getline(entrada, linea))
        {
            if (numeroLinea > 1)
            {
                vector<string> datos = separar(linea);

                if (datos.size() == 6)
                {
                    Peliculas *pelicula = new Peliculas(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5]);
                    peliculas.push_back(pelicula);
                }
                else if (datos.size() == 10)
                {
                    Episodio *episodio = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
                    episodios.push_back(episodio);
                }
            }
            numeroLinea++;
        }
        entrada.close();
        return true;
    }else{
        cout << " ERROR " << endl;
        return false;
    }
}

   

void Streaming::mPeliculas()
{
    cout << "Peliculas" << endl;
    for (Peliculas *pelicula : peliculas)
    {
        cout << "ID de Pelicula: " << pelicula->getID() << " Titulo: " << pelicula->getNombre() << " Genero: " << pelicula->getGenero() << endl;
    }
}

void Streaming::mEpisodios()
{
    cout << "Episodios" << endl;
    for (Episodio *episodio : episodios)
    {
        cout << "ID de Episodio: " << episodio->getID() << " Titulo: " << episodio->getNombre() << " Genero: " << episodio->getGenero() << endl;
    }
}
