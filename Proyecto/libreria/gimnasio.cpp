#include <liberia.h>



Asistencia* resizeClientes(Asistencia *AsistenciaClientes, u_int CantAsistencias, u_int nuevoTam){

    Asistencia* aux = new Asistencia[nuevoTam];

    u_int longitud = (CantAsistencias <  nuevoTam) ? CantAsistencias : nuevoTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = AsistenciaClientes[i];
        return aux;
    }
    return nullptr;
}

Inscripcion* resizeInscripcion(Asistencia* AsistenciaClientes, u_int cantinscripciones, u_int nuevoTam){

    Inscripcion* aux = new Inscripcion[nuevoTam];

    u_int longitud = (cantinscripciones <  nuevoTam) ? cantinscripciones : nuevoTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = AsistenciaClientes->CursosInscriptos[i];;
        return aux;
    }
    return nullptr;
}
eCliente BuscarIdCliente(ClientesGYM *Clientes, u_int idCliente, u_int CantClientes, ClientesGYM &cliente)
{
    ClientesGYM *aux = Clientes, *ultimo = (Clientes) + CantClientes - 1;
    while(true) {
        if (aux->idCliente == idCliente ){
            cliente = *aux;
            return eCliente :: ExitoCliente;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eCliente :: ErrIdClienteinx;
}

eClase BuscarIdClase(ClasesGym *Clases, u_int idClase, u_int cantClases, ClasesGym &clase)
{
    ClasesGym *aux = Clases, *ultimo = (Clases) + cantClases - 1;
    while(true) {
        if (aux->idClase == idClase ){
            clase = *aux;
            return eClase :: ExitoClase;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eClase :: ErrIdClaseinx;
}
int BuscarIdCliente(ClientesGYM *Clientes, u_int idCliente, u_int CantClientes, ClientesGYM &cliente)
{
    ClientesGYM *aux = Clientes, *ultimo = (Clientes) + CantClientes - 1;
    while(true) {
        if (aux->idCliente == idCliente ){
            cliente = *aux;
            return 1 ;//Exito Cliente
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return 0;//Error id Cliente
}

int BuscarIdClase(ClasesGym *Clases, u_int idClase, u_int cantClases, ClasesGym &clase)
{
    ClasesGym *aux = Clases, *ultimo = (Clases) + cantClases - 1;
    while(true) {
        if (aux->idClase == idClase ){
            clase = *aux;
            return 1 // exito id clase
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return 0 // error id clase
}

