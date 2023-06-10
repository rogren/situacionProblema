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
    vector<Peliculas *> peliculas; // Vector para almacenar las películas

    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
        if (numeroLinea > 1)
        {
            // cout << (numeroLinea++) << ":" << linea << endl;
            vector<string> datos = separar(linea);
            if (datos.size() == 6)
            {
                // cout << "P: " << linea << endl;
                // Peliculas* pelicula = new Peliculas(datos[0], datos[1], datos[3], stoi(datos[4]), stof(datos[5]), stoi(datos[6]));
                // peliculas.push_back(pelicula);
            }
            else if (datos.size() == 10)
            {
                cout << "Episodio: " << linea << endl;
                Episodio *episodio = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
                cout << "ID de episodio: " << episodio->getIdEp() << endl;
            }
            cout << endl;
        }
        numeroLinea++;
    }

    entrada.close();

    return 0;
}

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
