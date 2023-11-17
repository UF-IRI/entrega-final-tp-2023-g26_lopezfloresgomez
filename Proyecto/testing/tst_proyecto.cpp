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
bool cupomax(clase clase,int m, claseG *array)
{
  claseG *aux = array + m-1;
  while(array !=aux)// recorreriamos el generico, ya que lo hacemos como funcion individual
  {
       if(clase.Turnos->cantInscriptos<array->Turnos->cupoMax)
       {   return true;
       }
       array++;
  }
  return false;
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
