#include <iostream>
#include "Streaming.h"
using namespace std;

int main()
{
    Streaming streaming;
    string archivo;

    cout << " Ingresa el nombre del archivo que quieres abrir: ";
    cin >> archivo;

    while (!streaming.CargaExcel(archivo))  //llama al metodo CargaExcel hasta que este abra correctamente
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
            streaming.mPeliculas(); //llama al metodo mPeliculas de clase Streaming 
        }
        else if (opcion == 2)
        {
            streaming.mSeries();    //llama al metodo mSeries de clase Streaming 
        }
        else if (opcion == 3)
        {
            float calif;
            cout << "Ingresa la calificacion por la que deseas filtrar: ";
            cin >> calif;
            cout << endl;
            cout << "******************** Peliculas con calificacion mayor o igual a " << calif << " ********************" << endl;
            cout << endl;
            bool parametro = streaming.mostrarCalifPel(calif);  //llama al metodo mostrarCalifPel de clase Streaming 
        }
        else if (opcion == 4)
        {
            float calif;
            cout << "Ingresa la calificacion por la que deseas filtrar: ";
            cin >> calif;
            cout << endl;
            cout << "******************** Videos con calificacion mayor o igual a " << calif << " ********************" << endl;
            bool parametro = streaming.mostrarCalifVid(calif);  //llama al metodo mostrarCalifVid de clase Streaming 

            if (!parametro)
            {
                cout << "No se encontraron videos con calificacion de " << calif << endl;
            }
        }
        else if (opcion == 5)
        {
            string nombreSerie;
            cout << "Ingresa el nombre de la serie que deseas filtrar: ";
            cin.ignore();   // descarta caracteres residuales y evita que el menu entre en un bucle
            getline(cin, nombreSerie);
            cout << endl;
            cout << "******************** Episodios de la serie: " << nombreSerie << " ********************" << endl;
            streaming.filtrarSerie(nombreSerie);    //llama al metodo filtrarSerie de clase Streaming 
        }
        else if (opcion == 6)
        {
            streaming.calificacionV();  //llama al metodo CalificacionV de clase Streaming 
        }
        else if (opcion == 7)
        {
            string nombreSerie;
            cout << "Ingresa el nombre de la serie para calcular el promedio: ";
            cin.ignore();   // descarta caracteres residuales y evita que el menu entre en un bucle
            getline(cin, nombreSerie);
            cout << endl;

            float promedioCalificacion = streaming.promedioCalificacion(nombreSerie);   //llama al metodo promedioCalificacion de clase Streaming 
            cout << "El promedio '" << nombreSerie << "' es: " << promedioCalificacion << endl;
        }
        else if (opcion == 8)
        {
            string genero;
            cout << " Ingresa el genero que deseas buscar: ";
            cin.ignore();   // descarta caracteres residuales y evita que el menu entre en un bucle
            getline(cin, genero);
            cout << endl;
            streaming.filtrarGenero(genero);    //llama al metodo filtrarGenero de clase Streaming 
        }
        else if (opcion == 9)
        {
            cout << "Saliendo del servicio..." << endl;
            break;
        }
        else
        {
            cout << endl;
            cout << "ERROR" << endl << "O P C I O N  I N V A L I D A" << endl;
        }
    }
    return 0;
}