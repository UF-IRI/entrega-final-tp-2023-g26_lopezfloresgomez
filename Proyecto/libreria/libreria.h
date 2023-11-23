#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "libreria_global.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

struct clase {
    string nombreClas;
    float horario;// posible horario de clase
    unsigned int idClas;
    unsigned int cupo;
    unsigned int cupoMax;//cupo maximo de personas por clase en este horario
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

bool reserva(usuario * usuarios,clase* clases);
bool verificarPago(usuario usuario);
bool menores(usuario usuario);


#endif // LIBRERIA_H
