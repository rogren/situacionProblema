int main() {
    ifstream entrada("DatosPeliculas.csv");
    if (!entrada) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea)) {
        if (numeroLinea > 1) {
            vector<string> datos = separar(linea);
            if (datos.size() == 6) {
                cout << "Pelicula: ";
                Pelicula pelicula(datos);
            } else {
                cout << "Episodio: ";
                Episodio episodio(datos);
            }
            cout << endl;
        }
        numeroLinea++;
    }

    entrada.close();

    return 0;
}