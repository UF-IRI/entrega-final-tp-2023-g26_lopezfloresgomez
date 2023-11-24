/*
#include <libreria.h>
Asistencia* resizeClientes(Asistencia *Asistencias, u_int tamA, u_int nuevoTam,eAsistencia &eAsist){

    Asistencia* aux = new Asistencia[nuevoTam];

    u_int longitud = (tamA <  nuevoTam) ? tamA : nuevoTam;//Calcula la longitud que se va a copiar desde el arreglo original al nuevo. Si el tamaño actual tamA es menor que el nuevo tamaño nuevoTam, entonces longitud será igual a tamA; de lo contrario, será igual a nuevoTam.
    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = Asistencias[i];//copia asistencia en aux
         eAsist = ExitoAsistencias;
        return aux;
    }
     eAsist = ErrEspacio;
    return nullptr;
} //En resumen, esta función redimensiona dinámicamente un arreglo copiando los elementos desde el arreglo original al nuevo arreglo de acuerdo con el nuevo tamaño especificado. La función devuelve el puntero al nuevo arreglo, o nullptr si la asignación de memoria no fue exitosa.

Inscripcion* resizeInscripcion(Asistencia* Asistencias, u_int cantI, u_int nuevoTam,eAsistencia &eAsist2){

    Inscripcion* aux = new Inscripcion[nuevoTam];

    u_int longitud = (cantI <  nuevoTam) ? cantI : nuevoTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = Asistencias->CursosInscriptos[i];
         eAsist2 = ExitoAsistencias;
        return aux;
    }
    eAsist2 = ErrEspacio;
    return nullptr;
}




eClase BuscarIdCliente(usuario *usuarios, u_int idCliente, u_int tamU, usuario &cliente)
{
    usuario *aux = usuarios, *ultimo = (usuarios) + tamU - 1;
    while(true) {
        if (aux->idCliente == idCliente ){
            cliente = *aux;
            return eClase :: ExitoClase; ;//Exito Cliente //correspondencia
        }
        if (aux == ultimo)// apunta a lo ultimo
            break;
        aux++;
    }
    return  eCliente :: ErrIdClienteinx;//Error id Cliente
}

eClase BuscarIdClase(clase *Clases, u_int idClas, u_int tamC, clase &clases)
{
    clase *aux = Clases, *ultimo = (Clases) + tamC - 1;
    while(true) {
        if (aux->idClas == idClas )
        {
            clases = *aux;
            return eClase :: ExitoClase; // exito id clase
        }
        if (aux == ultimo)
            break;
        aux++;
    }//recorro todo y veo si el id clase es correcto
    return eClase :: ErrIdClaseinx  ; // error id clase
}
eClase BuscarIdClase(clase *Clases, u_int idClas, u_int tamC)
{
    clase *aux = Clases, *ultimo = (Clases) + tamC - 1;
    while(true) {
        if (aux->idClas == idClas ){
            aux->cupo++;
            return eClase :: ExitoClase;
        }
        if (aux == ultimo)
            break;
        aux++;
    }
    return eClase :: ErrIdClaseinx;
}
eClase BuscarIdClaseEnInscripciones(Asistencia AsistenciaUser, unsigned int idClas){

   unsigned int i=0;

    while(true) {
        if (AsistenciaUser.CursosInscriptos->idCurso == idClas ){
            return eClase :: ErrClaseRepetida;
        }
        if ( AsistenciaUser.cantInscriptos == i)
            break;
        i++;
    }
    return eClase :: ExitoClase;;
}
 eAsistencia BuscarAsisCliente(u_int idClas, u_int idCliente,  Asistencia *&Asistencias, Asistencia &AsistenciaCliente, u_int &tamA)
{
    eAsistencia eAsist;
    eAsistencia eAsist2;
    if(tamA == 0){
        Asistencias = resizeClientes(Asistencias, tamA, tamA+1, eAsist);

        if(eAsist == ExitoAsistencias){
            Asistencias[tamA].idCliente = idCliente;
            Asistencias[tamA].cantInscriptos = 1;
            Asistencia *aux = Asistencias;
            Asistencias[tamA].CursosInscriptos = resizeInscripcion(aux, 0, 1, eAsist2);
            Asistencias[tamA].CursosInscriptos->idCurso = idClas;
            Asistencias[tamA].CursosInscriptos->fechaInscripcion = time(0);
            AsistenciaCliente = Asistencias[tamA];
            tamA++;
            return eAsistencia :: ExitoCrearAsistencias;
        }
        else
            return eAsistencia :: ErrEspacio;
    }

    else{
        Asistencia *aux = Asistencias, *ultimo = (Asistencias) + tamA - 1;

        while(true) {

            if (aux->idCliente == idCliente ){
                AsistenciaCliente = *aux;
                return eAsistencia :: ExitoAsistencias;
            }

            if (aux == ultimo){
                Asistencias = resizeClientes(Asistencias, tamA,tamA+1, eAsist);

                if(eAsist == ExitoAsistencias){
                    Asistencias[tamA].idCliente = idCliente;
                    Asistencias[tamA].cantInscriptos = 1;
                    Asistencia *aux = Asistencias;
                    Asistencias[tamA].CursosInscriptos = resizeInscripcion(aux, 0, 1, eAsist2);
                    Asistencias[tamA].CursosInscriptos->idCurso = idClas;
                    Asistencias[tamA].CursosInscriptos->fechaInscripcion = time(0);
                    AsistenciaCliente = Asistencias[tamA];
                    tamA ++;
                    return eAsistencia :: ExitoCrearAsistencias;
                }

                else
                    return eAsistencia :: ErrEspacio;
            }

            aux++;
        }
    }

    return eAsistencia :: ExitoAsistencias ;
}

    eAsistencia BuscarAsisClienteCliente(u_int idClas, u_int idCliente,  Asistencia *&Asistencias)
    {
        Asistencia *aux = Asistencias;
        eAsistencia eAsist2;

        while(true) {

            if (aux->idCliente == idCliente){
                aux->CursosInscriptos = resizeInscripcion(aux, aux->cantInscriptos, aux->cantInscriptos+1, eAsist2);
                if(eAsist2 == eAsistencia :: ExitoAsistencias){
                    aux->cantInscriptos++;
                    aux->CursosInscriptos[(aux->cantInscriptos)-1].idCurso = idClas;
                    aux->CursosInscriptos[(aux->cantInscriptos)-1].fechaInscripcion = time(0);
                    return eAsistencia :: ExitoAsistencias;
                }
                else
                    return eAsistencia :: ErrEspacio;
            }

            aux++;
        }
    }

    eClase BuscarIdClaseEnInscripciones(Asistencia AsistenciaCliente, u_int idClas){

        u_int cont = 0;

        while(true) {
            if (AsistenciaCliente.CursosInscriptos->idCurso == idClas ){
                return eClase :: ErrClaseRepetida;
            }
            if ( AsistenciaCliente.cantInscriptos == cont)
                break;
            cont++;
        }
        return eClase :: ExitoClase;
    }



eCliente FiltroDeCliente(usuario *usuarios, u_int idCliente, u_int &tamC)
{
    usuario cliente;
    int error;


    error = BuscarIdCliente(usuarios, idCliente, tamC, cliente);
    if(error == 1){
        for(unsigned long long i = 0; i<cliente.nombre.length(); i++)
        {
            if(!(((cliente.nombre[i] >= 65 && cliente.nombre[i] <= 90) || (cliente.nombre[i] >= 97 && cliente.nombre[i] <= 127)))) //|| (cliente.nombre[i] >= 160 && cliente.nombre[i] <= 165) || (cliente.nombre[i] == 130)))
                return eCliente::ErrNombre;
        }

        for(unsigned long long i = 0; i<cliente.apellido.length(); i++)
        {
            if(!(((cliente.apellido[i] >= 65 && cliente.apellido[i] <= 90) || (cliente.apellido[i] >= 97 && cliente.apellido[i] <= 127)))) //|| (cliente.nombre[i] >= 160 && cliente.nombre[i] <= 165) || (cliente.nombre[i] == 130)))
                return eCliente::ErrApellido;
        }

        for(unsigned long long i = 0; i<cliente.telefono.length(); i++)
        {
            if(!((cliente.telefono[i] >= 48 && cliente.telefono[i] <= 57) || (cliente.telefono[i] == 45)))
                return eCliente::ErrTelefono;
        }

        if(cliente.estado < 0)
            return eCliente::ErrEstado;

        int dia, mes, año, edad = 0;
        char delimiter = '-';
        string auxdia, auxmes, auxaño;
        stringstream ss;
        ss << cliente.fechaNac;
        getline(ss,auxdia,delimiter);
        dia = stoi(auxdia);
        getline(ss,auxmes,delimiter);
        mes = stoi(auxmes);
        getline(ss,auxaño,delimiter);
        año = stoi(auxaño);

        time_t rawtime;
        tm fechanacimiento;
        tm * timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        fechanacimiento.tm_mday = dia;
        fechanacimiento.tm_mon = (mes-1);
        fechanacimiento.tm_year = (año-1900);

        edad = timeinfo->tm_year - fechanacimiento.tm_year;

        if(fechanacimiento.tm_mon < timeinfo->tm_mon || (fechanacimiento.tm_mon == timeinfo->tm_mon && fechanacimiento.tm_mday < timeinfo->tm_mday))
            edad--;

        if(edad<18)
            return eCliente :: ErrMuyJoven;
        else if(edad>100)
            return eCliente :: ErrMuyViejo;

        return eCliente ::ExitoCliente;
    }
    else
        return eCliente :: ErrIdClienteinx;
}
eDia FiltroFecha() {

    time_t rawtime;//tiempo real
    tm * timeinfo;//se utiliza para almacenar informacion del tiempo desglozado

    time(&rawtime);//tiempo actual almacenado en raw time
    timeinfo = localtime(&rawtime);//se desgloza la representacion del tiempo

    if(timeinfo->tm_wday == 6)//igual a sabado
        return eDia :: ErrDia;

    return eDia :: ExitoDia;
}
eClase FiltroDeClase(clase *Clases, u_int idCliente, u_int idClase, Asistencia *&Asistencias, u_int &tamC, u_int &tamA)
{
    clase Clase;
    eClase error1, error3; //errorres relacionados con la clase
    eAsistencia error2, error4; //errores relacionados con la asistencia
    Asistencia AsistenciaCliente;

    error1 = BuscarIdClase(Clase, idClase, tamC, Clases);//clase correspondiente al id de clase

    if(error1 == eClase ::ExitoClase) //igual a 1
    {

        if(Clases->cupo == Clases->cupoMax)//limite maximo
            return eClase :: ErrCupos;// -2

        error2 = BuscarAsistenicaCliente(idClase, idCliente, Asistencias, AsistenciaCliente, tamA);//se busca asistencia del cliente en la clase especifica

        if(error2 == eAsistencia :: ExitoAsistencias)//1 asiste
        {

            if(BuscarIdClaseEnInscripciones(AsistenciaCliente, idClase) == eClase :: ErrClaseRepetida)//-4 se verifica si cliente ya esta inscripto
                return eClase :: ErrClaseRepetida;//-4

            else {
                error3 = CompararClaseInscripciones(Clase, AsistenciaCliente, Clases, tamC);//conflictos de horarios
                if(error3 == eClase :: ExitoClase)//1
                {

                    BuscarIdClase( Clases, idClase, tamC);

                    error4 = BuscarAsistenicaCliente(idClase, idCliente, Asistencias);//asistencia del cliente clase especifica

                    if(error4 == eAsistencia :: ExitoAsistencias)
                        return eClase :: ExitoClase;//1

                    else
                        return eClase :: ErrEspacioCrearAsistencia;//-5
                }

                else
                    return error3;
            }
        }

        else if(error2 == eAsistencia :: ExitoCrearAsistencias)//2
        {
            BuscarIdClase( Clases, idClase, tamC);
            return eClase :: ExitoClase;//1
        }

        else
            return eClase :: ErrEspacioCrearAsistencia;//-5
    }
    else
        return error1;
}

void eliminarclaserepetida(Asistencia* asistencias, int tamA)
{

    Asistencia *auxasistencias = asistencias, *ultimo = asistencias + tamA - 1; //recorrer el arreglo
    while(true){
        for(u_int i=0; i < auxasistencias->cantInscriptos-1; i++){
            for(u_int j=i; j < auxasistencias->cantInscriptos; j++){

                if(auxasistencias->CursosInscriptos[i].idCurso == auxasistencias->CursosInscriptos[j].idCurso && auxasistencias->CursosInscriptos[i].idCurso != 0 ){
                    auxasistencias->CursosInscriptos[j].idCurso = 0;
                    auxasistencias->CursosInscriptos[j].fechaInscripcion = 0;
                    auxasistencias->cantInscriptos--;
                }

            }

        }
        if (auxasistencias == ultimo)
            break;
        auxasistencias++;

    }

    return;
}
void ordenarclasesinscriptas(Asistencia* asistencias, size_t tamA) { //ordena segun la fecha de inscripcion

    Asistencia *auxasistencias = asistencias;
    Asistencia *ultimo = asistencias + tamA - 1;
    Inscripcion aux;

    while (auxasistencias <= ultimo) {
        if (auxasistencias->cantInscriptos > 0) {
            for (u_int i = 0; i < auxasistencias->cantInscriptos - 1; i++) {
                int Contcambios = 0;

                for (u_int j = 0; j < auxasistencias->cantInscriptos - 1; j++) {
                    if (auxasistencias->CursosInscriptos[j].fechaInscripcion >
                        auxasistencias->CursosInscriptos[j + 1].fechaInscripcion) {
                        aux = auxasistencias->CursosInscriptos[j];
                        auxasistencias->CursosInscriptos[j] = auxasistencias->CursosInscriptos[j + 1];
                        auxasistencias->CursosInscriptos[j + 1] = aux;
                        Contcambios++;
                    }
                }

                if (Contcambios == 0)
                    break;
            }
        }

        auxasistencias++;

        // Si has llegado al final del arreglo, salir del bucle
        if (auxasistencias > ultimo)
            break;
    }

    return;
}
void ordenarlasclaseseliminadasalfinal(Asistencia* asistencias, int tamA){//clase duplicada se elimina

    Asistencia *auxasistencias = asistencias, *ultimo = asistencias + tamA - 1; //recorremos el arreglo
    Inscripcion aux;//intercambios para ordenar
    eAsistencia eAsist2;
    while(true){
        for(u_int i=0; i < auxasistencias->cantInscriptos-1; i++){
            int Contcambios=0;
            for(u_int j=0; j < auxasistencias->cantInscriptos-1; j++){

                if(auxasistencias->CursosInscriptos[j].idCurso < auxasistencias->CursosInscriptos[j+1].idCurso ){

                    aux = auxasistencias->CursosInscriptos[j];
                    auxasistencias->CursosInscriptos[j] = auxasistencias->CursosInscriptos[j+1];
                    auxasistencias->CursosInscriptos[j+1] = aux;
                    Contcambios++;
                }
            }
            if(Contcambios==0)
                break;
        }
        auxasistencias->CursosInscriptos = resizeInscripcion(auxasistencias,  auxasistencias->cantInscriptos, auxasistencias->cantInscriptos,eAsist2);
        if (auxasistencias == ultimo)
            break;
        auxasistencias++;
    }
//esta función ordena las inscripciones de clases en una estructura Asistencia  y ajusta el tamaño del arreglo al número actual de inscripciones después de cada iteración. La condición de parada es cuando no se realizan cambios durante una iteración completa del bucle interno.

    return;

}
eClase CompararClaseInscripciones(Asistencia* Asistencias, clase *Clases, u_int tamC, int tamA)// el enum
{
    u_int i, j;
    clase clase1, clase2;
    Asistencia *auxasistencias = Asistencias, *ultimo = Asistencias + tamA - 1;
    while(true){
        for(i=0; i<auxasistencias->cantInscriptos; i++) {
            for(j=i+1; j<auxasistencias->cantInscriptos; j++){
                if(auxasistencias->CursosInscriptos[i].idCurso != 0 || auxasistencias->CursosInscriptos[j].idCurso != 0){
                    BuscarIdClase(Clases, auxasistencias->CursosInscriptos[i].idCurso, tamC, clase1);
                    BuscarIdClase(Clases, auxasistencias->CursosInscriptos[j].idCurso, tamC, clase2);
                    if(((clase1.horario-clase2.horario)<1 && (clase1.horario-clase2.horario)>-1) || ((clase1.nombreClas == "Musculacion" && clase2.nombreClas == "Musculacion") && ((clase1.horario-clase2.horario) < 0.7 && (clase1.horario-clase2.horario) > -0.7))){
                        auxasistencias->CursosInscriptos[j].idCurso = 0;
                        auxasistencias->CursosInscriptos[j].fechaInscripcion = 0;// que no se inscriba dos veces al mismo horario misma clase
                        auxasistencias->cantInscriptos--;// una inscripcion menos
                    }
                }
            }
        }
        if (auxasistencias == ultimo)
            break;
        auxasistencias++;
    }

    return eClase :: ExitoClase; // igual a 1 true
}

*/
