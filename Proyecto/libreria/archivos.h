#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "libreria.h"

enum errArchivo { errArchivoLeer = -1,  exitoArchivoLeer = 1 };

int leerArchivoClases(ifstream &archivo, clase* &clases, unsigned int &tamC);
int leerArchivoUsuario(ifstream &archivo, usuario* & usuarios, unsigned int &tamU);
void incrementarClases(clase* &clases, unsigned int &tam);
void incrementarUsuarios(usuario *& usuarios, unsigned int &tam);


bool leerArchivosAsistencia(ifstream & archivo,Asistencia *& Asistencias,unsigned int &tamA);




#endif // ARCHIVOS_H
