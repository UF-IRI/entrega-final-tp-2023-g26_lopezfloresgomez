#include "archivos.h"

files readFileUsers(ifstream &fileUsers, usersGYM *&users, u_int &cantU){

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

files readFileClasses(ifstream &fileClasses, classGYM *&classes, u_int &cantC){
    int i = 0;

    if (!fileClasses.is_open()) {
        return files :: errOpen;
    }

    string header;
    getline(fileClasses, header);

    string line;
    char delimiter = ',';

    while(getline(fileClasses, line))
        cantC++;

    fileClasses.clear();
    fileClasses.seekg(0, std::ios::beg);

    classes = new classGYM[cantC];

    getline(fileClasses, header);
    string auxidClase, auxnombre, auxhorario;
    stringstream ss;
    while(!fileClasses.eof() && getline(fileClasses, line)) {
        ss.clear();
        ss<<line;
        getline(ss,auxidClase,delimiter);
        (classes[i]).idClase = stoi(auxidClase);

        getline(ss,auxnombre,delimiter);
        (classes[i]).nombreClase = auxnombre;

        getline(ss,auxhorario,delimiter);
        (classes[i]).horario = stof(auxhorario);

        if(stoi(auxidClase)>0 && stoi(auxidClase)<6){
            (classes[i]).cuposMax=45;
            (classes[i]).cupos=0;
        }
        else if(stoi(auxidClase)>5 && stoi(auxidClase)<12){
            (classes[i]).cuposMax=25;
            (classes[i]).cupos=0;
        }
        else if(stoi(auxidClase)>11 && stoi(auxidClase)<18){
            (classes[i]).cuposMax=15;
            (classes[i]).cupos=0;
        }
        else if(stoi(auxidClase)>17 && stoi(auxidClase)<24){
            (classes[i]).cuposMax=40;
            (classes[i]).cupos=0;
        }
        else if(stoi(auxidClase)>23 && stoi(auxidClase)<30){
            (classes[i]).cuposMax=50;
            (classes[i]).cupos=0;
        }
        else if(stoi(auxidClase)>29 && stoi(auxidClase)<34){
            (classes[i]).cuposMax=30;
            (classes[i]).cupos=0;
        }
        else if(stoi(auxidClase)>33 && stoi(auxidClase)<61){
            (classes[i]).cuposMax=30;
            (classes[i]).cupos=0;
        }

        i++;
    }

    return files :: success;
}

files writeFileBinary(ofstream &fileBin, Asistencia *&clientAssist, u_int &cantA){
    if (fileBin.is_open()) {
        for (u_int i=0; i < cantA; i++) {
            fileBin.write((char*)&clientAssist[i].idCliente, sizeof(u_int));
            fileBin.write((char*)&clientAssist[i].cantInscriptos, sizeof(u_int));
            for(int j = 0; j < clientAssist[i].cantInscriptos; j++) {
                fileBin.write((char*)&clientAssist[i].CursosInscriptos[j], sizeof(Inscripcion));
            }
        }
        return files :: success;
    }
    return files :: errOpen;
}


/*
files readFileBinary(ifstream &fileBinRead, Asistencia *assist){

    if (!fileBinRead.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return files :: errOpen;
    }


    if (!fileBinRead.is_open()){
        delete [] assist;
        return files :: errOpen;
    }


    fileBinRead.clear();
    fileBinRead.seekg(0);

    Asistencia *aux = assist;

    while (!fileBinRead.eof()) {
        fileBinRead.read((char *)&aux->idCliente, sizeof(u_int));
        fileBinRead.read((char *)&aux->cantInscriptos, sizeof(u_int));

        Inscripcion *registered = new Inscripcion[aux->cantInscriptos];
        Inscripcion *auxInscriptions = registered;
        for (u_int i = 0; i < aux->cantInscriptos; i++) {
            fileBinRead.read((char *)auxInscriptions, sizeof(Inscripcion));
            auxInscriptions++;
        }
        aux->CursosInscriptos = registered;

        aux++;
    }


    return files :: success;

}

*/
