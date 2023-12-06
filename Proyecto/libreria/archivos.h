#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "libreria.h"

//Declaro errores
enum files {errOpen= -2, errWriting = -1, success = 1};
typedef enum files;

//Declaro Funciones
files readFileClients(ifstream &fileUsers, usersGYM *&users, u_int &cantU);
files readFileClasses(ifstream &fileClasses, classGYM *&classes, u_int &cantC);
files readFileBinary(ifstream &fileBinRead, Asistencia *assist);
files writeFileBinary(ofstream &fileBin, Asistencia *&clientAssist, u_int &cantA);




#endif // ARCHIVOS_H
