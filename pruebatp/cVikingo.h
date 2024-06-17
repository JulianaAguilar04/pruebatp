#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "cPersona.h"
#include "cDragon.h"

using namespace std;

class cVikingo:public cPersona
{
private:
	string Posicion;
	cDragon* miDragon; //relaci�n entre dragon y vikingo, posible lista de dragones matados

public:
	cVikingo(string Nombre, string Apellido, string Apodo, string FecNac, string Posicion, cDragon &Dragoncito);
	string to_string();
	friend ostream& operator<<(ostream& os, cVikingo& v);
	string getNombre();
	string getApellido();
	string getPosicion();
	void dragonesMatados();
	void setNombre(string Nombre);
	void setApellido(string Apellido);
	void setPosicion(string Posicion);
	void Trabajar();
	void AtacarDragones();
	static void AtacarDragones();
	void registrarDragonMatado(const string& nombreDragon);
	void mostrarDragonesMatados();

	~cVikingo();
};
