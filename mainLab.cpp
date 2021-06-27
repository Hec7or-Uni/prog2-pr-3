# include <iostream>
# include <cstring>
# include "laberinto.hpp"

using namespace std;

int main(int numArg, char* args[]) {
    if ((numArg == 2) || (numArg == 4)) {
        if (numArg == 2) {
            // Inicializacion de Variables
            Laberinto lab;
            bool encontrado = false;
            char nombreFichero[] = "datos/";
            // LLamada de métodos
            strcat(nombreFichero, args[1]);
            cargarLaberinto(nombreFichero, lab);
            buscarCamino(lab, encontrado);
            mostrarLaberintoR(lab);
        } else {
            double Densidad = stod(args[3]);    // stod() => Convierte un <DATO> a un Double.
            int Alto  = atoi(args[1]);          // atoi() => Convierte un <DATO> a un Entero.
            int Ancho = atoi(args[2]);
            // Me aseguro de que cumple las precondicones de un laberinto correcto
            if ((Densidad >= 0) && (Densidad <= 1) && (Alto >= 3) && (Ancho >= 3) && (Alto <= MAX_DIM) && (Ancho <= MAX_DIM)) {
                // Inicialzación de Variables
                Laberinto lab;
                bool encontrado = false;
                lab.alto = Alto;
                lab.ancho = Ancho;
                // LLamada de métodos
                generarLaberinto(lab, Densidad, 0, 0);
                lab.mapa[1][1] = LIBRE;                     // Me aseguro de que lab.mapa[1][1] esta libre.
                lab.mapa[lab.alto-2][lab.ancho-2] = LIBRE;  // Me aseguro de que lab.mapa[lab.alto-2][lab.ancho-2] esta libre.
                buscarCamino(lab, encontrado);
                mostrarLaberintoR(lab);
            } else {
                cerr << "Ha ocurrido un ERROR: " << endl;
                cerr << "    -La densidad  debe estar entre 0 y 1" << endl;
                cerr << "    -La altura  debe ser: 3 <= Altura <= " << MAX_DIM << endl;
                cerr << "    -La anchura debe ser: 3 <= Ancho  <= " << MAX_DIM <<endl;
            }
        }
    } else {
        cerr << "Argumentos invalidos, pruebe una de estas opciones: " << endl;
        cerr << "~Resolver  ->  ./mainLab <labName.txt>" << endl;
        cerr << "~Generar   ->  ./mainLab <Fila[F>=3]> <Columna[C>=3]> <Densidad[0-1]>" << endl;
    }
    return 0;
}