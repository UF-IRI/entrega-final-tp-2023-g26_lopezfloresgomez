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


    return 0;
}

/*
 * // crear una estructura generica, con datos llenos por la informacion dada por la consigna (horarios, tipo de clase)
typedef struct {
    unsigned int cupoMax;//cupo maximo de personas por clase en este horario
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
*/
int leerArchivoClases(ifstream &archivo, clase* &clase, unsigned int &tamC){
    char delimiter = ',';
    string line;

    stringstream iss;

    if(archivo.is_open()){

        getline(archivo, line);

        while(!archivo.eof() && getline(archivo, line)){
            iss.clear();
            iss<<line;

            incrementarClases(clase, tamC);

            getline(iss, line, delimiter);
            clase[tamC-1].Turnos->idclas= stoi(line);
            getline(iss, line, delimiter);
            clase[tamC-1].nombreclas=line;
            getline(iss, line);
            clase[tamC-1].Turnos->horario=stof(line);
        }

    }
    return 1;
}

void incrementarClases(clase* &clases, unsigned int &tam){
    if(clases==nullptr){
        if(tam<=0){
            clases = new clase[++tam];
        }
        return;
    }

    clase* temporal = new clase[++tam];

    for(unsigned int i = 0; i < tam-1; i++){
        temporal[i] = clases[i];
    }
    delete[] clases;
    clases = temporal;
}
