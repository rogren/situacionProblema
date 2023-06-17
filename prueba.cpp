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
        cout << " Ingresa el nombre del archivo que quieres abrir: ";
        cin >> archivo;
    }
    while (true)
    {
        cout << endl;
        int opcion;
        cout << "***************************************** M E N U *****************************************" << endl;
        cout << "1. Mostrar Peliculas" << endl;
        cout << "2. Mostrar Series" << endl;
        cout << "3. Filtrar Peliculas por calificacion" << endl;
        cout << "4. Filtrar Videos en general por calificacion" << endl;
        cout << "5. Filtrar Episodios de Series" << endl;
        cout << "6. Calificar videos " << endl;
        cout << "7. Obtener promedio de calificacion de serie" << endl;
        cout << "8. Filtrar por genero" << endl;
        cout << "9. Salir " << endl;

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
            string nombreSerie;
            cout << "Ingresa el nombre de la serie que deseas filtrar: ";
            cin.ignore(); // .ignore es utilizado para evitar que el menu entre en bucle infitito
            getline(cin, nombreSerie);
            cout << endl;
            cout << "******************** Episodios de la serie: " << nombreSerie << " ********************" << endl;
            streaming.filtrarSerie(nombreSerie);
        }
        else if (opcion == 6)
        {
            streaming.calificacionV();
        }
        else if (opcion == 7)
        {
            string nombreSerie;
            cout << "Ingresa el nombre de la serie para calcular el promedio de calificación: ";
            cin.ignore();
            getline(cin, nombreSerie);
            cout << endl;

            float promedioCalificacion = streaming.promedioCalificacion(nombreSerie);
            cout << "El promedio de calificación de la serie '" << nombreSerie << "' es: " << promedioCalificacion << endl;
        }
        else if (opcion == 8)
        {
            string genero;
            cout << " Ingresa el genero que deseas buscar: ";
            cin.ignore();
            getline(cin, genero);
            cout << endl;
            streaming.filtrarGenero(genero);
        }
        else if (opcion == 9)
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