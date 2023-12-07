#include "archivos.h"
//agregar longitud por derecha
eArchivos leerArchivoClientes(ifstream &infileClientes, ClientesGYM *&Clientes, u_int &cantClientes){

    int i = 0;

    if (!infileClientes.is_open()) {

        return eArchivos :: ErrorApertura;
    }

    string header;
    getline(infileClientes, header);

    string line;
    char delimiter = ',';

    while(getline(infileClientes, line))
        cantClientes++;

    infileClientes.clear();
    infileClientes.seekg(0, std::ios::beg);

    Clientes = new ClientesGYM[cantClientes];

    getline(infileClientes, header);
    string auxidCliente, auxnombre, auxapellido, auxemail, auxtelefono, auxfechanacimiento, auxestado;
    stringstream ss;
    while(!infileClientes.eof() && getline(infileClientes, line)) {
        ss.clear();
        ss<<line;
        getline(ss,auxidCliente,delimiter);
        (Clientes[i]).idCliente = stoi(auxidCliente);

        getline(ss,auxnombre,delimiter);
        (Clientes[i]).nombre = auxnombre;

        getline(ss,auxapellido,delimiter);
        (Clientes[i]).apellido = auxapellido;

        getline(ss,auxemail,delimiter);
        (Clientes[i]).email = auxemail;

        getline(ss,auxtelefono,delimiter);
        (Clientes[i]).telefono = auxtelefono;

        getline(ss,auxfechanacimiento,delimiter);
        (Clientes[i]).fechanacimiento = auxfechanacimiento;

        getline(ss,auxestado,delimiter);
        (Clientes[i]).estado = stoi(auxestado);

        i++;
    }

    return eArchivos :: ExitoOperacion;
}

eArchivos leerArchivoClases(ifstream &infileClases, ClasesGym *&Clases, u_int &cantClases){

    int i = 0;

    if (!infileClases.is_open()) {

        return eArchivos :: ErrorApertura;
    }

    string header;
    getline(infileClases, header);

    string line;
    char delimiter = ',';

    while(getline(infileClases, line))
        cantClases++;

    infileClases.clear();
    infileClases.seekg(0, std::ios::beg);

    Clases = new ClasesGym[cantClases];

    getline(infileClases, header);
    string auxidClase, auxnombre, auxhorario;
    stringstream ss;
    while(!infileClases.eof() && getline(infileClases, line)) {
        ss.clear();
        ss<<line;
        getline(ss,auxidClase,delimiter);
        (Clases[i]).idClase = stoi(auxidClase);

        getline(ss,auxnombre,delimiter);
        (Clases[i]).nombre = auxnombre;

        getline(ss,auxhorario,delimiter);
        (Clases[i]).horario = stof(auxhorario);

        if(stoi(auxidClase)>0 && stoi(auxidClase)<6){
            (Clases[i]).cuposMax=45;
            (Clases[i]).cuposActuales=0;
        }
        else if(stoi(auxidClase)>5 && stoi(auxidClase)<12){
            (Clases[i]).cuposMax=25;
            (Clases[i]).cuposActuales=0;
        }
        else if(stoi(auxidClase)>11 && stoi(auxidClase)<18){
            (Clases[i]).cuposMax=15;
            (Clases[i]).cuposActuales=0;
        }
        else if(stoi(auxidClase)>17 && stoi(auxidClase)<24){
            (Clases[i]).cuposMax=40;
            (Clases[i]).cuposActuales=0;
        }
        else if(stoi(auxidClase)>23 && stoi(auxidClase)<30){
            (Clases[i]).cuposMax=50;
            (Clases[i]).cuposActuales=0;
        }
        else if(stoi(auxidClase)>29 && stoi(auxidClase)<34){
            (Clases[i]).cuposMax=30;
            (Clases[i]).cuposActuales=0;
        }
        else if(stoi(auxidClase)>33 && stoi(auxidClase)<61){
            (Clases[i]).cuposMax=30;
            (Clases[i]).cuposActuales=0;
        }

        i++;
    }

    return eArchivos::ExitoOperacion;
}

eArchivos LeerArchivoBinario(ifstream &archivobinlee, Asistencia *asistencias){

    if (!archivobinlee.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return eArchivos::ErrorApertura;
    }


    if (!archivobinlee.is_open()){
        delete [] asistencias;
        return eArchivos :: ErrorApertura;
    }


    archivobinlee.clear();
    archivobinlee.seekg(0);

    Asistencia *aux = asistencias;

    while (!archivobinlee.eof()) {
        archivobinlee.read((char *)&aux->idCliente, sizeof(u_int));
        archivobinlee.read((char *)&aux->cantInscriptos, sizeof(u_int));

        Inscripcion *registered = new Inscripcion[aux->cantInscriptos];
        Inscripcion *auxInscriptions = registered;
        for (u_int i = 0; i < aux->cantInscriptos; i++) {
            archivobinlee.read((char *)auxInscriptions, sizeof(Inscripcion));
            auxInscriptions++;
        }
        aux->CursosInscriptos = registered;

        aux++;
    }


    return eArchivos::ExitoOperacion;
}


eArchivos EscribirArchivoBinario(ofstream &archivobin, Asistencia *&AsistenciaClientes, u_int &cantAsistencias){

    if (archivobin.is_open()) {
        for (u_int i=0; i<cantAsistencias; i++) {
            archivobin.write((char*)&AsistenciaClientes[i].idCliente, sizeof(u_int));
            archivobin.write((char*)&AsistenciaClientes[i].cantInscriptos, sizeof(u_int));
            for(u_int j = 0; j < AsistenciaClientes[i].cantInscriptos; j++) {
                archivobin.write((char*)&AsistenciaClientes[i].CursosInscriptos[j], sizeof(Inscripcion));
            }
        }

        return eArchivos :: ExitoOperacion;

    }

    return eArchivos :: ErrorApertura;
}
