#include "archivos.h"
#include "archivos.cpp"
#include "libreria.h"


int main() {
    unsigned int tamC = 0, tamU= 0, cantAsistencias = 0;
    int  auxErr = 1, cantAsistBin;

    clases *clases;
    usuario *usuarios;
    Asistencia *asistUsuarios;
    Asistencia *asistBin;

    srand(static_cast<unsigned int>(time(nullptr)));
    time_t t = time(0);
    tm* fecha_hora = localtime(&t);
    fecha_hora->tm_hour = 0;
    fecha_hora->tm_min = 0;
    fecha_hora->tm_sec = 0;

    string aux;
    time_t timestamp = mktime(fecha_hora);
    aux = to_string(timestamp);

    ifstream archivoUsuarios("../iriClientesGYM.csv");
    auxErr = leerArchivoUsuario(archivoUsuarios, usuarios, tamU);
    archivoUsuarios.close();
    if(auxErr == 0){
        cout << "Error abriendo archivo USUARIOS" << endl;
        return 0;
    }

    ifstream archivoClases("../iriClasesGYM.csv");
    auxErr = leerArchivoClases(archivoClases, clases, tamC);
    archivoClases.close();
    if(auxErr == 0){
        cout << "Error abriendo archivo CLASES" << endl;;
        return 0;
    }

    ofstream archivobin("asistencias_" + aux + ".dat", ios :: binary);
    auxErr = EscribirArchivoBinario(archivobin, asistUsuarios, cantAsistencias);
    archivobin.close();
    if(auxErr == 0){
        cout << "Error escribiendo BINARIO" <<endl;
        return 0;
    }

    delete[] clases;
    delete[] usuarios;


    ifstream archivobinleer("../asistencias_1697673600000.dat", ios::binary);

    archivobinleer.seekg(0, ios::end);
    streampos fileSize = archivobinleer.tellg();
    archivobinleer.seekg(0, ios::beg);
    cantAsistBin = static_cast<u_int>(fileSize / ((sizeof(Asistencia)) + sizeof(Inscripcion)))-1;

    asistBin = new Asistencia[cantAsistBin];

    auxErr = LeerArchivoBinario(archivobinleer, asistBin);
    archivobinleer.close();

    if(auxErr == 0){
        cout << "Error abriendo archivo BINARIO" << endl;
        return 0;
    }

    return 0;
}
