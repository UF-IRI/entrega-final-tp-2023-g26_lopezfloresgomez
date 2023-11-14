#include "archivos.h"
#include "libreria.h"
#include <iostream>
#include <fstream>
#include <string>

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

int leerArchivo(ifstream &archivo, claseG *aux){

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return errArchivo::errArchivoLeer;
    }


    return 0;
}
