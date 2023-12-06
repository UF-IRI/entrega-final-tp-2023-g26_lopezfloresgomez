#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef string str;
typedef unsigned int u_int;


struct Inscripcion // bin
{
    unsigned int idCurso;// creemos que es idclase
    time_t fechaInscripcion;// horario de incripcion de la persona, entre las 19 a 22, a mi criterio. con 24 horas de anticipacion, restriccion
};

struct Asistencia
{
    int idCliente;
    int cantInscriptos;
    Inscripcion* CursosInscriptos;
};

typedef struct Inscripcion Inscripcion;
typedef struct Asistencia Asistencia;

typedef struct {
    string nombreClase;
    float horario; // posible horario de clase
    u_int idClase;
    u_int cupos;
    u_int cuposMax; //cupo maximo de personas por clase en este horario
} classGYM;

typedef struct
{
    string nombre;
    string apellido;
    string email;
    string fechaNac;
    string telefono;
    int idCliente;
    int estado;
} usersGYM;



#endif // LIBRERIA_H
