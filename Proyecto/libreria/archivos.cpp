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

int leerArchivo(ifstream archivo, claseG *aux){

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return errArchivo::errArchivoLeer;
    }

    int i=0,j=0, filas=0;
    char caracter;
    string elemento;
    string hora;
    string cupo;

    while (archivo.get(caracter)) {   //.get agarra el caracter
        if (caracter == ',') {
            if(i==0){
                elemento.clear();
                i++;
            }
            switch (filas){
            case 0:
                aux[i].nombreClaS = elemento;
                break;
            case 2:
                aux[i].Turnos->cupo_max = stoi(elemento);
                break;
            case 4:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 8 : NULL;
                break;
            case 5:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 9 : NULL;
                break;
            case 6:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 10 : NULL;
                break;
            case 7:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 11 : NULL;
                break;
            case 8:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 12 : NULL;
                break;
            case 9:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 13 : NULL;
                break;
            case 10:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 14 : NULL;
                break;
            case 11:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 15 : NULL;
                break;
            case 12:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 16 : NULL;
                break;
            case 13:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 17 : NULL;
                break;
            case 14:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 18 : NULL;
                break;
            case 15:
                aux[i].Turnos[j].horario = (caracter == 'X') ? 19 : NULL;
                break;
            }
        } else if (caracter == '\n') {   // \n salto de linea

            i=0;
            elemento.clear();

        } else {
            //elemento.push_back(caracter);   //le mete el caracter
        }
    }


    return 0;
}
