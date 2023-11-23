#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "libreria.h"


int leerArchivoClases(ifstream &archivo, clase* &clases, unsigned int &tamC);
int leerArchivoUsuario(ifstream &archivo, usuario* & usuarios, unsigned int &tamU);
void incrementarClases(clase* &clases, unsigned int &tam);
void incrementarUsuarios(usuario *& usuarios, unsigned int &tam);

int EscribirArchivoBinario(ofstream &archivo, Asistencia *&asistClientes, unsigned int &cantAsistencias);



#endif // ARCHIVOS_H
