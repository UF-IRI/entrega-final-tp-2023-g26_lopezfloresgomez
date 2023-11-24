#include "archivos.h"

int leerArchivoUsuario(ifstream &archivo, usuario *&usuarios, unsigned int &tamU)
{
    if(!archivo.is_open()){
        return 0;
    }
    char delimiter= ',';
    int i=0;
    string line;
    string header;
    string elemento;
    stringstream iss;

    getline(archivo, header);

    while(getline(archivo, line)){ // Agarra la cantinad de clientes
        tamU++;
    }

    archivo.clear();
    archivo.seekg(0, ios::beg); // pone el puntero al principio

    usuarios = new usuario[tamU];

    getline(archivo, header);

    while(!archivo.eof() && getline(archivo, line)) {
        iss.clear();
        iss << line;

        getline(iss,elemento,delimiter);
        usuarios[i].idCliente = stoi(elemento);
        getline(iss,usuarios[i].nombre,delimiter);
        getline(iss,usuarios[i].apellido,delimiter);
        getline(iss,usuarios[i].email,delimiter);
        getline(iss,usuarios[i].telefono,delimiter);
        getline(iss,usuarios[i].fechaNac,delimiter);
        getline(iss,elemento,delimiter);
        usuarios[i].estado = stoi(elemento);
        i++;
    }
    return 1;
}

int leerArchivoClases(ifstream &archivo, clase *&clases, unsigned int &tamC)
{
    if(!archivo.is_open())
        return 0;

    char delimiter= ',';
    int i=0;
    string line;
    string header;
    string elemento;
    stringstream iss;

    getline(archivo, header);

    while(getline(archivo, line)){ // Agarra la cantinad de clientes
        tamC++;
    }

    archivo.clear();
    archivo.seekg(0, std::ios::beg); // pone el puntero al principio

    clases = new clase[tamC];
    getline(archivo, header);

    while(!archivo.eof() && getline(archivo, line)) {
        iss.clear();
        iss<<line;
        getline(iss,elemento,delimiter);
        clases[i].idClas = stoi(elemento);
        getline(iss,clases[i].nombreClas,delimiter);
        getline(iss,elemento,delimiter);
        clases[i].horario = stof(elemento);
        i++;

        if(clases[i].idClas>0 && clases[i].idClas<6){
            clases[i].cupoMax=45;
            clases[i].cupo=0;
        }
        else if(clases[i].idClas>5 && clases[i].idClas<12){
            clases[i].cupoMax=25;
            clases[i].cupo=0;
        }
        else if(clases[i].idClas >11 && clases[i].idClas<18){
            clases[i].cupoMax=15;
            clases[i].cupo=0;
        }
        else if(clases[i].idClas>17 && clases[i].idClas<24){
            clases[i].cupoMax=40;
            clases[i].cupo=0;
        }
        else if(clases[i].idClas>23 && clases[i].idClas<30){
            clases[i].cupoMax=50;
            clases[i].cupo=0;
        }
        else if(clases[i].idClas>29 && clases[i].idClas<34){
            clases[i].cupoMax=30;
            clases[i].cupo=0;
        }
        else if(clases[i].idClas>33 && clases[i].idClas<61){
            clases[i].cupoMax=30;
            clases[i].cupo=0;
        }
    }
    return 1;
}

int LeerArchivoBinario(ifstream &archivo, Asistencia *asistencias){
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 0;
    }

    archivo.clear();
    archivo.seekg(0);

    Asistencia *aux = asistencias;

    while (!archivo.eof()) {
        archivo.read((char *)&aux->idCliente, sizeof(u_int));
        archivo.read((char *)&aux->cantInscriptos, sizeof(u_int));

        Inscripcion *registered = new Inscripcion[aux->cantInscriptos];
        Inscripcion *auxInscriptions = registered;
        for (int i = 0; i < aux->cantInscriptos; i++) {
            archivo.read((char *)auxInscriptions, sizeof(Inscripcion));
            auxInscriptions++;
        }
        aux->CursosInscriptos = registered;
        aux++;
    }
    return 1;
}


int EscribirArchivoBinario(ofstream &archivo, Asistencia *&asistClientes, unsigned int &cantAsistencias){

    if (archivo.is_open()) {
        for (unsigned int i=0; i < cantAsistencias; i++) {
            archivo.write((char*)&asistClientes[i].idCliente, sizeof(unsigned int));
            archivo.write((char*)&asistClientes[i].cantInscriptos, sizeof(unsigned int));
            for(int j = 0; j < asistClientes[i].cantInscriptos; j++) {
                archivo.write((char*)&asistClientes[i].CursosInscriptos[j], sizeof(Inscripcion));
            }
        }
        return 1;
    }
    return 0;
}







