#ifndef __t7c4e2__Vertice__
#define __t7c4e2__Vertice__

#include <iostream>

template <class V, class A> class Arista;
template <class V, class A> class Vertice;

template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Vertice<V, A> & vertice);

template <class V, class A>
class Vertice {
	V info;
	Arista<V, A> * aristas;
	Vertice<V, A> * siguiente;

public:
	Vertice();
	Vertice(V info);

	~Vertice();

	V getInfo();
	void setInfo(V value);

	Arista<V, A> * getAristas();
	void setAristas(Arista<V, A> value);

	Vertice<V, A> * getSiguiente();
	void setSiguiente(Vertice<V, A> * value);

	void AdicionarArista(Arista<V, A> * arista);
	void AdicionarArista(A peso, Vertice<V, A> * destino);

	friend std::ostream & operator << <>(std::ostream & os, Vertice<V, A> & vertice);

	//ejercicio
	//suma peso de aristas
	int sumAristas();
	//cuantas relaciones (aristas) tiene
	int cuentArista();
	// regresa el peso de la mas pesada
	int laMasPesada();

};

template <class V, class A>
Vertice<V, A>::Vertice()
{
	aristas = siguiente = NULL;
}

template <class V, class A>
Vertice<V, A>::Vertice(V info)
{
	this->info = info;
	aristas = NULL;
	siguiente = NULL;
}

template <class V, class A>
Vertice<V, A>::~Vertice()
{
	Arista<V, A> * temp = aristas;

	while (temp != NULL) {
		aristas = aristas->getSiguiente();
		delete temp;
		temp = aristas;
	}
}

template <class V, class A>
V Vertice<V, A>::getInfo()
{
	return info;
}

template <class V, class A>
void Vertice<V, A>::setInfo(V value)
{
	info = value;
}

template <class V, class A>
Arista<V, A> * Vertice<V, A>::getAristas()
{
	return aristas;
}

template <class V, class A>
void Vertice<V, A>::setAristas(Arista<V, A> value)
{
	aristas = value;
}

template <class V, class A>
Vertice<V, A> * Vertice<V, A>::getSiguiente()
{
	return siguiente;
}

template <class V, class A>
void Vertice<V, A>::setSiguiente(Vertice<V, A> * value)
{
	siguiente = value;
}

template <class V, class A>
void Vertice<V, A>::AdicionarArista(Arista<V, A> * arista)
{
	Arista<V, A> * temp = aristas;
	Arista<V, A> * anterior = aristas;

	while (temp != NULL) {
		anterior = temp;
		temp = temp->getSiguiente();
	}

	if (anterior == NULL)
	{
		aristas = arista;
	}
	else {
		anterior->setSiguiente(arista);
	}
}

template <class V, class A>
void Vertice<V, A>::AdicionarArista(A peso, Vertice<V, A> * destino)
{
	Arista<V, A> * arista = new Arista<V, A>(peso, destino);
	AdicionarArista(arista);
}

template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Vertice<V, A> & vertice)
{
	os << "Vertice " << vertice.info << " se ha relacionado con: "<<std::endl;

	Arista<V, A> * temp = vertice.aristas;

	while (temp != NULL) {
		os << *temp;
		temp = temp->getSiguiente();
	}

	return os;
}

//----------------------------------------------------------

template <class V, class A>
int Vertice<V, A>::sumAristas()
{
	Arista<V, A> * temp = this->aristas;
	int total = 0;
	while (temp != NULL) {
		
		total += temp->getPeso();

		temp = temp->getSiguiente();
	}
	return total;
}

template <class V, class A>
int Vertice<V, A>::cuentArista()
{
	Arista<V, A> * temp = this->aristas;
	int total = 0;
	while (temp != NULL) {

		total ++;

		temp = temp->getSiguiente();
	}
	return total;
}

template <class V, class A>
int Vertice<V, A>::laMasPesada()
{

	Arista<V, A> * temp = this->aristas;
	Arista<V, A>* gorda = temp;
	while (temp != NULL) {

		if (gorda->getPeso() < temp->getPeso())
		{
			gorda = temp;
		}

		temp = temp->getSiguiente();
	}
	return gorda->getPeso();
}

#endif /* defined(__t7c4e2__Vertice__) */