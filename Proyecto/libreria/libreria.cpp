#include "libreria.h"


Libreria::Libreria()
{
}

/*int contieneCaracterNoNumerico(int numero) {
         // Verificar si el entero contiene caracteres no numéricos
    while (numero != 0) {
        int digito = numero % 10;
        if (digito < 0 || digito > 9) {
            // Si encuentra un dígito no numérico, la validación falla
            return 1;
        }
        numero /= 10;
    }
    return 0; // El entero solo contiene dígitos, la validación es exitosa
  if (contieneCaracterNoNumerico(usuario.estado)==true) {
        return 0; // Error: Caracteres no permitidos en el estado
}*/


bool verificarPago(usuario usuariop)
{
    if( usuariop.estado>=0)
        return true; // cuota al dia
    else
        return false; // usuario no realizo el pago mensual
}
bool correspondencia (clase clase, int m,claseG *claseGe)
{
    claseG *aux = claseGe+m-1;

    while( claseGe != aux)//
    {
        if(clase.Turnos->idclas == claseGe->Turnos->idclas){// comparativa de los archivos con el generico
         return true;
        }
        claseGe++;
    }

    return false;
}
bool cupomax(clase clases,int m, claseG *array)
{
    claseG *aux = array + m-1; // Apunta al generico final
            float i=8.0;
    while(array !=aux)// recorreriamos el generico, ya que lo hacemos como funcion individual
    {
        if ((clases.Turnos->horario==i) && (array->Turnos->horario==1) && (clases.Turnos->cantInscriptos < array->Turnos->cupoMax))
        {
     return true;
        }
        array++;
        i++;
    }
    return false;

}
bool menores(usuario usuario){// analisis de la fecha de nacimiento con el anio actual, preguntar funciones ctime, menores de 16 anios no entran.
     time_t tiempoActual = time(nullptr);
     tm* fechaActual = localtime(&tiempoActual);

     string line = usuario.fechaNac;
     //line = 26-06-2011 BBBBBB
    istringstream iss(line);
     // Asumiendo que el formato de la fecha es "DD-MM-AAAA"
     // Extraer el substring correspondiente al año
     string anio = line.substr(6, 4);
     int anioNacimiento = stoi(anio);

     int edad = (fechaActual->tm_year) + 1900 - anioNacimiento;
                // 123 + 1900 -2002

     // Verificar si tiene más de 18 años
     if (edad >= 18)
        return true;
     else
        return false;
}

/*
 * Reserva la funcion es que recorra los usuarios y clases
bool reserva(usuario * usuarios,clase* clases){}
*/
