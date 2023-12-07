#include <catch2/catch.hpp>
#include "archivos.h"
#include "archivos.cpp"
#include "libreria.h"



TEST_CASE("Testing Archivos")
{
    SECTION("Archivo clientes (.csv)") {

        u_int cantClientes;
        usersGYM *Clientes, ClientePrueba;
        files errArchivocliente;

        ClientePrueba.idCliente = 206;
        ClientePrueba.apellido = "Torres";
        ClientePrueba.email = "MateoTorres@bolandia.iri";
        ClientePrueba.estado = 0;
        ClientePrueba.fechaNac = "08-01-1995";
        ClientePrueba.nombre = "Mateo";
        ClientePrueba.telefono = "844-131-1318";

        ifstream infileClientes("../iriClientesGYM.csv");

        errArchivocliente = readFileUsers(infileClientes, Clientes, cantClientes);

        REQUIRE(errArchivocliente == success);
        REQUIRE(cantClientes == 250);
        REQUIRE(Clientes[205].apellido == ClientePrueba.apellido);
        REQUIRE(Clientes[205].idCliente == ClientePrueba.idCliente);
        REQUIRE(Clientes[205].email == ClientePrueba.email);
        REQUIRE(Clientes[205].estado == ClientePrueba.estado);
        REQUIRE(Clientes[205].fechaNac == ClientePrueba.fechaNac);
        REQUIRE(Clientes[205].nombre == ClientePrueba.nombre);
        REQUIRE(Clientes[205].telefono == ClientePrueba.telefono);

        infileClientes.close();

        delete []Clientes;
    }

    SECTION("Archivo Aistencia (.bin)") {
        int cantAsist;
        Asistencia *asistencias;
        files errBinario;

        ifstream infileAsistencia("../asistencias_1697673600000.dat", ios::binary);

        infileAsistencia.seekg(0, std::ios::end);
        std::streampos fileSize = infileAsistencia.tellg();
        infileAsistencia.seekg(0, std::ios::beg);
        cantAsist = static_cast<u_int>(fileSize / ((sizeof(Asistencia)) + sizeof(Inscripcion)))-1;


        asistencias = new Asistencia[cantAsist];

        errBinario = readFileBinary(infileAsistencia, asistencias);

        REQUIRE(errBinario == success);

        delete []asistencias;

        infileAsistencia.close();
    }



    SECTION("Archivo Clases (.csv)") {
        u_int cantclases;
        classGYM *Clases, ClasePrueba;
        files errArchivoclase;

        ClasePrueba.idClase = 9;
        ClasePrueba.nombreClase = "Yoga";
        ClasePrueba.horario = 15;
        ClasePrueba.cuposMax = 25;
        ClasePrueba.cupos = 0;

        ifstream infileClases("../iriClasesGYM.csv");
        errArchivoclase = readFileClasses(infileClases, Clases, cantclases);

        REQUIRE(errArchivoclase == success);
        REQUIRE(cantclases == 60);
        REQUIRE(Clases[8].idClase == ClasePrueba.idClase);
        REQUIRE(Clases[8].nombreClase == ClasePrueba.nombreClase);
        REQUIRE(Clases[8].horario == ClasePrueba.horario);
        REQUIRE(Clases[8].cuposMax == ClasePrueba.cuposMax);
        REQUIRE(Clases[8].cupos == ClasePrueba.cupos);

        infileClases.close();

        delete []Clases;
    }
}
