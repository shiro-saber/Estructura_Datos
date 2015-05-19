#ifndef __t7c4e2__Arista__
#define __t7c4e2__Arista__

#include <iostream>
#include "Vertice.h"

template <typename V, typename A>
std::ostream & operator <<(std::ostream & os, Arista<V, A> & arista);

template <class V, class A>
class Arista {
	A peso;

public:
	Arista<V, A> * siguiente;
	Vertice<V, A> * destino;

	Arista();
	Arista(A peso, Vertice<V, A> * destino);

	A getPeso();
	void setPeso(A value);

	Vertice<V, A> * getDestino();
	void setDestino(Vertice<V, A> * value);

	Arista<V, A> * getSiguiente();
	void setSiguiente(Arista<V, A> * value);

	friend std::ostream & operator << <>(std::ostream & os, Arista<V, A> & arista);

};

template <class V, class A>
Arista<V, A>::Arista()
{
	siguiente = NULL;
	destino = NULL;
}

template <class V, class A>
Arista<V, A>::Arista(A peso, Vertice<V, A> * destino)
{
	this->peso = peso;
	this->destino = destino;
	this->siguiente = NULL;
}

template <class V, class A>
A Arista<V, A>::getPeso()
{
	if (this == NULL)
	{
		return 0;
	}
	return peso;
}

template <class V, class A>
void Arista<V, A>::setPeso(A value)
{
	peso = value;
}

template <class V, class A>
Vertice<V, A> * Arista<V, A>::getDestino()
{
	return destino;
}

template <class V, class A>
void Arista<V, A>::setDestino(Vertice<V, A> * value)
{
	destino = value;
}

template <class V, class A>
Arista<V, A> * Arista<V, A>::getSiguiente()
{
	return siguiente;
}

template <class V, class A>
void Arista<V, A>::setSiguiente(Arista<V, A> * value)
{
	siguiente = value;
}

template <typename V, typename A>
std::ostream & operator << (std::ostream & os, Arista<V, A> & arista)
{
	os << " --- " << arista.peso << " ---> " << arista.destino->getInfo() << std::endl;

	return os;
}

#endif /* defined(__t7c4e2__Arista__) */