#include <archivos.h>
#include <libreria.h>

// Agregar longitud por derecha
eErroresArchivos leerArchivoClientes(ifstream &archivoClientes, ClientesGYM *&clientes, u_int &cantClientes){

    int i = 0;

    if (!archivoClientes.is_open()) {

        return eErroresArchivos::ErrorApertura;
    }

    string header;
    getline(archivoClientes, header);

    string line;
    char delimiter = ',';

    while(getline(archivoClientes, line))
        cantClientes++;

    archivoClientes.clear();
    archivoClientes.seekg(0, std::ios::beg);

    clientes = new ClientesGYM[cantClientes];

    getline(archivoClientes, header);
    string auxidCliente, auxnombre, auxapellido, auxemail, auxtelefono, auxfechanacimiento, auxestado;
    stringstream ss;
    while(!archivoClientes.eof() && getline(archivoClientes, line)) {
        ss.clear();
        ss << line;
        getline(ss, auxidCliente, delimiter);
        (clientes[i]).idCliente = stoi(auxidCliente);

        getline(ss, auxnombre, delimiter);
        (clientes[i]).nombre = auxnombre;

        getline(ss, auxapellido, delimiter);
        (clientes[i]).apellido = auxapellido;

        getline(ss, auxemail, delimiter);
        (clientes[i]).email = auxemail;

        getline(ss, auxtelefono, delimiter);
        (clientes[i]).telefono = auxtelefono;

        getline(ss, auxfechanacimiento, delimiter);
        (clientes[i]).fechanacimiento = auxfechanacimiento;

        getline(ss, auxestado, delimiter);
        (clientes[i]).estado = stoi(auxestado);

        i++;
    }

    return eErroresArchivos::ExitoOperacion;
}

eErroresArchivos leerArchivoClases(ifstream &archivoClases, ClasesGym *&clases, u_int &cantClases){

    int i = 0;

    if (!archivoClases.is_open()) {

        return eErroresArchivos::ErrorApertura;
    }

    string header;
    getline(archivoClases, header);

    string line;
    char delimiter = ',';

    while(getline(archivoClases, line))
        cantClases++;

    archivoClases.clear();
    archivoClases.seekg(0, std::ios::beg);

    clases = new ClasesGym[cantClases];

    getline(archivoClases, header);
    string auxidClase, auxnombre, auxhorario;
    stringstream ss;
    while(!archivoClases.eof() && getline(archivoClases, line)) {
        ss.clear();
        ss << line;
        getline(ss, auxidClase, delimiter);
        (clases[i]).idClase = stoi(auxidClase);

        getline(ss, auxnombre, delimiter);
        (clases[i]).nombre = auxnombre;

        getline(ss, auxhorario, delimiter);
        (clases[i]).horario = stof(auxhorario);

        if(stoi(auxidClase)>0 && stoi(auxidClase)<6){
            (clases[i]).cuposMax = 45;
            (clases[i]).cuposActuales = 0;
        }
        else if(stoi(auxidClase)>5 && stoi(auxidClase)<12){
            (clases[i]).cuposMax = 25;
            (clases[i]).cuposActuales = 0;
        }
        else if(stoi(auxidClase)>11 && stoi(auxidClase)<18){
            (clases[i]).cuposMax = 15;
            (clases[i]).cuposActuales = 0;
        }
        else if(stoi(auxidClase)>17 && stoi(auxidClase)<24){
            (clases[i]).cuposMax = 40;
            (clases[i]).cuposActuales = 0;
        }
        else if(stoi(auxidClase)>23 && stoi(auxidClase)<30){
            (clases[i]).cuposMax = 50;
            (clases[i]).cuposActuales = 0;
        }
        else if(stoi(auxidClase)>29 && stoi(auxidClase)<34){
            (clases[i]).cuposMax = 30;
            (clases[i]).cuposActuales = 0;
        }
        else if(stoi(auxidClase)>33 && stoi(auxidClase)<61){
            (clases[i]).cuposMax = 30;
            (clases[i]).cuposActuales = 0;
        }

        i++;
    }

    return eErroresArchivos::ExitoOperacion;
}

eErroresArchivos LeerArchivoBinario(ifstream &archivobinlee, Asistencia *asistencias){

    if (!archivobinlee.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return eErroresArchivos::ErrorApertura;
    }

    if (!archivobinlee.is_open()){
        delete [] asistencias;
        return eErroresArchivos::ErrorApertura;
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

    return eErroresArchivos::ExitoOperacion;
}

eErroresArchivos EscribirArchivoBinario(ofstream &archivobin, Asistencia *&asistenciaClientes, u_int &cantAsistencias){

    if (archivobin.is_open()) {
        for (u_int i=0; i<cantAsistencias; i++) {
            archivobin.write((char*)&asistenciaClientes[i].idCliente, sizeof(u_int));
            archivobin.write((char*)&asistenciaClientes[i].cantInscriptos, sizeof(u_int));
            for(u_int j = 0; j < asistenciaClientes[i].cantInscriptos; j++) {
                archivobin.write((char*)&asistenciaClientes[i].CursosInscriptos[j], sizeof(Inscripcion));
            }
        }

        return eErroresArchivos::ExitoOperacion;
    }

    return eErroresArchivos::ErrorApertura;
}
