/*
Para un estudio sociológico en una universidad, una empresa consultora quiere
desarrollar una aplicación que le permita establecer las relaciones entre estudiantes
durante su vida estudiantil. La aplicación debe ser capaz de generar los siguientes
resultados:
 Con quiénes se ha relacionado un estudiante y qué tiempo duró cada relación //cehck
 Qué porcentaje del tiempo ha estado acompañado y qué porcentaje del tiempo ha estado solo // check
 Quién es el estudiante que ha tenido más relaciones // check
 Quiénes son los estudiantes que no han tenido relaciones // check 
 Quién es el estudiante más estable en sus relaciones !! // check
Diseñe e implemente la aplicación antes mencionada. Haga las consideraciones que
considere necesarias.
*/
#include<iostream>
#include<cstdlib>
#include <string>
#include "Grafo.h"
#define ANIOS 5

using namespace std;


int main()
{

	Grafo<string, int>* tec = new Grafo<string, int>();

	Vertice<string, int>* juan = new Vertice<string, int>("juan");
	Vertice<string, int>* paco = new Vertice<string, int>("paco");
	Vertice<string, int>* gabriel = new Vertice<string, int>("gabriel");
	Vertice<string, int>* victoria = new Vertice<string, int>("victoria");
	Vertice<string, int>* manuela = new Vertice<string, int>("manuela");

	tec->AdicionarVertice(juan);
	tec->AdicionarVertice(paco);
	tec->AdicionarVertice(gabriel);
	tec->AdicionarVertice(victoria);
	tec->AdicionarVertice(manuela);

	tec->AdicionarArista(juan, manuela, 2);
	tec->AdicionarArista(manuela, juan, 2);

	tec->AdicionarArista(gabriel, manuela, 2);
	tec->AdicionarArista(manuela, gabriel, 2);
	
	tec->AdicionarArista(paco, manuela, 1);
	tec->AdicionarArista(manuela, paco, 1);

	cout << "las relaciones en el campus son: " << *tec << endl;
	cout << "los PORCENTAJES tiempos de los estudaintes: " << endl; //falta probar tiempos

	tec->timposPareja(manuela, ANIOS);
	tec->timposPareja(juan, ANIOS);
	tec->timposPareja(paco, ANIOS);
	tec->timposPareja(gabriel, ANIOS);
	tec->timposPareja(victoria, ANIOS);

	cout << endl;

	cout << "el estudiante con mas relaciones" << endl;
	cout << *(tec->elPimp()) <<endl;

	tec->foreverAlones();

	tec->elMasEstable();


	system("PAUSE");
	return 0;
}