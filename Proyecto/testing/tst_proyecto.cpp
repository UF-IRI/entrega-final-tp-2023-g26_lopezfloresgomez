#include <catch2/catch.hpp>
#include "archivos.h"
#include "libreria.h"

TEST_CASE("Lectura Archivos", "[Archivos]"){
    SECTION("Archivo Usuarios"){

        unsigned int tamC;
        usuario *usuarios;
        usuario usuarioTesting;
        int errorArchivo;
        //90,Alejandro,Pacheco,AlejandroPacheco@bolandia.iri,625-718-5792,02-08-1997,-13735
        usuarioTesting.idCliente = 90;
        usuarioTesting.nombre = "Mateo";
        usuarioTesting.apellido = "Pacheco";
        usuarioTesting.email = "AlejandroPacheco@bolandia.iri";
        usuarioTesting.telefono = "625-718-5792";
        usuarioTesting.fechaNac = "02-08-1997";
        usuarioTesting.estado = -13735;

        ifstream archivo("iriClientesGYM.csv");
        //leerArchivoUsuario(ifstream &archivo, usuario* & usuarios, unsigned int &tamU);
        errorArchivo = leerArchivoUsuario(archivo, usuarios, tamC);

        REQUIRE(errorArchivo == 1);
        REQUIRE(tamC == 250);
        REQUIRE(usuarios[89].apellido == usuarioTesting.apellido);
        REQUIRE(usuarios[89].idCliente == usuarioTesting.idCliente);
        REQUIRE(usuarios[89].email == usuarioTesting.email);
        REQUIRE(usuarios[89].estado == usuarioTesting.estado);
        REQUIRE(usuarios[89].fechaNac == usuarioTesting.fechaNac);
        REQUIRE(usuarios[89].nombre == usuarioTesting.nombre);
        REQUIRE(usuarios[89].telefono == usuarioTesting.telefono);

        archivo.close();

        delete []usuarios;
    }

    SECTION("Archivo Clases") {
        unsigned int tamC;
        clases *clas, claseTesting;
        int errorArchivo;

        claseTesting.idClas = 9;
        claseTesting.nombreClas = "Yoga";
        claseTesting.horario = 15;
        claseTesting.cupoMax = 25;
        claseTesting.cupo = 0;

        ifstream archivo("iriClasesGYM.csv");
        //int leerArchivoClases(ifstream &archivo, clase* &clases, unsigned int &tamC);
        errorArchivo = leerArchivoClases(archivo, clas, tamC);

        REQUIRE(errorArchivo == 1);
        REQUIRE(tamC == 60);
        REQUIRE(clas[8].idClas == claseTesting.idClas);
        REQUIRE(clas[8].nombreClas == claseTesting.nombreClas);
        REQUIRE(clas[8].horario == claseTesting.horario);
        REQUIRE(clas[8].cupoMax == claseTesting.cupoMax);
        REQUIRE(clas[8].cupo == claseTesting.cupo);

        archivo.close();

        delete []clas;
    }
}
