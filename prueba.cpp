#include <iostream>
#include "Streaming.h"
using namespace std;

int main()
{
    Streaming streaming;
    string archivo;

    cout << " Ingresa el nombre del archivo que quieres abrir: ";
    cin >> archivo;

    while (!streaming.CargaExcel(archivo))
    {
        cout << " Archivo no encontrado " << endl;
        cout << " Ingresa el nombre del archivo que quieres abrir: ";
        cin >> archivo;
    }
    while (true)
    {
        cout << endl;
        int opcion;
        cout << "=======Prueba=======" << endl;
        cout << "1. Mostrar Peliculas" << endl;
        cout << "2. Mostrar Series" << endl;
        cout << "3. Filtrar Peliculas por calificacion" << endl;
        cout << "4. Filtrar Videos en general por calificacion" << endl;
        cout << "5. Salir " << endl;

        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            streaming.mPeliculas();
        }
        else if (opcion == 2)
        {
            streaming.mSeries();
        }
        else if (opcion == 3)
        {
            float calif;
            cout << "Ingresa la calificacion por la que deseas filtrar: ";
            cin >> calif;
            cout << endl;
            cout << "******************** Peliculas con calificacion mayor o igual a " << calif << " ********************" << endl;
            cout << endl;
            bool parametro = streaming.mostrarCalifPel(calif);

        }
        else if (opcion == 4)
        {
            float calif;
            cout << "Ingresa la calificacion por la que deseas filtrar: ";
            cin >> calif;
            cout << endl;
            cout << "******************** Videos con calificacion mayor o igual a " << calif << " ********************" << endl;
            bool parametro = streaming.mostrarCalifVid(calif);

            if (!parametro)
            {
                cout << "No se encontraron videos con calificacion de " << calif << endl;
            }
        }
        else if (opcion == 5)
        {
            cout << "Saliendo del servicio..." << endl;
            break;
        }
        else
        {
            cout << endl;
            cout << "O P C I O N  I N V A L I D A" << endl;
        }
    }

    return 0;
}