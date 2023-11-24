#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "libreria_global.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

typedef unsigned int u_int;
using namespace std;

struct clase {
    string nombreClas;
    float horario;// posible horario de clase
    unsigned int idClas;
    unsigned int cupo;
    unsigned int cupoMax;//cupo maximo de personas por clase en este horario
};
struct usuario
{
    string nombre;
    string apellido;
    string email;
    string fechaNac;
    string telefono;
    int idCliente;
    int estado;
};
struct Inscripcion // bin
{
    unsigned int idCurso;// creemos que es idclase
    time_t fechaInscripcion;// horario de incripcion de la persona, entre las 19 a 22, a mi criterio. con 24 horas de anticipacion, restriccion
};
typedef struct Inscripcion Inscripcion;

struct Asistencia
{
    int idCliente;
    int cantInscriptos;
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
#endif // LIBRERIA_H
