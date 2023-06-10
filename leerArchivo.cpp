#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Peliculas.h"
#include "Episodio.h"
#include "Video.h"

using namespace std;

vector<string> separar(string linea);

int main(int argc, char const *argv[])
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea = 1;

    vector<Peliculas*> peliculas; // Vector para almacenar las películas
    vector<Episodio*> episodios; // Vector para almacenar los episodios

    while (getline(entrada, linea))
    {
        if (numeroLinea > 1)
        {
            // cout << (numeroLinea++) << ":" << linea << endl;
            vector<string> datos = separar(linea);
            
            if (datos.size() == 6)
            {
                //cout << "Pelicula: " << linea << endl;
                Peliculas* pelicula = new Peliculas(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5]);
                peliculas.push_back(pelicula);
            }
            else if (datos.size() == 10)
            {
                //cout << "Episodio: " << linea << endl;
                Episodio *episodio = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
                episodios.push_back(episodio);
            }
            cout << endl;
        }
        numeroLinea++;
    }

    entrada.close();

    cout << "Episodios" << endl;
    for (Episodio* episodio: episodios)
    {
        cout<< "ID de Episodio: " << episodio->getID() << " Titulo: " << episodio->getNombre()  <<" Episodio: " << episodio->getNombreEpisodio()<< endl;
    }
    cout << endl;
    cout<< "Peliculas" << endl;
    for(Peliculas* pelicula: peliculas)
    {
        cout << "ID de Pelicula: " << pelicula->getID() <<" Titulo: " << pelicula->getNombre() << " Genero: " << pelicula->getGenero() << endl;
    }

    return 0;
}



//FUNCION
vector<string> separar(string linea)
{
    vector<string> tokens; // componentes linea

    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato != "")
        {
            // cout << dato << endl;
            tokens.push_back(dato); // GUARDA en vector
            numeroTokens++;
        }
    }
    // cout << "Tokens: " << numeroTokens << endl << endl;
    return tokens;
}
