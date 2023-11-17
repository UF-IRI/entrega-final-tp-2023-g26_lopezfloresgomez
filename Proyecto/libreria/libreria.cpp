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
        return 1; // cuota al dia
    else
        return -1; // usuario no realizo el pago mensual
}
bool correspondencia (clase clase, int m,claseG *claseGe)
{
    claseG *aux = claseGe+m-1;

    while( claseGe != aux)//
    {
        if(clase.Turnos->idclas==claseGe->Turnos->idclas)// comparativa de los archivos con el generico
        { return true;
        }
        claseGe++;
    }

            return -1;

}
bool cupomax(clase clases,int m, claseG *array)
{
    claseG *aux = array + m-1;
            float i=8.0;
    while(array !=aux)// recorreriamos el generico, ya que lo hacemos como funcion individual
    {
        if ((clases.Turnos->horario==i) && (array->Turnos->horario==1) && (clases.Turnos->cantInscriptos<array->Turnos->cupoMax))
        {
     return true;
        }
        array++;
        i++;
    }
         return false;

}
/*bool menores(usuario usuario)// analisis de la fecha de nacimiento con el anio actual, preguntar funciones ctime, menores de 16 anios no entran.
{

}


bool reserva(usuario * usuarios,clase* clases)
{


}*/







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








