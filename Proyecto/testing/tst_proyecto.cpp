#include <catch2/catch.hpp>
#include <libreria.h>
#include <archivos.h>


TEST_CASE("funciones(correctamente)", "[correspondencia]")
{
    SECTION("correspondencia verdadera")
    {
        clase clases;
        clases.Turnos=new Turno();//me aseguro que turnos se inicialize correctamente
        clases.Turnos->idclas=10;
        int m=3;
        claseG *aux=new claseG[3];

        bool resultado=correspondencia(clases,m,aux);
        REQUIRE(resultado==true);
        delete []aux;
        delete clases.Turnos;
    }
    SECTION("correspondencia falsa")
    {
        clase clases;
        clases.Turnos = new Turno(); // me aseguro que turnos se inicialize correctamente
        clases.Turnos->idclas = 99;   // Cambié el idclas para que no coincida con el idclas en aux
        int m = 3;
        claseG *aux = new claseG[3];

        bool resultado = correspondencia(clases, m, aux);
        REQUIRE(resultado == false);

        delete[] aux;
        delete clases.Turnos;
    }
}

