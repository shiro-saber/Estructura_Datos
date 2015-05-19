#ifndef __t7c4e2__Grafo__
#define __t7c4e2__Grafo__

#include <iostream>
#include "Arista.h"

using namespace std;

template <class V, class A> class Grafo;
template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Grafo<V, A> & grafo);

template <class V, class A>
class Grafo {
    Vertice<V, A> * vertices;

    public:
	Grafo();
	~Grafo();

	void AdicionarVertice(Vertice<V, A> * vertice);
	void AdicionarArista(Vertice<V, A> * origen, Arista<V, A> * arista);
	void AdicionarArista(Vertice<V, A> * origen, Vertice<V, A> * destino, A peso);

	friend std::ostream & operator << <>(std::ostream & os, Grafo<V, A> & grafo);


	//ejercicio
	//porsentaje acompañado
	void timposPareja(Vertice<V, A>* alumno, float anios);
	//quien ha tenido mas relaciones
	Vertice<V, A>* elPimp();
	//quienes no han tenido relaciones
	void foreverAlones();
	// quien es el mas estable
	void elMasEstable();
        //es grafo completo?
        bool completo();
};

template <class V, class A>
Grafo<V, A>::Grafo()
{
	vertices = NULL;
}

template <class V, class A>
Grafo<V, A>::~Grafo()
{
	Vertice<V, A> * temp = vertices;

	while (temp != NULL) {
		vertices = vertices->getSiguiente();
		delete temp;
		temp = vertices;
	}
}

template <class V, class A>
void Grafo<V, A>::AdicionarVertice(Vertice<V, A> * vertice)
{
	Vertice<V, A> * temp = vertices;
	Vertice<V, A> * anterior = vertices;

	while (temp != NULL) {
		anterior = temp;
		temp = temp->getSiguiente();
	}

	if (anterior == NULL) {
		vertices = vertice;
	}
	else {
		anterior->setSiguiente(vertice);
	}
}

template <class V, class A>
void Grafo<V, A>::AdicionarArista(Vertice<V, A> * origen, Arista<V, A> * arista)
{
	origen->AdicionarArista(arista);
}

template <class V, class A>
void Grafo<V, A>::AdicionarArista(Vertice<V, A> * origen, Vertice<V, A> * destino, A peso)
{
	origen->AdicionarArista(peso, destino);
}

template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Grafo<V, A> & grafo)
{
	Vertice<V, A> * temp = grafo.vertices;

	while (temp != NULL) {
		os << *temp << std::endl;
		temp = temp->getSiguiente();
	}

	return os;
}

//------------------------------

template <class V, class A>
void Grafo<V, A>::timposPareja(Vertice<V, A>* alumno, float anios)
{
	float solo = 0;
	float acom = alumno->sumAristas();
	float Psolo = 0;
	float Pacom = 0;
	Pacom = (acom / anios) * 100;
	Psolo = 100 - Pacom;
	cout << "el alumno: " << alumno->getInfo() << " ha estado " << Pacom << " con pareja y " << Psolo << " sin pareja" << endl;

}

template <class V, class A>
Vertice<V, A>* Grafo<V, A>::elPimp()
{
	Vertice<V, A> * temp = this->vertices;
	Vertice<V, A>* elMasPimp = NULL;
	elMasPimp = temp;
	while (temp != NULL) {
		
		if (elMasPimp->cuentArista() < temp->cuentArista())
		{
			elMasPimp = temp;
		}

		temp = temp->getSiguiente();
	}
	return elMasPimp;
}

template <class V, class A>
void Grafo<V, A>::foreverAlones()
{
	Vertice<V, A> * temp = this->vertices;
	cout << "los foerever alones: " << endl;
	while (temp != NULL) {
		
		if (temp->cuentArista() == 0)
		{
			cout << temp->getInfo() << ", ";
		}

		temp = temp->getSiguiente();
	}
	cout << endl;
}

template <class V, class A>
void Grafo<V, A>::elMasEstable()
{
	Vertice<V, A> * temp = this->vertices;
	Vertice<V, A>* elMasPimp = NULL;
	elMasPimp = temp;
	while (temp != NULL) {

		if (elMasPimp->laMasPesada() < temp->laMasPesada())
		{
			elMasPimp = temp;
		}

		temp = temp->getSiguiente();
	}

	cout << "el estudiante con las relaciones mas estables es: " << elMasPimp->getInfo() << endl;
}

template <class V, class A>
bool Grafo<V, A>::completo()
{
    Vertice<V, A> *temp = this->vertices; //cuantos vertices hay
    Vertice<V, A> *elotro = NULL; //necesitamos otro para comparar si estan 
    elotro = temp;
    bool es;
    
    while (temp != NULL)
    {
        //if(temp != NULL)
        //{
            if(temp->cuentArista() == elotro->cuentArista()) //compara si el numero de aristas en total es igual al del otro, en cuanto haya uno desigual ya no es completo
            {
                es = true;
                temp = temp->getSiguiente();
            }
            else
            {
                es = false;
                break;
            }
        //}
    }
    return es;
}

#endif /* defined(__t7c4e2__Grafo__) */