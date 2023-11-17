#include <catch2/catch.hpp>
#include "archivos.h"
#include "libreria.h"

TEST_CASE("funciones (correctamente)", "[verificarPago]")
{
    usuario aux;
    int valor;
    SECTION ("prueba del estado negativo"){
        aux.estado=-6;
        valor=verificarPago(aux);
       CHECK (valor==-1);
    }
  SECTION ("prueba del estado positivo"){
       int valor;
       aux.estado=1;
       valor=verificarPago(aux);
       CHECK (valor==1);
  }
 /* SECTION ("prueba del estado con letras"){

       int valor;
       int condicion;
       aux.estado=1;
       condicion=contieneCaracterNoNumerico(aux.estado);
       REQUIRE (condicion==0);
       valor=verificarPago(aux);

  }*/
  SECTION ("prueba del estado 0"){
       int valor;
       aux.estado=0;
       valor=verificarPago(aux);
       CHECK (valor==1);
  }
}

TEST_CASE("funciones (correctamente)","[menores]"){
  SECTION("correspondencia verdadera") // MAYOR DE EDAD
  {
       usuario aux;
       aux.fechaNac = "26-06-2011";
       bool resul = menores(aux);

       REQUIRE(resul == true);
  }
  SECTION("correspondencia verdadera") // menor de edasd
  {
       usuario aux;
       aux.fechaNac = "28-11-2000";
       bool resul = menores(aux);

       REQUIRE(resul == false);
  }
}

TEST_CASE("funciones (correctamente)", "[cupomax]")
{
       // Crear objetos necesarios para la prueba
        clase clase;
        clase.Turnos->cantInscriptos = 20; // Ajusta los valores según tus necesidades
        int m= 5;
        claseG *aux= new claseG[m];
        aux[0].Turnos->cupoMax= 40;
        aux[1].Turnos->cupoMax= 40;
        aux[2].Turnos->cupoMax= 40;
        aux[3].Turnos->cupoMax= 40;
        aux[4].Turnos->cupoMax= 40;
        claseG array[3]; // Ajusta el tamaño según tus necesidades
        array[0].Turnos = new Turno{5, 15};
        array[1].Turnos = new Turno{12, 25};
        array[2].Turnos = new Turno{8, 18};

       SECTION("Caso de prueba 1") {
           REQUIRE(cupomax(clase, 2, array) == true); // Ajusta el índice según tus necesidades
       }

       SECTION("Caso de prueba 2") {
           REQUIRE(cupomax(clase, 3, array) == false); // Ajusta el índice según tus necesidades
       }
}


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
