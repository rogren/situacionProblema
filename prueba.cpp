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
        cout << "3. Salir " << endl;

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
            cout << "Saliendo del servicio..." << endl;
            break;
        }
        else
        {
            cout << "Opcion invalida" << endl;
            return 0;
        }
    }

    return 0;
}