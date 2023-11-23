#include "archivos.h"

int leerArchivoUsuario(ifstream &archivo, usuario *&usuarios, unsigned int &tamU)
{
    if(!archivo.is_open())
        return -1;

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
    archivo.seekg(0, std::ios::beg); // pone el puntero al principio

    usuarios = new usuario[tamU];

    getline(archivo, header);

    while(!archivo.eof() && getline(archivo, line)) {
        iss.clear();
        iss<<line;
        elemento.clear();
        getline(iss,elemento,delimiter);
        usuarios[i].idCliente = stoi(elemento);
        getline(iss,usuarios[i].nombre,delimiter);
        getline(iss,usuarios[i].apellido,delimiter);
        getline(iss,usuarios[i].email,delimiter);
        getline(iss,usuarios[i].telefono,delimiter);
        getline(iss,usuarios[i].fechaNac,delimiter);
        elemento.clear();
        getline(iss,elemento,delimiter);
        usuarios[i].estado = stoi(elemento);
        i++;
    }
    return 1;
}

int leerArchivoClases(ifstream &archivo, clase *&clases, unsigned int &tamC)
{
    if(!archivo.is_open())
        return -1;

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
    }

    return 1;
}






