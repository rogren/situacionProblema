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
                    Series *nSerie = new Series(datos[0], datos[1], datos[3]);
                    nSerie->agregarEp(episodio);
                    series.push_back(nSerie);
                }
            }
            numeroLinea++;
        }
        entrada.close();
        return true;
    }
    else
    {
        cout << " ERROR " << endl;
        return false;
    }
}

void Streaming::mPeliculas()
{
    cout << endl;
    cout << "********************* P E L I C U L A S *********************" << endl;
    for (Peliculas *pelicula : peliculas)
    {
        pelicula->mostrarDatos();
    }
}

void Streaming::mSeries()
{
    cout << endl;
    cout << "************ S E R I E S ***********" << endl;
    string nombres = "";

    for (Series *serie : series)
    {
        if (serie->getNombreSerie() != nombres)
        {
            cout << "========================================================================" << endl;
            cout << "ID: " << serie->getiDSer();
            cout << " Nombre: " << serie->getNombreSerie() << endl;
            nombres = serie->getNombreSerie();
            cout << "========================================================================" << endl;
        }
        for (Episodio *episodio : serie->getEpisodios())
            episodio->mostrarDatos();
    }
}

bool Streaming::mostrarCalifPel(float valor) const
{
    int calMAX = 7; // define cual es la calificacion maxima que tienen los videos
    bool parametro = false;

    while (!parametro)
    {
        for (Peliculas *pelicula : peliculas)
        {
            if (pelicula->getCalificacion() >= valor)
            {
                pelicula->mostrarDatos();
                parametro = true;
            }
        }

        if (!parametro)
        {
            cout << endl;
            cout << "No se encontraron peliculas con calificacion de " << valor << endl;

            if (valor > calMAX)
            {
                cout << "Recuerda que la calificacion maxima es " << calMAX << endl;
                cout << endl;
            }
            cout << "Ingresa la calificacion por la que deseas filtrar: ";
            cin >> valor;
        }
    }

    return parametro;
}

bool Streaming::mostrarCalifVid(float valor) const
{
    int calMAX = 7; // define cual es la calificacion maxima que tienen los videos
    bool parametro = false;

    while (!parametro)
    {
        for (Peliculas *pelicula : peliculas)
        {
            if (pelicula->getCalificacion() >= valor)
            {
                pelicula->mostrarDatos();
                parametro = true;
            }
        }

        for (Series *serie : series)
        {
            for (Episodio *episodio : serie->getEpisodios())
            {
                if (episodio->getCalificacion() >= valor)
                {
                    cout << "========================================================================" << endl;
                    cout << "iD: " << episodio->getID();
                    cout << " Nombre: " << episodio->getNombre() << endl;
                    cout << "========================================================================" << endl;
                    cout << "Genero: " << episodio->getGenero() << endl;
                    episodio->mostrarDatos();
                    parametro = true;
                }
            }
        }
        if (!parametro)
        {
            cout << endl;
            cout << "No se encontraron peliculas con calificacion de " << valor << endl;

            if (valor > calMAX)
            {
                cout << "Recuerda que la calificacion maxima es " << calMAX << endl;
                cout << endl;
            }
            cout << "Ingresa la calificacion por la que deseas filtrar: ";
            cin >> valor;
        }
    }
    return parametro;
}

bool Streaming::filtrarSerie(const string &nombreSerie) const
{
    bool encontrado = false;
    for (Series *serie : series)
    {
        if (serie->getNombreSerie() == nombreSerie)
        {
            encontrado = true;
            for (Episodio *episodio : serie->getEpisodios())
            {
                cout << "----------------------------------------------------" << endl;
                episodio->mostrarDatos();
            }
        }
    }
    if (!encontrado)
    {
        cout << "La serie no esta disponible en la plataforma" << endl;
    }
}
void Streaming::calificacionV()
{
    string titulo;
    cout << " Ingresa el titulo de la pelicula o episodio que quieres calificar : ";
    cin.ignore();
    getline(cin, titulo);

    bool encontrado = false;

    for (Peliculas *pelicula : peliculas)
    {
        if (pelicula->getNombre() == titulo)
        {
            float calificacion;
            cout << " Ingresa la calificacion que quieres dar a " << pelicula->getNombre() << " : ";
            cin >> calificacion;
            pelicula->setCalificacion(calificacion);
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        for (Series *serie : series)
        {
            for (Episodio *episodio : serie->getEpisodios())
            {
                if (episodio->getNombreEpisodio() == titulo)
                {
                    float calificacion;
                    cout << " Ingresa la calificacion que quieres dar a " << episodio->getNombreEpisodio() << " : ";
                    cin >> calificacion;
                    episodio->setCalificacion(calificacion);
                    encontrado = true;
                    cout << endl << " ¡Se asigno la calificacion correctamente! " << endl;
                    break;
                }
            }
            if (encontrado)
            {
                break;
            }
        }
    }
    if (!encontrado)
    {
        cout << "No se encontro en la plataforma el video que diste" << endl;
    }
}

