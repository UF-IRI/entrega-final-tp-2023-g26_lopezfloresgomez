#include "archivos.h"
#include "libreria.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*
typedef struct {
    unsigned int cupo_max;//cupo maximo de personas por clase en este horario
    float horario;// posible horario de clase
    unsigned int cantInscriptos;// cupos ocupados, reagrupar original
    unsigned int* alumnos;
    unsigned int idclas;
} Turno;

struct clase {
    string nombreclas;
    unsigned int cantTurnos;
    Turno* Turnos;

};
struct claseG {
    string nombreClaS;
    Turno* Turnos;
};
*/

int leerArchivoGen(ifstream &archivo, claseG* claseGen){

    int i=0,fila=0;


    char delimiter = ',';
    string line;
    string elemento;


    while (archivo.good()) {
        getline(archivo, line);
        istringstream iss(line);
        bool primeraColumna = true;
        if (fila == 0){
            while (getline(iss, claseGen[i].nombreClaS, delimiter)) {
                if (primeraColumna)
                    primeraColumna = false; // Si es la primera columna, no la guardamos
                else
                    i++;
            }
        }
        if (fila == 2){
            while (getline(iss, elemento, delimiter)) {
                if (primeraColumna) {
                    primeraColumna = false; // Si es la primera columna, no la guardamos
                } else {
                    for(int aux=0; aux<9; aux++){
                        claseGen[i].Turnos[aux].cupoMax = stoi(elemento);
                    }
                    i++;
                }
            }
        }
        if (fila >= 4){
            while (getline(iss, elemento, delimiter)) {
                if (primeraColumna) {
                    primeraColumna = false; // Si es la primera columna, no la guardamos
                } else {
                    if(elemento == "X")
                        claseGen[i].Turnos[fila-4].horario = 1;
                    else{
                        claseGen[i].Turnos[fila-4].horario = 0;
                    }
                    i++;
                }

            }
        }
        fila++;
        i = 0; // Reinicializar el contador i
    }

    /*
    int sol=4;
    for(int aux=0; aux<11; aux++){
        cout << claseGen[sol].nombreClaS << " " <<claseGen[sol].Turnos[aux].horario<< endl;
    }*/

    return 0;
}
