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
        
        Grafo<string, int>* otro = new Grafo<string, int>();
        
	Vertice<string, int>* ola = new Vertice<string, int>("juan");
	Vertice<string, int>* elo = new Vertice<string, int>("paco");
	Vertice<string, int>* ilo = new Vertice<string, int>("gabriel");
	Vertice<string, int>* alo = new Vertice<string, int>("victoria");
	Vertice<string, int>* ela = new Vertice<string, int>("manuela");
        
        otro->AdicionarVertice(ola);
	otro->AdicionarVertice(elo);
	otro->AdicionarVertice(ilo);
	otro->AdicionarVertice(alo);
	otro->AdicionarVertice(ela);

        otro->AdicionarArista(ola, ola, 2);
	otro->AdicionarArista(ola, elo, 2);
        otro->AdicionarArista(ola, ilo, 2);
        otro->AdicionarArista(ola, alo, 2);
        otro->AdicionarArista(ola, ela, 2);
        
        otro->AdicionarArista(elo, elo, 2);
	otro->AdicionarArista(elo, ola, 2);
        otro->AdicionarArista(elo, ilo, 2);
        otro->AdicionarArista(elo, alo, 2);
        otro->AdicionarArista(elo, ela, 2);
        
        otro->AdicionarArista(ilo, ilo, 2);
        otro->AdicionarArista(ilo, ola, 2);
        otro->AdicionarArista(ilo, elo, 2);
        otro->AdicionarArista(ilo, alo, 2);
        otro->AdicionarArista(ilo, ela, 2);
        
        otro->AdicionarArista(alo, alo, 2);
        otro->AdicionarArista(alo, ola, 2);
        otro->AdicionarArista(alo, elo, 2);
        otro->AdicionarArista(alo, ilo, 2);
        otro->AdicionarArista(alo, ela, 2);
        
        otro->AdicionarArista(ela, ela, 2);
        otro->AdicionarArista(ela, ola, 2);
        otro->AdicionarArista(ela, elo, 2);
        otro->AdicionarArista(ela, ilo, 2);
        otro->AdicionarArista(ela, alo, 2);
	/*cout << "los PORCENTAJES tiempos de los estudaintes: " << endl; //falta probar tiempos

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
        */
        
        if(tec->completo())
            cout << "Es grafo completo :)" << endl;
        else
            cout << "No es grafo completo :(" << endl;
        
        if(otro->completo())
            cout << "Es grafo completo :)" << endl;
        else
            cout << "No es grafo completo :(" << endl;

	system("PAUSE");
	return 0;
}
