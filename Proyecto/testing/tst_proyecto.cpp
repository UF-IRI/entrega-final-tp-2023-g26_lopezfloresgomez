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
