#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>


enum errArchivo { errArchivoLeer = -1,  exitoArchivoLeer = 1 };

int leerArchivo(std::ifstream archivo);


#endif // ARCHIVOS_H
