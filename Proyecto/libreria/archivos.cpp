#include "archivos.h"
files readFileClients(ifstream &fileUsers, usersGYM *&users, u_int &cantU){

    int i = 0;

    if (!fileUsers.is_open()) {

        return files :: errOpen;
    }

    string header;
    getline(fileUsers, header);

    string line;
    char delimiter = ',';

    while(getline(fileUsers, line))
        cantU++;

    fileUsers.clear();
    fileUsers.seekg(0, std::ios::beg);

    users = new usersGYM[cantU];

    getline(fileUsers, header);
    string auxidCliente, auxnombre, auxapellido, auxemail, auxtelefono, auxfechanacimiento, auxestado;
    stringstream ss;
    while(!fileUsers.eof() && getline(fileUsers, line)) {
        ss.clear();
        ss<<line;
        getline(ss,auxidCliente,delimiter);
        (users[i]).idCliente = stoi(auxidCliente);

        getline(ss,auxnombre,delimiter);
        (users[i]).nombre = auxnombre;

        getline(ss,auxapellido,delimiter);
        (users[i]).apellido = auxapellido;

        getline(ss,auxemail,delimiter);
        (users[i]).email = auxemail;

        getline(ss,auxtelefono,delimiter);
        (users[i]).telefono = auxtelefono;

        getline(ss,auxfechanacimiento,delimiter);
        (users[i]).fechaNac = auxfechanacimiento;

        getline(ss,auxestado,delimiter);
        (users[i]).estado = stoi(auxestado);

        i++;
    }
    return files :: success;
}






