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

/*
//declaro errores
enum Clientes  { ErrEstado = -7, ErrIdClienteinx = -6, ErrNombre = -5, ErrApellido = -4, ErrTelefono = -3, ErrMuyViejo = -2, ErrMuyJoven = -1, ExitoCliente = 1 };
enum Clases  { ErrEspacioCrearAsistencia = -5, ErrClaseRepetida = -4, ErrSuperposicionDeHorarios = -3, ErrCupos = -2, ErrIdClaseinx = -1, ExitoClase = 1 };
enum Asistencias  { ErrEspacio = -1, ExitoAsistencias = 1, ExitoCrearAsistencias = 2 };
enum Dia  { ErrDia = -1, ExitoDia = 1 };


typedef enum Clientes  eCliente;
typedef enum Clases  eClase;
typedef enum Asistencias   eAsistencia;
typedef enum Dia eDia;
//Buscar
eCliente BuscarIdCliente(usuario *usuarios, u_int idCliente, u_int tamU, usuario &cliente);
eClase BuscarIdClase(clase *Clases, u_int idClas, u_int tamC, clase &clases);
eClase BuscarIdClase(clase *Clases, u_int idClas, u_int tamC);
eAsistencia BuscarAsisCliente(u_int idClas, u_int idCliente,  Asistencia *&Asistencias, Asistencia &AsistenciaCliente, u_int &tamA);
eAsistencia BuscarAsisClienteCliente(u_int idClas, u_int idCliente,  Asistencia *&Asistencias);
eClase BuscarIdClaseEnInscripciones(Asistencia AsistenciaUser, unsigned int idClas);
//Filtrar
eCliente FiltroDeCliente(usuario *usuarios, u_int idCliente, u_int &tamC);
eClase FiltroDeClase(clase *Clases, u_int idCliente, u_int idClase, Asistencia *&Asistencias, u_int &tamC, u_int &tamA);
eDia FiltroFecha();

//resize
Asistencia* resizeClientes(Asistencia *Asistencias, u_int tamA, u_int nuevoTam,eAsistencia &eAsist);
Inscripcion* resizeInscripcion(Asistencia* Asistencias, u_int cantI, u_int nuevoTam,eAsistencia &eAsist2);

//comparar
eClase CompararClaseInscripciones(ClasesGym clase, Asistencia AsistenciaCliente, ClasesGym *Clases, u_int cantclases);

//Controlar archivo binario
void ordenarclasesinscriptas(Asistencia* asistencias, size_t tamA);
void eliminarclaserepetida(Asistencia* asistencias, int tamA);
void ordenarlasclaseseliminadasalfinal(Asistencia* asistencias, int tamA);
eClase CompararClaseInscripciones(Asistencia* Asistencias, clase *Clases, u_int tamC, int tamA);
*/

class LIBRERIA_EXPORT Libreria
{
public:
    Libreria();
};
#endif // LIBRERIA_H
