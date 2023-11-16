#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "libreria_global.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// crear una estructura generica, con datos llenos por la informacion dada por la consigna (horarios, tipo de clase)
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


struct claseG {
    string nombreClaS;
    Turno* Turnos;
};

// turnos,es la funcion que nos muestra los horarios disponibles junto con los cupos, la cantidad de inscriptos y la info de cada alumno en ese horario
/* la estructura clase contiene el nombre de la clase, el id, y la cantidad de horarios disponibles (canTturnos), y a su vez contiene la subestructura
turnos, que engloba la info de cada horario*/
/* que hacer para el relleno de las estructuras, ya que no tenemos una estructura generica que nos permita realizar comparativas con la informacion
 y a su vez es necesario dar informacion a estructuras que deberan ser rellenadas con los datos de los archivos, por ejemplo nombreclas,idclase
cupo_max*/

struct usuario
{
    string nombre;
    string apellido;
    string email;
    string fechaNac;
    int idCliente;
    int estado;
    string telefono;

};
struct Inscripcion
{
    unsigned int idCurso;// creemos que es idclase
    time_t fechaInscripcion;// horario de incripcion de la persona, entre las 19 a 22, a mi criterio. con 24 horas de anticipacion, restriccion
};
typedef struct Inscripcion Inscripcion;

struct Asistencia
{
    int idCliente;
    Inscripcion* CursosInscriptos;
};
typedef struct Asistencia Asistencia;
typedef struct usuario usuario;
typedef struct clase clases;


// deesglosar todas las funciones, hacer el analisis de todas las restricciones, para encontrar los usuarios validos,
/* analizar errores de sintaxis, hacer la de menores, encargarnos de todos los archivos ( simplemente bajarlos y guardarlos en nuestra estructura
*/

class LIBRERIA_EXPORT Libreria
{
public:
    Libreria();
};

int leerArchivoGen(ifstream archivo, claseG *aux);
bool reserva(usuario * usuarios,clase* clases);
bool verificarPago(usuario usuario);
bool cupomax(clase clase,int m, claseG *array);
bool correspondencia (clase clase, int m,claseG *claseGe);



#endif // LIBRERIA_H
