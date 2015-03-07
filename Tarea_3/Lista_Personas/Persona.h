#include <string>
#include <iostream>

using namespace std;

class Persona
{
private:
	string nombre;
	string apellidos;
	int edad;
	int dia;
	int mes;
	int ano;
public:
	Persona() {}
	Persona(string _nombre, string _apellidos, int _edad, int _dia, int _mes, int _ano) : nombre(_nombre), apellidos(_apellidos), edad(_edad), dia(_dia), mes(_mes), ano(_ano){}
	~Persona() {}

	string getNombre() { return nombre; }
	string getApellidos() { return apellidos; }
	int getEdad() { return edad; }
	int getDia() { return dia; }
	int getMes() { return mes; }
	int getAnio() { return ano; }

	friend ostream & operator << (ostream&, Persona);
	bool operator <(Persona);
	bool operator >(Persona);
};