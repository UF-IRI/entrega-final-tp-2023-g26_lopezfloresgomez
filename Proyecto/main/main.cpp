#include "archivos.h"
#include "archivos.cpp"
#include "libreria.h"
#include "time.h"


int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    //Asistencia *Asistencias;
    //u_int cantAsist;
    u_int cantclases = 0, cantClientes = 0, reservas = 5000, cantAsistencias = 0, cantAsist = 0, cantasist = 154, j = 0;
    classGYM *Clases;
    usersGYM *Clientes;
    Asistencia *AsistenciaClientes, *asistencias;

    files errorArchivoClases, errorArchivoBinario, errorArchivoBinarioOUT, errorArchivoUsuarios;
    time_t t = time(0);
    tm* fecha_hora = localtime(&t);
    fecha_hora->tm_hour = 0;
    fecha_hora->tm_min = 0;
    fecha_hora->tm_sec = 0;

    string aux;
    time_t timestamp = mktime(fecha_hora);
    aux = to_string(timestamp);
    /*
files readFileUsers(ifstream &fileUsers, usersGYM *&users, u_int &cantU);
files readFileClasses(ifstream &fileClasses, classGYM *&classes, u_int &cantC);
files readFileBinary(ifstream &fileBinRead, Asistencia *assist);
files writeFileBinary(ofstream &fileBin, Asistencia *&clientAssist, u_int &cantA);

    */
    ifstream infileClases("../iriClasesGYM.csv");
    errorArchivoClases = readFileClasses(infileClases, Clases, cantclases);
    infileClases.close();
    if(errorArchivoClases == files :: errOpen){
        cout << "no se pudo abrir el archivo de clases";
        cout << endl;
        return files :: errOpen;
    }


    ifstream archivobinlee("../asistencias_1697673600000.dat", ios::binary);

    archivobinlee.seekg(0, std::ios::end);
    std::streampos fileSize = archivobinlee.tellg();
    archivobinlee.seekg(0, std::ios::beg);
    cantAsist = static_cast<u_int>(fileSize / ((sizeof(Asistencia)) + sizeof(Inscripcion)))-1;

    asistencias = new Asistencia[cantasist];

    errorArchivoBinario = readFileBinary(archivobinlee, asistencias);
    archivobinlee.close();
    if(errorArchivoBinario == files :: errOpen){
        cout<<"no se pudo abrir el archivo de asistencias";
        cout<<endl;
        delete []Clases;
        return files :: errOpen;
    }


    ifstream infileClientes("../iriClientesGYM.csv");
    errorArchivoUsuarios = readFileUsers(infileClientes, Clientes, cantClientes);
    infileClientes.close();
    if(errorArchivoUsuarios == files :: errOpen){
        cout<<"no se pudo abrir el archivo de clientes";
        cout<<endl;
        delete []Clases;
        delete []asistencias;
        return files :: errOpen;
    }

    ofstream archivobin("../asistencias_" + aux + ".dat", ios :: binary);
    errorArchivoBinarioOUT = writeFileBinary(archivobin, AsistenciaClientes, cantAsistencias);
    archivobin.close();
    if(errorArchivoBinarioOUT == files :: errOpen){
        cout<<"no se pudo abrir el archivo de escritura de asistencias";
        cout<<endl;
        return files :: errOpen;
    }

    for(u_int i = 0; i < cantasist; i++){
        delete[]asistencias[i].CursosInscriptos;
    }
    delete [] Clases;
    delete [] Clientes;
    delete [] asistencias;
    delete [] AsistenciaClientes;

    return 0;
}
