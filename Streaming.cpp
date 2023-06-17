#include "Streaming.h"
#include "Peliculas.h"
#include "Episodio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Streaming::Streaming(){};
vector<string> Streaming::separar(string linea) // separar una linea en tokens
{
    vector<string> tokens; // vector para almacenar tokens

    stringstream entrada(linea);        // creacion de stringstream desde la cadena de entrada
    string dato;                        // variable que almacena cada token
    int numeroTokens = 0;               // contador tokens
    while (getline(entrada, dato, ',')) // uso de getline y ',' como delimitador de donde debe terminar cada token
    {
        if (dato != "") // si el token no esta vacio
        {
            tokens.push_back(dato); // Guardar en vector
            numeroTokens++;
        }
    }
    return tokens;
}

bool Streaming::CargaExcel(const string &archivo)
{
    ifstream entrada;      // ifstream lee el archivo
    entrada.open(archivo); // abrir archivo que se especifica
    if (entrada.is_open()) // verificar si el archivo se abrio
    {
        string linea;                   // variable que almacena las lineas del archivo
        int numeroLinea = 1;            // variable que cuenta numeros de linea
        while (getline(entrada, linea)) // while para leer el archivo
        {
            if (numeroLinea > 1) // ignorar primera linea que solo contiene estandares
            {
                vector<string> datos = separar(linea); // Separar los datos de la línea en un vector utilizando la función separar()

                if (datos.size() == 6) // si tiene 6 tokens es una pelicula
                {
                    // nuevo objeto pelicula con los datos obtenidos
                    Peliculas *pelicula = new Peliculas(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5]);
                    peliculas.push_back(pelicula);
                }
                else if (datos.size() == 10) // si tiene 10 tokens es un episodio
                {
                    // nuevo objeto episodio con los datos obtenidos
                    Episodio *episodio = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stof(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
                    episodios.push_back(episodio);

                    // Crear un nuevo objeto de la clase Series y agregarlo al vector series
                    // La serie se identifica por su nombre, datos[3]
                    Series *nSerie = new Series(datos[0], datos[1], datos[3]);
                    // agregar episodio a la serie
                    nSerie->agregarEp(episodio);
                    // agregar serie al vector de series
                    series.push_back(nSerie);
                }
            }
            numeroLinea++;  //siguiente linea
        }
        entrada.close();    //cerrar archivo
        return true;    
    }
    else
    {
        cout << " ERROR Archivo no encontrado" << endl;  // mensaje de error si no se encuentra el archivo
        return false;
    }
}

void Streaming::mPeliculas()
{
    cout << endl;
    cout << "********************* P E L I C U L A S *********************" << endl;
    for (Peliculas *pelicula : peliculas)   //recorre cada elemento del vector 
    {
        pelicula->mostrarDatos();   //invoca metodo mostrarDatos de pelicula
    }
}

void Streaming::mSeries()
{
    cout << endl;
    cout << "************ S E R I E S ***********" << endl;
    string nombres = "";    //esta variable controla la impresion del nombre de la serie 

    for (Series *serie : series)    //recorre cada elemento del vector series 
    {
        if (serie->getNombreSerie() != nombres) // si el nombre de la serie es diferente al anterior vuelve a imprimir el nombre, esto se hace para dar formato 
        {
            cout << "========================================================================" << endl;
            cout << "ID: " << serie->getiDSer();
            cout << " Nombre: " << serie->getNombreSerie() << endl;
            nombres = serie->getNombreSerie();
            cout << "========================================================================" << endl;
        }
        for (Episodio *episodio : serie->getEpisodios())  // recorre episodios de la serie 
            episodio->mostrarDatos();   //invoca metodo mostrarDatos de episodio
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
                    cout << endl
                         << " ¡Se asigno la calificacion correctamente! " << endl;
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

float Streaming::promedioCalificacion(const string &nombreSerie) const
{
    float sumaCalificaciones = 0.0; // Inicializar en 0 la suma de todas las calificaciones
    int totalEpisodios = 0;         // Inicializar en 0 el contador para los episodios de la serie

    for (Series *serie : series)
    {
        if (serie->getNombreSerie() == nombreSerie)
        {
            for (Episodio *episodio : serie->getEpisodios())
            {
                sumaCalificaciones += episodio->getCalificacion();
                totalEpisodios++;
            }
        }
    }

    if (totalEpisodios > 0)
    {
        return sumaCalificaciones / totalEpisodios;
    }
    else
    {
        return 0; // Si no se encontraron episodios de la serie, el promedio es 0.
    }
}
void Streaming::filtrarGenero(string &genero)
{
    string nombres = "";
    cout << "********************* Videos del genero " << genero << "*********************" << endl;
    bool encontrado = false;

    for (const Peliculas *pelicula : peliculas)
    {
        if (pelicula->getGenero().find(genero) != string::npos)
        {
            pelicula->mostrarDatos();
            encontrado = true;
        }
    }
    for (Series *serie : series)
    {

        if (serie->getGeneroSerie().find(genero) != string::npos)
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
            {
                episodio->mostrarDatos();
                encontrado = true;
            }
        }
    }
    if (!encontrado)
    {
        cout << " No se encontraron Videos con el genero " << genero << endl;
    }
}
