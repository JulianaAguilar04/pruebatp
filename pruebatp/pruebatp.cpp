// pruebatp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include "cJinete.h"
#include "cVikingo.h"

using namespace std;

void EscueladeDragones(vector<cJinete*> &Jinetes_isla, vector<cDragon*>&Dragones_isla);
void EstudioDeDragones(vector<cDragon*>& Dragones_isla);
void ListaDeDragones(const vector<cDragon*>& Dragones_isla);
void EntrenarDragones(vector<cJinete*>& Jinetes_isla,vector<cDragon*>& Dragones_isla);

/*
void CarreradeDragones();

void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones);
*/


int main()
{
    //menu
    cAtaque Ataque1("Fuego", "15", "14");
    cAtaque Ataque2("Veneno", "20", "11");
    cAtaque Ataque3("Electricidad", "14", "12");

    vector<cDragon*> Dragones_isla;
    vector<string>Habilidades1 = { "Volar rapido", "Llamarada" };
    
    Dragones_isla.push_back(new cDragon("Chimuelo", "Inteligente", "Mediano", "Negro", false, 300, 500, Habilidades1, &Ataque1));
    Dragones_isla.push_back(new cDragon("Exterminador", "Rapido", "Mediano", "Transparente", true, 300, 500, Habilidades1, &Ataque2));
    Dragones_isla.push_back(new cDragon("Skrill", "Agresivo", "Grande", "Violeta", false, 300, 500, Habilidades1, &Ataque3));


    vector <cDragon*> ::iterator it_d = Dragones_isla.begin();

    while (it_d != Dragones_isla.end()) {
        cout << *(*it_d) << endl;
        it_d++;
    }

    cDragon Dragon4("Skrill", "Agresivo", "Grande", "Violeta", false, 500, 300, Habilidades1, &Ataque3);

    vector <cPersona*> Personas_isla;
    Personas_isla.push_back(new cVikingo("Juliana", "Aguilar", "Juju", "31-03-2004", "Guerrera", Dragon4, 10));
    Personas_isla.push_back(new cJinete("Elias", "Garcia", "Elu", "19-06-2002", "Lloron", 1.5, 15));
    Personas_isla.push_back(new cVikingo("Elias", "Garcia", "Elu", "19-06-2002", "Guerrero", Dragon4, 5));
    
    vector<cPersona*>::iterator it_p = Personas_isla.begin();

    while (it_p != Personas_isla.end()) {
        cout << *(*it_p) << endl;
        it_p++;
    } 

    //me creo un vetor de jinetes para utilizarlos en escuela de dragones
    vector<cJinete*> Jinetes_isla;
    for (cPersona* persona : Jinetes_isla) {
        cJinete* jinete = dynamic_cast<cJinete*>(persona);
        if (jinete != nullptr) {
            Jinetes_isla.push_back(jinete);
        }
    }

    //me creo un vector de vikingos para utilizarlos en batalla de dragones
    vector<cVikingo*> Vikingos_isla;
    for (cPersona* persona : Personas_isla) {
        cVikingo* vikingo = dynamic_cast<cVikingo*>(persona);
        if (vikingo != nullptr) {
            Vikingos_isla.push_back(vikingo);
        }
    }

    vector<std::string> habilidadesIniciales = { "volar rápido", "llamarada" };
    cDragon dragon1("Furia", "Inteligente","Chico", "Negro", true,  300, 500, habilidadesIniciales, &Ataque1);
    cJinete entrenador1("Hipo", "Iuzchuk", "Ache", "23-11-2001", "Herrero", 1.5, 30); //nivel de fuerza?

    dragon1.mostrarHabilidades();

    dragon1.Entrenar("velocidad", entrenador1);
    dragon1.Entrenar("resistencia", entrenador1);
    dragon1.Entrenar("habilidades", entrenador1);

    dragon1.mostrarHabilidades();


    int opcion;
    do {
        cout << "------BIENVENIDO A LA ISLA DE BERK------" << endl;
        cout << "1) Escuela de dragones" << endl;
        cout << "2) Carrera de dragones" << endl;
        cout << "3) Batalla de dragones" << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            EscueladeDragones(Jinetes_isla, Dragones_isla);
            break;
        case 2:
            cout << "Aqui va la opcion de carrera de dragones" << endl;
            break;
        case 3:
            cout << "BatalladeDragones(Vikingos_isla, Dragones_isla)" << endl;;
            break;
        case 4:
            cout << "Muchas gracias por visitar la Isla de Berk" << endl;
            break;

        default:
            cout << "Opcion invalida: Intentelo de nuevo" << endl;
            break;
        }
        cout << endl;
    } while (opcion != 4);


    
    for (int i = 0; i < Dragones_isla.size(); i++) {
        delete Dragones_isla[i];
    }

    for (int i = 0; i < Personas_isla.size(); i++) {
        delete Personas_isla[i];
    }

   return 0;
}
//fin del main


//--------------------------------------------------------------------------------ESCUELA DE DRAGONES
void EscueladeDragones(vector<cJinete*>& Jinetes_isla, vector<cDragon*>& Dragones_isla) {
    int opcion;
    do {
        cout << "\nUSTED ESTA EN LA ESCUELA DE LA ISLA" << endl;
        cout << "1) Estudio de dragones" << endl;
        cout << "2) Lista de dragones conocidos " << endl;
        cout << "3) Entrenar " << endl;
        cout << "4) Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            EstudioDeDragones(Dragones_isla);
            break;
        case 2:
            ListaDeDragones(Dragones_isla);
            break;
        case 3:
            EntrenarDragones(Jinetes_isla,Dragones_isla);
            break;

        case 4:
            cout << "Saliendo de la Escuela de Dragones..." << endl;
            break;

        default:
            cout << "Opcion invalida: Vuelva a intentarlo" << endl;
            break;
        }

    } while (opcion != 4);
}


void EstudioDeDragones(vector<cDragon*>& Dragones_isla) {
    string nombre, caracteristica, tamano, color;
    int velocidad=0, resistencia=0, hab=0;
    bool estado;
    char domado;
    vector<string> v_habilidades;

    cout << "Ustdes ha encontrado un nuevo dragon!" << endl;
    cout << "Ingrese el nombre del dragon: ";
    cin >> nombre;
    cout << "Ingrese las caracteristicas del dragon: ";
    cin >> caracteristica;
    cout << "Ingrese el tamano del dragon: ";
    cin >> tamano;
    cout << "Ingrese el color del dragon: ";
    cin >> color;
    cout << "El dragon esta domado? (s/n): ";
    cin >> domado;
    estado = (domado == 's' || domado == 'S');
    cout << "Ingrese la velocidad del dragon:" << endl;
    cin >> velocidad;
    cout << "Ingrese la resistencia del dragon:" << endl;
    cin >> resistencia;
    cout << "Ingrese las habilidades del dragon:" << endl;
    cout << "Cantidad:" << endl;
    cin >> hab;

    v_habilidades.reserve(hab); //reservo espacio para la cantidades de habilidades
    for (int i = 0; i < hab; i++)
    {
        string habilidad;
        cout << "Ingrese habilidad:" << (i+1) <<":" << endl;
        cin >> habilidad;
        v_habilidades.push_back(habilidad);
    }

    string tipoAtaque, danioAtaque, alcanceAtaque;
    cout << "Ingrese el tipo de ataque del dragón: ";
    cin >> tipoAtaque;
    cout << "Ingrese el daño del ataque del dragón: ";
    cin >> danioAtaque;
    cout << "Ingrese el alcance del ataque del dragón: ";
    cin >> alcanceAtaque;
    cAtaque* ataque = new cAtaque(tipoAtaque, danioAtaque, alcanceAtaque);

    // Crear el nuevo objeto cDragon y agregarlo al vector
    Dragones_isla.push_back(new cDragon(nombre, caracteristica, tamano, color, estado, velocidad, resistencia, v_habilidades, ataque));
    cout << "Dragon agregado exitosamente!" << endl;
}

void ListaDeDragones(const vector<cDragon*>& Dragones_isla) {
    cout << "\nLista de Dragones Conocidos:" << endl;
    for (const auto& dragon : Dragones_isla) {
        cout << dragon->to_string();
    }
}

void EntrenarDragones(vector<cJinete*>& Jinetes_isla,vector<cDragon*>& Dragones_isla) {
    
    vector<cJinete*>::iterator it_j = Jinetes_isla.begin();
    vector<cDragon*>::iterator it_d = Dragones_isla.begin();

    while (it_j != Jinetes_isla.end()) {
        cJinete& JineteActual = **it_j;
        while (it_d != Dragones_isla.end()) {
            (*it_d)->Entrenar("Velocidad", JineteActual);
            ++it_d;
        }
        ++it_j;
        it_d = Dragones_isla.begin();
    }

    /*for (auto& dragon : Dragones_isla) {
        if (dragon->getEstado()) {
            dragon->Entrenar();
            cout << "El dragon " << dragon->getNombre() << " ha sido entrenado." << endl;
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " no esta domado y no puede ser entrenado." << endl;
        }
    }
    */


}
//-----------------.h y .cpp de escuela de dragones-------------------------
/*class EscueladeDragones {
private:
    string Nombre;
    vector<cJinete*> Alumnos;
    vector<cDragon*> Dragones;

public:
    EscueladeDragones(string Nombre);
    void AgregarJinete(cJinete* Jinete);
    void AgregarDragon(cDragon* Dragon);
    void ImprimirEstado();
};
EscueladeDragones::EscueladeDragones(string Nombre) {
    this->Nombre = Nombre;
}

void EscueladeDragones::AgregarJinete(cJinete* Jinete) {
    Alumnos.push_back(Jinete);
}

void EscueladeDragones::AgregarDragon(cDragon* Dragon) {
    Dragones.push_back(Dragon);
}

void EscueladeDragones::ImprimirEstado() {
    cout << "Escuela de Dragones: " << Nombre << endl;
    cout << "Lista de Alumnos:" << endl;
    for (auto alumno : Alumnos) {
        cout << alumno->to_string() << endl;
    }
    cout << "Lista de Dragones:" << endl;
    for (auto dragon : Dragones) {
        cout << dragon->getNombre() << " - " << dragon->getColor() << " - " << dragon->getTamano() << endl;
    }
}
*/

//--------------------------------------------------------------------------------FIN ESCUELA DE DRAGONES























































/*

//--------------------------------------------------------------------------------BATALLA DE DRAGONES
// .h y .cpp de Batalla de dragones
//INICIO.H
class BatalladeDragones {
private:
    vector<cDragon*> dragonesMalos;
    vector<cDragon*> dragonesBuenos;
    vector<cVikingo*> vikingos;
    vector<cJinete*> jinetes;
public:
    BatalladeDragones(vector<cDragon*>& dragones, vector<cVikingo*>& vikingos, vector<cJinete*>& jinetes);
    void AvisarAldea();
    void Combatir();
    void AnunciarGanador(cPersona* ganador);
    void FiltrarDragones(vector<cDragon*>& dragones); // Nuevo método para filtrar dragones
};
*/

/*#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cVikingo;
class cDragon;

void BatalladeDragones(vector<cVikingo*>& Vikingos_isla, vector<cDragon*>& Dragones_isla);*/
//FIN.H

/*

//INICIO.CPP
BatalladeDragones::BatalladeDragones(vector<cDragon*>& dragones, vector<cVikingo*>& vikingos, vector<cJinete*>& jinetes) {
    srand(time(0));
    FiltrarDragones(dragones);
    this->vikingos = vikingos;
    this->jinetes = jinetes;
}

void BatalladeDragones::FiltrarDragones(vector<cDragon*>& dragones) {
    for (auto dragon : dragones) {
        if (dragon->getEstado()) {
            dragonesBuenos.push_back(dragon);
        }
        else {
            dragonesMalos.push_back(dragon);
        }
    }
}

void BatalladeDragones::AvisarAldea() {
    cout << "¡La aldea está en peligro!" << endl;
}


void BatalladeDragones::Combatir() {
    if (dragonesMalos.empty() || (vikingos.empty() && jinetes.empty())) {
        cout << "No hay suficientes dragones malos o combatientes para realizar la batalla." << endl;
        return;
    }

    // Seleccionar un vikingo/jinete aleatorio
    cPersona* combatiente;
    if (!vikingos.empty() && !jinetes.empty()) {
        if (rand() % 2 == 0) {
            combatiente = vikingos[rand() % vikingos.size()];
        }
        else {
            combatiente = jinetes[rand() % jinetes.size()];
        }
    }
    else if (!vikingos.empty()) {
        combatiente = vikingos[rand() % vikingos.size()];
    }
    else {
        combatiente = jinetes[rand() % jinetes.size()];
    }

    // Seleccionar un dragón malo aleatorio
    cDragon* dragonMalo = dragonesMalos[rand() % dragonesMalos.size()];

    // Realizar el combate
    int fuerzaCombatiente = combatiente->getFuerza();
    if (fuerzaCombatiente > dragonMalo->getResistencia()) {
        cout << "¡" << combatiente->getNombre() << " ha derrotado a " << dragonMalo->getNombre() << "!" << endl;
        // Eliminar dragón malo de la lista
        dragonesMalos.erase(remove(dragonesMalos.begin(), dragonesMalos.end(), dragonMalo), dragonesMalos.end());
        // Añadir dragón malo a la lista de dragones matados por el combatiente
        combatiente->addDragonMatado(dragonMalo);
        // Anunciar ganador
        AnunciarGanador(combatiente);
    }
    else {
        cout << "¡" << dragonMalo->getNombre() << " ha derrotado a " << combatiente->getNombre() << "!" << endl;
        // Anunciar ganador
       // AnunciarGanador(dragonMalo);
    }
}

void BatalladeDragones::AnunciarGanador(cPersona* ganador) {
    cout << "¡El ganador es " << ganador->getNombre() << "!" << endl;
}
/*
void BatalladeDragones::AnunciarGanador(cDragon* ganador) {
    cout << "¡El ganador es el dragón " << ganador->getNombre() << "!" << endl;
}
*/

/*
void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones) {
    cVikingo::AtacarDragones(); // Enviar mensaje a los vikingos

    cout << "La batalla ha comenzado!" << endl;

    // Simulación simple de la batalla
    srand(time(0));
    for (auto& vikingo : vikingos) {
        if (dragones.empty()) {
            cout << "Todos los dragones han sido derrotados!" << endl;
            return;
        }

        int dragonIndex = rand() % dragones.size();
        cDragon* dragon = dragones[dragonIndex];

        // Ejemplo simple de combate: 50% de probabilidad de que el vikingo gane
        if (rand() % 2 == 0) {
            cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragon->getNombre() << endl;
            vikingo->registrarDragonMatado(dragon->getNombre());
            dragones.erase(dragones.begin() + dragonIndex); // Eliminar dragón derrotado
            delete dragon; // Liberar memoria del dragón eliminado
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " ha derrotado al vikingo " << vikingo->getNombre() << endl;
        }
    }

    cout << "La batalla ha terminado!" << endl;
}
*/

//FIN.CPP


/*
void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones)
{
}
*/



 /* NO SE COMO HACERLO, CHAT GPT ME DIJO ESTO PERO NO FUNCIONA
 
// Creación de objeto BatalladeDragones
BatalladeDragones batalla(dragones, vikingos, jinetes);

// Simulación de batalla
batalla.AvisarAldea();
batalla.Combatir();
*/ 



/* batalla dragones cpp (VIEJO, LO DEJO POR LAS DUDAS)
void BatalladeDragones(vector<cVikingo*>& vikingos, vector<cDragon*>& dragones) {
    cVikingo::AtacarDragones(); // Enviar mensaje a los vikingos

    cout << "La batalla ha comenzado!" << endl;

    // Simulación simple de la batalla
    srand(time(0));
    for (auto& vikingo : vikingos) {
        if (dragones.empty()) {
            cout << "Todos los dragones han sido derrotados!" << endl;
            return;
        }

        int dragonIndex = rand() % dragones.size();
        cDragon* dragon = dragones[dragonIndex];

        // Ejemplo simple de combate: 50% de probabilidad de que el vikingo gane
        if (rand() % 2 == 0) {
            cout << "El vikingo " << vikingo->getNombre() << " ha derrotado al dragon " << dragon->getNombre() << endl;
            vikingo->registrarDragonMatado(dragon->getNombre());
            dragones.erase(dragones.begin() + dragonIndex); // Eliminar dragón derrotado
            delete dragon; // Liberar memoria del dragón eliminado
        }
        else {
            cout << "El dragon " << dragon->getNombre() << " ha derrotado al vikingo " << vikingo->getNombre() << endl;
        }
    }

    cout << "La batalla ha terminado!" << endl;
}
*/

/*CORRECCION:
la hice que sea estatica porq sino tiraba error, antes decia lo mismo pero sin static 
y le puse puntero, lo arregle solo para q no me tiraba error pero seguro no esta bien 
antes era: "void Entrenar(cPersona Persona, ) {} "

Tambien la modifique en lo lugares q la llamaba ( prubatp.cpp linea 51/52 , pruebatp.cpp linea 152/153) 
*/
