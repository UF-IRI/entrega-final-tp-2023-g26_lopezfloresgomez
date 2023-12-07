#include <libreria.h>
#include <archivos.h>

Asistencia* resizeClientes(Asistencia *Asiscliente, u_int CantAsis, u_int nuevoTam, filesA &filesA){

    Asistencia* auxA = new Asistencia[nuevoTam];

    u_int longitud = (CantAsis <  nuevoTam) ? CantAsis : nuevoTam;

    if(auxA != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            auxA[i] = Asiscliente[i];


        filesA = ExitoAsistencias;
        return auxA;
    }

    filesA = ErrEspacio;
    return nullptr;
}

Inscripcion* resizeInscripcion(Asistencia* AsisClientes, u_int cantins, u_int nTam, filesA &filesA){

    Inscripcion* aux = new Inscripcion[nTam];

    u_int longitud = (cantins<  nTam) ? cantins : nTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = AsisClientes->CursosInscriptos[i];


        filesA = ExitoAsistencias;
        return aux;
    }

    filesA = ErrEspacio;
    return nullptr;
}

filesCLI BuscarIdCliente(usersGYM *Clientes, u_int idCliente, u_int CantClientes, usersGYM &cliente)
{
    usersGYM *aux = Clientes, *ultimo = (Clientes) + CantClientes - 1;
    while(true) {
        if (aux->idCliente == idCliente ){
            cliente = *aux;
            return filesCLI :: ExitoCliente;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return filesCLI :: ErrIdClienteinx;
}

filesCLA BuscarIdClase(classGYM *Clases, u_int idClase, u_int cantClases, classGYM &clase)
{
    classGYM *aux = Clases, *ultimo = (Clases) + cantClases - 1;
    while(true) {
        if (aux->idClase == idClase ){
            clase = *aux;
            return filesCLA :: ExitoClase;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return filesCLA :: ErrIdClaseinx;
}

