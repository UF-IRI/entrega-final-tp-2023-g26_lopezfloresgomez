#include <libreria.h>


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

int BuscarIdCliente(ClientesGYM *Clientes, u_int idCliente, u_int CantClientes, ClientesGYM &cliente)
{
    ClientesGYM *aux = Clientes, *ultimo = (Clientes) + CantClientes - 1;
    while(true) {
        if (aux->idCliente == idCliente ){
            cliente = *aux;
            return 1;//Exito Cliente
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
            return 1;// exito id clase
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return 0; // error id clase
}

int BuscarIdClaseEnInscripciones(Asistencia AsistenciaUser, unsigned int idClas){

    int i=0;

    while(true) {
        if (AsistenciaUser.CursosInscriptos->idCurso == idClas ){
            return -1;
        }
        if ( AsistenciaUser.cantInscriptos == i)
            break;
        i++;
    }
    return 1;
}
eAsistencia BuscarAsisCliente(u_int idClase, u_int idCliente,  Asistencia *&AsistenciaClientes, Asistencia &AsistenciaCliente, u_int &CantAsistencias)
{
    int exito1,;
    if(CantAsistencias == 0){
        AsistenciaClientes = resizeClientes(AsistenciaClientes, CantAsistencias, CantAsistencias+1);

        /*if(exito1 == 1){
            AsistenciaClientes[CantAsistencias].idCliente = idCliente;
            AsistenciaClientes[CantAsistencias].cantInscriptos = 1;
            Asistencia *aux = AsistenciaClientes;
            AsistenciaClientes[CantAsistencias].CursosInscriptos = resizeInscripcion(aux, 0, 1);
            AsistenciaClientes[CantAsistencias].CursosInscriptos->idClase = idClase;
            AsistenciaClientes[CantAsistencias].CursosInscriptos->fechaInscripcion = time(0);
            AsistenciaCliente = AsistenciaClientes[CantAsistencias];
            CantAsistencias++;
            return 1;// ExitoCrearAsistencias;
        }
        else
            return 0; // ErrEspacio;
    }*/

    else{
        Asistencia *aux = AsistenciaClientes, *ultimo = (AsistenciaClientes) + CantAsistencias - 1;

        while(true) {

            if (aux->idCliente == idCliente ){
                AsistenciaCliente = *aux;
                return eAsistencia :: ExitoAsistencias;
            }

            if (aux == ultimo){
                AsistenciaClientes = resizeClientes(AsistenciaClientes, CantAsistencias, CantAsistencias+1);

                if(exito1 == 1){
                    AsistenciaClientes[CantAsistencias].idCliente = idCliente;
                    AsistenciaClientes[CantAsistencias].cantInscriptos = 1;
                    Asistencia *aux = AsistenciaClientes;
                    AsistenciaClientes[CantAsistencias].CursosInscriptos = resizeInscripcion(aux, 0, 1, eAsist2);
                    AsistenciaClientes[CantAsistencias].CursosInscriptos->idClase = idClase;
                    AsistenciaClientes[CantAsistencias].CursosInscriptos->fechaInscripcion = time(0);
                    AsistenciaCliente = AsistenciaClientes[CantAsistencias];
                    CantAsistencias++;
                    return 1 // ExitoCrearAsistencias;
                }

                else
                    return 0 // ErrEspacio;
            }

            aux++;
        }
    }

    return 1 //ExitoAsistencias ;
}
