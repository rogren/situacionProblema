/*
lee un archivo en c++
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
vector<string> separar(string linea);

main(int argc, char const *argv[])
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
       // cout << (numeroLinea++) << ":" << linea << endl;
        vector<string> datos = separar(linea);
        if (datos.size()==6)
        {
            cout << "Pelicula: ";
            //new Pelicula(datos);
        } else
        {
            cout << "Episodio: ";
            //new Episodio(datos);
        }
        cout << endl;
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
            //cout << dato << endl;
            tokens.push_back(dato); //GUARDA en vector
            numeroTokens++;
        }
    }
    //cout << "Tokens: " << numeroTokens << endl << endl;
    return tokens;
}