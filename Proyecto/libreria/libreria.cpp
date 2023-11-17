#include "libreria.h"

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
    claseG *aux = claseGe+m-1;

    while( claseGe != aux)//
    {
        if(clase.Turnos->idclas==claseGe->Turnos->idclas){// comparativa de los archivos con el generico
            return true;
        }
        claseGe++;
    }
    return -1;

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
/*
struct usuario
{
    string nombre;
    string apellido;
    string email;
    string fechaNac;
    int idCliente;
    int estado;
    string telefono;
};
*/
bool menores(usuario usuario){// analisis de la fecha de nacimiento con el anio actual, preguntar funciones ctime, menores de 16 anios no entran.
    time_t tiempoActual = time(nullptr);
    tm* fechaActual = localtime(&tiempoActual);

    string line = usuario.fechaNac;
    istringstream iss(line);
    // Asumiendo que el formato de la fecha es "DD-MM-AAAA"
    // Extraer el substring correspondiente al año
    string anio = line.substr(6, 4);
    int anioNacimiento = stoi(anio);

    int edad = fechaActual->tm_year + 1900 - anioNacimiento;

    // Verificar si tiene más de 18 años
    if (edad >= 18) {
        return 1;
    } else {
        return 0;
    }

}

/*
bool reserva(usuario * usuarios,clase* clases)
{


}

*/





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








