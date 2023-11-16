#include "libreria.h"
#include <iostream>
#include <fstream>
#include <string>

Libreria::Libreria()
{
}
/*
typedef struct {
    unsigned int cupo_max;//cupo maximo de personas por clase en este horario
    float horario;// posible horario de clase
    unsigned int cantInscriptos;// cupos ocupados, reagrupar original
    unsigned int* alumnos;
    unsigned int idclas;
} Turno;
struct claseG {
    string nombreClaS;
    Turno* Turnos;
};
*/
bool verificarPago(usuario usuario)// N cantidad de struc alumnos vigentes,bool
{
    if ( usuario.estado>=0)
        return 1; // cuota al dia
    else
        return -1; // usuario no realizo el pago mensual
}

bool correspondencia (clase clase, int m,claseG *claseGe)
{
    claseGe *aux = claseGe+m-1;

    while( claseGe != aux)//
    {
        if(clase->idclas==claseGe.idclas && clase->turno.horario == claseGe.turno.horario)// comparativa de los archivos con el generico
            return 1;
        else
            return -1;
    }
}
bool cupomax(clase clase,int m)
{
    clase *aux= clase+m-1;
    while(clase !=aux)// recorreriamos el generico, ya que lo hacemos como funcion individual
    {
        if(clase->turnos.cantinscriptos<clase->turnos.cupomax)
            return 1;
        else
            return -1;
    }
}

bool menores(usuario usuario)// analisis de la fecha de nacimiento con el anio actual, preguntar funciones ctime, menores de 16 anios no entran.
{

}

bool dia()// preguntar sobre la funcion que analiza la reserva, ya que esta tendra un horario limitado de 19 a 22 hs. no hacer
{

}
bool reserva(usuario usuario[],clases clases[],int n,int m)
{
    for(int i=0; i<n; i++){
        for(int h=0; i<m;h++){

        }
    }
}







// como delimitar las restricciones, teniendo en cuenta que puede haber documentos o id con letras y estos solo admiten numeros, pero a su vez las letras en la tabla assky son numeros y no me lo tomaria como restriccion
// como rellenar el sistema matricial de los horarios, para asi completar los cupos maximos
/*typedef struct {
    unsigned int cupo_max;//cupo maximo de personas por clase en este horario
    float horario;// posible horario de clase
    unsigned int cantInscriptos;// cupos ocupados, reagrupar original
    unsigned int* alumnos;

} Turno;

struct clase {
    int idClase;// preguntar
    string nombreclas;
    unsigned int cantTurnos;
    Turno* Turnos;

struct usuario
{
    string nombre;
    string apellido;
    string email;
    string fechaNac;
    int idCliente;
    int estado;
    string telefono;
    int horario;
*/


using namespace std;




bool verificarPago(usuario usuario)// N cantidad de struc alumnos vigentes,bool
{
    if ( usuario.estado>=0)
        return 1; // cuota al dia
    else
        return 0; // usuario no realizo el pago mensual
}

bool correspondencia (usuario , clases , int m)
{
    clases *aux = clases+N-1;

    while( clases != aux)
    {
       if( verificaPago(usuario)==1)
        {

        }
    }
    if( verificaPago())


}
bool cupos(usuario usuario[],clases clases[],int n,int m)
{
    for(int i=0; i<n; i++){
        for(int h=0; i<m;h++){

        }
    }
}

