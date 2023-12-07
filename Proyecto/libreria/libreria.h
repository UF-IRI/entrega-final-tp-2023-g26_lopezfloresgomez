#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "libreria_global.h"

using namespace std;

typedef std::string str;
typedef unsigned int u_int;

// Declaro Errores
enum ErroresClientes  { ErrEstado = -7, ErrIdClienteinx = -6, ErrNombre = -5, ErrApellido = -4, ErrTelefono = -3, ErrMuyViejo = -2, ErrMuyJoven = -1, ExitoCliente = 1 };
enum ErroresClases  { ErrEspacioCrearAsistencia = -5, ErrClaseRepetida = -4, ErrSuperposicionDeHorarios = -3, ErrCupos = -2, ErrIdClaseinx = -1, ExitoClase = 1 };
enum ErroresAsistencias  { ErrEspacio = -1, ExitoAsistencias = 1, ExitoCrearAsistencias = 2 };
enum ErroresDia  { ErrDia = -1, ExitoDia = 1 };

typedef enum ErroresClientes  eErroresClientes;
typedef enum ErroresClases eErroresClases;
typedef enum ErroresAsistencias   eErroresAsistencias;
typedef enum ErroresDia eErroresDia;

// Declaro estructuras
typedef struct
{
    u_int idClase;
    time_t fechaInscripcion;

} Inscripcion;

typedef struct
{
    u_int idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;

} Asistencia;

typedef struct
{
    u_int idClase;
    str nombre;
    float horario;
    u_int cuposActuales;
    u_int cuposMax;

} ClasesGym;

typedef struct
{
    u_int idCliente;
    str nombre, apellido, email, telefono;
    str fechanacimiento;
    int estado;

} ClientesGYM;

// Declaro errores
enum ErroresArchivos {ErrorApertura = -2, ErrorEscritura = -1, ExitoOperacion = 1};
typedef enum ErroresArchivos  eErroresArchivos;

// Declaro Funciones
eErroresArchivos leerArchivoClientes(ifstream &archivoClientes, ClientesGYM *&clientes, u_int &cantClientes);
eErroresArchivos leerArchivoClases(ifstream &archivoClases, ClasesGym *&clases, u_int &cantClases);
eErroresArchivos LeerArchivoBinario(ifstream &archivoBinario, Asistencia *asistencias);
eErroresArchivos EscribirArchivoBinario(ofstream &archivoBinario, Asistencia *&asistenciaClientes, u_int &cantAsistencias);

// Buscar
eErroresClientes BuscarIdCliente(ClientesGYM *clientes, u_int idCliente, u_int cantClientes, ClientesGYM &cliente);
ErroresClases BuscarIdClase(ClasesGym *clases, u_int idClase, u_int cantClases, ClasesGym &clase);
ErroresClases BuscarIdClase(ClasesGym *clases, u_int idClase, u_int cantClases);
eErroresAsistencias BuscarAsistenicaCliente(u_int idCliente, u_int idClase, Asistencia *&asistenciaClientes, Asistencia &asistenciaCliente, u_int &cantAsistencias);
eErroresAsistencias BuscarAsistenicaCliente(u_int idClase, u_int idCliente,  Asistencia *&asistenciaClientes);
ErroresClases BuscarIdClaseEnInscripciones(Asistencia asistenciaCliente, u_int idClase);

// Filtrar
eErroresClientes FiltroDeCliente(ClientesGYM *clientes, u_int idCliente, u_int cantClientes);
ErroresClases FiltroDeClase(ClasesGym *clases, u_int idCliente, u_int idClase, Asistencia *&asistenciaClientes, u_int cantClases, u_int &CantAsistencias);
eErroresDia FiltroFecha();

// Resize
Asistencia* resizeClientes(Asistencia *asistenciaClientes, u_int CantAsistencias, u_int nuevoTam, eErroresAsistencias &eAsist);
Inscripcion* resizeInscripcion(Asistencia *asistenciaClientes, u_int cantInscripciones, u_int nuevoTam, eErroresAsistencias &eAsist2);

// Comparar
ErroresClases CompararClaseInscripciones(ClasesGym clase, Asistencia asistenciaCliente, ClasesGym *clases, u_int cantClases);

// Controlar archivo binario
void ordenarclasesinscriptas(Asistencia* asistenciaClientes, int cantAsistencias);
void eliminarclaserepetida(Asistencia* asistenciaClientes, int cantAsistencias);
void ordenarlasclaseseliminadasalfinal(Asistencia* asistenciaClientes, int cantAsistencias);
ErroresClases CompararClaseInscripciones(Asistencia* asistenciaClientes, ClasesGym *clases, u_int cantClases);


class LIBRERIA_EXPORT Libreria
{
public:
    Libreria();
};

#endif // LIBRERIA_H
