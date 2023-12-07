#include <archivos.h>
#include <libreria.h>

Asistencia* resizeClientes(Asistencia *asistenciaClientes, u_int cantAsistencias, u_int nuevoTam, eErroresAsistencias &eAsist){

    Asistencia* aux = new Asistencia[nuevoTam];

    u_int longitud = (cantAsistencias <  nuevoTam) ? cantAsistencias : nuevoTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = asistenciaClientes[i];

        eAsist = ExitoAsistencias;
        return aux;
    }

    eAsist = ErrEspacio;
    return nullptr;
}

Inscripcion* resizeInscripcion(Asistencia *asistenciaClientes, u_int cantInscripciones, u_int nuevoTam, eErroresAsistencias &eAsist2){

    Inscripcion* aux = new Inscripcion[nuevoTam];

    u_int longitud = (cantInscripciones <  nuevoTam) ? cantInscripciones : nuevoTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = asistenciaClientes->CursosInscriptos[i];

        eAsist2 = ExitoAsistencias;
        return aux;
    }

    eAsist2 = ErrEspacio;
    return nullptr;
}

eErroresClientes BuscarIdCliente(ClientesGYM *clientes, u_int idCliente, u_int cantClientes, ClientesGYM &cliente)
{
    ClientesGYM *aux = clientes, *ultimo = (clientes) + cantClientes - 1;
    while(true) {
        if (aux->idCliente == idCliente ){
            cliente = *aux;
            return eErroresClientes::ExitoCliente;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eErroresClientes::ErrIdClienteinx;
}

ErroresClases BuscarIdClase(ClasesGym *clases, u_int idClase, u_int cantClases, ClasesGym &clase)
{
    ClasesGym *aux = clases, *ultimo = (clases) + cantClases - 1;
    while(true) {
        if (aux->idClase == idClase ){
            clase = *aux;
            return eErroresClases::ExitoClase;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eErroresClases::ErrIdClaseinx;
}

ErroresClases BuscarIdClase(ClasesGym *clases, u_int idClase, u_int cantClases)
{
    ClasesGym *aux = clases, *ultimo = (clases) + cantClases - 1;
    while(true) {
        if (aux->idClase == idClase ){
            aux->cuposActuales++;
            return eErroresClases::ExitoClase;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return ErroresClases::ErrIdClaseinx;
}

eErroresAsistencias BuscarAsistenicaCliente(u_int idClase, u_int idCliente,  Asistencia *&asistenciaClientes, Asistencia &asistenciaCliente, u_int &cantAsistencias)
{
    eErroresAsistencias eAsist;
    eErroresAsistencias eAsist2;
    if(cantAsistencias == 0){
        asistenciaClientes = resizeClientes(asistenciaClientes, cantAsistencias, cantAsistencias+1, eAsist);

        if(eAsist == ExitoAsistencias){
            asistenciaClientes[cantAsistencias].idCliente = idCliente;
            asistenciaClientes[cantAsistencias].cantInscriptos = 1;
            Asistencia *aux = asistenciaClientes;
            asistenciaClientes[cantAsistencias].CursosInscriptos = resizeInscripcion(aux, 0, 1, eAsist2);
            asistenciaClientes[cantAsistencias].CursosInscriptos->idClase = idClase;
            asistenciaClientes[cantAsistencias].CursosInscriptos->fechaInscripcion = time(0);
            asistenciaCliente = asistenciaClientes[cantAsistencias];
            cantAsistencias++;
            return eErroresAsistencias::ExitoCrearAsistencias;
        }
        else
            return eErroresAsistencias::ErrEspacio;
    }

    else{
        Asistencia *aux = asistenciaClientes, *ultimo = (asistenciaClientes) + cantAsistencias - 1;

        while(true) {

            if (aux->idCliente == idCliente ){
                asistenciaCliente = *aux;
                return eErroresAsistencias::ExitoAsistencias;
            }

            if (aux == ultimo){
                asistenciaClientes = resizeClientes(asistenciaClientes, cantAsistencias, cantAsistencias+1, eAsist);

                if(eAsist == ExitoAsistencias){
                    asistenciaClientes[cantAsistencias].idCliente = idCliente;
                    asistenciaClientes[cantAsistencias].cantInscriptos = 1;
                    Asistencia *aux = asistenciaClientes;
                    asistenciaClientes[cantAsistencias].CursosInscriptos = resizeInscripcion(aux, 0, 1, eAsist2);
                    asistenciaClientes[cantAsistencias].CursosInscriptos->idClase = idClase;
                    asistenciaClientes[cantAsistencias].CursosInscriptos->fechaInscripcion = time(0);
                    asistenciaCliente = asistenciaClientes[cantAsistencias];
                    cantAsistencias++;
                    return eErroresAsistencias::ExitoCrearAsistencias;
                }

                else
                    return eErroresAsistencias::ErrEspacio;
            }

            aux++;
        }
    }

    return eErroresAsistencias::ExitoAsistencias ;
}

eErroresAsistencias BuscarAsistenicaCliente(u_int idClase, u_int idCliente,  Asistencia *&asistenciaClientes)
{
    Asistencia *aux = asistenciaClientes;
    eErroresAsistencias eAsist2;

    while(true) {

        if (aux->idCliente == idCliente){
            aux->CursosInscriptos = resizeInscripcion(aux, aux->cantInscriptos, aux->cantInscriptos+1, eAsist2);
            if(eAsist2 == eErroresAsistencias::ExitoAsistencias){
                aux->cantInscriptos++;
                aux->CursosInscriptos[(aux->cantInscriptos)-1].idClase = idClase;
                aux->CursosInscriptos[(aux->cantInscriptos)-1].fechaInscripcion = time(0);
                return eErroresAsistencias::ExitoAsistencias;
            }
            else
                return eErroresAsistencias::ErrEspacio;
        }

        aux++;
    }
}

eErroresClases BuscarIdClaseEnInscripciones(Asistencia asistenciaCliente, u_int idClase){

    u_int cont = 0;

    while(true) {
        if (asistenciaCliente.CursosInscriptos->idClase == idClase ){
            return eErroresClases::ErrClaseRepetida;
        }
        if ( asistenciaCliente.cantInscriptos == cont)
            break;
        cont++;
    }
    return eErroresClases::ExitoClase;
}


eErroresClases CompararClaseInscripciones(Asistencia* AsistenciaClientes, ClasesGym* Clases, u_int cantClases, int cantAsistencias) {
    u_int i, j;
    ClasesGym clase1, clase2;
    Asistencia* auxAsistencias = AsistenciaClientes, *ultimo = AsistenciaClientes + cantAsistencias - 1;
    while (true) {
        for (i = 0; i < auxAsistencias->cantInscriptos; i++) {
            for (j = i + 1; j < auxAsistencias->cantInscriptos; j++) {
                if (auxAsistencias->CursosInscriptos[i].idClase != 0 || auxAsistencias->CursosInscriptos[j].idClase != 0) {
                    BuscarIdClase(Clases, auxAsistencias->CursosInscriptos[i].idClase, cantClases, clase1);
                    BuscarIdClase(Clases, auxAsistencias->CursosInscriptos[j].idClase, cantClases, clase2);
                    if (((clase1.horario - clase2.horario) < 1 && (clase1.horario - clase2.horario) > -1) || ((clase1.nombre == "Musculacion" && clase2.nombre == "Musculacion") && ((clase1.horario - clase2.horario) < 0.7 && (clase1.horario - clase2.horario) > -0.7))) {
                        auxAsistencias->CursosInscriptos[j].idClase = 0;
                        auxAsistencias->CursosInscriptos[j].fechaInscripcion = 0;
                        auxAsistencias->cantInscriptos--;
                    }
                }
            }
        }
        if (auxAsistencias == ultimo)
            break;
        auxAsistencias++;
    }

    return eErroresClases::ExitoClase;
}

void ordenarclasesinscriptas(Asistencia* AsistenciaClientes, size_t cantAsistencias) {
    Asistencia* auxAsistencias = AsistenciaClientes;
    Asistencia* ultimo = AsistenciaClientes + cantAsistencias - 1;
    Inscripcion aux;

    while (auxAsistencias <= ultimo) {
        if (auxAsistencias->cantInscriptos > 0) {
            for (u_int i = 0; i < auxAsistencias->cantInscriptos - 1; i++) {
                int Contcambios = 0;

                for (u_int j = 0; j < auxAsistencias->cantInscriptos - 1; j++) {
                    if (auxAsistencias->CursosInscriptos[j].fechaInscripcion > auxAsistencias->CursosInscriptos[j + 1].fechaInscripcion) {
                        aux = auxAsistencias->CursosInscriptos[j];
                        auxAsistencias->CursosInscriptos[j] = auxAsistencias->CursosInscriptos[j + 1];
                        auxAsistencias->CursosInscriptos[j + 1] = aux;
                        Contcambios++;
                    }
                }

                if (Contcambios == 0)
                    break;
            }
        }

        auxAsistencias++;

        if (auxAsistencias > ultimo)
            break;
    }

    return;
}

void eliminarclaserepetida(Asistencia* AsistenciaClientes, int cantAsistencias) {
    Asistencia* auxAsistencias = AsistenciaClientes, *ultimo = AsistenciaClientes + cantAsistencias - 1;
    while (true) {
        for (u_int i = 0; i < auxAsistencias->cantInscriptos - 1; i++) {
            for (u_int j = i; j < auxAsistencias->cantInscriptos; j++) {
                if (auxAsistencias->CursosInscriptos[i].idClase == auxAsistencias->CursosInscriptos[j].idClase && auxAsistencias->CursosInscriptos[i].idClase != 0) {
                    auxAsistencias->CursosInscriptos[j].idClase = 0;
                    auxAsistencias->CursosInscriptos[j].fechaInscripcion = 0;
                    auxAsistencias->cantInscriptos--;
                }
            }
        }
        if (auxAsistencias == ultimo)
            break;
        auxAsistencias++;
    }

    return;
}

void ordenarlasclaseseliminadasalfinal(Asistencia* AsistenciaClientes, int cantAsistencias) {
    Asistencia* auxAsistencias = AsistenciaClientes, *ultimo = AsistenciaClientes + cantAsistencias - 1;
    Inscripcion aux;
    eErroresAsistencias eAsist2;

    while (true) {
        for (u_int i = 0; i < auxAsistencias->cantInscriptos - 1; i++) {
            int Contcambios = 0;
            for (u_int j = 0; j < auxAsistencias->cantInscriptos - 1; j++) {
                if (auxAsistencias->CursosInscriptos[j].idClase < auxAsistencias->CursosInscriptos[j + 1].idClase) {
                    aux = auxAsistencias->CursosInscriptos[j];
                    auxAsistencias->CursosInscriptos[j] = auxAsistencias->CursosInscriptos[j + 1];
                    auxAsistencias->CursosInscriptos[j + 1] = aux;
                    Contcambios++;
                }
            }
            if (Contcambios == 0)
                break;
        }
        auxAsistencias->CursosInscriptos = resizeInscripcion(auxAsistencias, auxAsistencias->cantInscriptos, auxAsistencias->cantInscriptos, eAsist2);
        if (auxAsistencias == ultimo)
            break;
        auxAsistencias++;
    }

    return;
}


eErroresClientes FiltroDeCliente(ClientesGYM *Clientes, u_int idCliente, u_int cantClientes) {
    ClientesGYM cliente;
    int error;

    error = BuscarIdCliente(Clientes, idCliente, cantClientes, cliente);
    if (error == ExitoCliente) {
        for (unsigned long long i = 0; i < cliente.nombre.length(); i++) {
            if (!((cliente.nombre[i] >= 65 && cliente.nombre[i] <= 90) || (cliente.nombre[i] >= 97 && cliente.nombre[i] <= 127))) {
                return ErrNombre;
            }
        }

        for (unsigned long long i = 0; i < cliente.apellido.length(); i++) {
            if (!((cliente.apellido[i] >= 65 && cliente.apellido[i] <= 90) || (cliente.apellido[i] >= 97 && cliente.apellido[i] <= 127))) {
                return ErrApellido;
            }
        }

        for (unsigned long long i = 0; i < cliente.telefono.length(); i++) {
            if (!((cliente.telefono[i] >= 48 && cliente.telefono[i] <= 57) || (cliente.telefono[i] == 45))) {
                return ErrTelefono;
            }
        }

        if (cliente.estado < 0)
            return ErrEstado;

        int dia, mes, año, edad = 0;
        char delimiter = '-';
        string auxdia, auxmes, auxaño;
        stringstream ss;
        ss << cliente.fechanacimiento;
        getline(ss, auxdia, delimiter);
        dia = stoi(auxdia);
        getline(ss, auxmes, delimiter);
        mes = stoi(auxmes);
        getline(ss, auxaño, delimiter);
        año = stoi(auxaño);

        time_t rawtime;
        tm fechanacimiento;
        tm *timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        fechanacimiento.tm_mday = dia;
        fechanacimiento.tm_mon = (mes - 1);
        fechanacimiento.tm_year = (año - 1900);

        edad = timeinfo->tm_year - fechanacimiento.tm_year;

        if (fechanacimiento.tm_mon < timeinfo->tm_mon || (fechanacimiento.tm_mon == timeinfo->tm_mon && fechanacimiento.tm_mday < timeinfo->tm_mday))
            edad--;

        if (edad < 18)
            return ErrMuyJoven;
        else if (edad > 100)
            return ErrMuyViejo;

        return ExitoCliente;
    } else
        return ErrIdClienteinx;
}

eErroresDia FiltroFecha() {
    time_t rawtime;
    tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    if (timeinfo->tm_wday == 6)
        return ErrDia;

    return ExitoDia;
}

eErroresClases FiltroDeClase(ClasesGym *Clases, u_int idCliente, u_int idClase, Asistencia *&AsistenciaClientes, u_int cantclases, u_int &CantAsistencias) {
    ClasesGym clase;
    eErroresClases error1, error3;
    eErroresAsistencias error2, error4;
    Asistencia AsistenciaCliente;

    error1 = BuscarIdClase(Clases, idClase, cantclases, clase);

    if (error1 == ExitoClase) {

        if (clase.cuposActuales == clase.cuposMax)
            return ErrCupos;

        error2 = BuscarAsistenicaCliente(idClase, idCliente, AsistenciaClientes, AsistenciaCliente, CantAsistencias);

        if (error2 == ExitoAsistencias) {

            if (BuscarIdClaseEnInscripciones(AsistenciaCliente, idClase) == ErrClaseRepetida)
                return ErrClaseRepetida;

            else {
                error3 = CompararClaseInscripciones(clase, AsistenciaCliente, Clases, cantclases);
                if (error3 == ExitoClase) {

                    BuscarIdClase(Clases, idClase, cantclases);

                    error4 = BuscarAsistenicaCliente(idClase, idCliente, AsistenciaClientes);

                    if (error4 == ExitoAsistencias)
                        return ExitoClase;
                    else
                        return ErrEspacioCrearAsistencia;
                } else
                    return error3;
            }
        } else if (error2 == ExitoCrearAsistencias) {
            BuscarIdClase(Clases, idClase, cantclases);
            return ExitoClase;
        } else
            return ErrEspacioCrearAsistencia;
    } else
        return error1;
}
