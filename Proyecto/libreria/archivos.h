#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include "libreria.h"

enum errArchivo { errArchivoLeer = -1,  exitoArchivoLeer = 1 };

int leerArchivo(std::ifstream archivo);
void incrementarClases(clase* &clases, unsigned int &tam);

#endif // ARCHIVOS_H
