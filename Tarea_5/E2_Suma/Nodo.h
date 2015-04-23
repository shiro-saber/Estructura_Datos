#pragma once
#include <iostream>

using namespace std;

template <class T> class Nodo;
template <typename T> ostream & operator <<(ostream & os, Nodo<T>  & n);

template <class T>
class Nodo
{
private:
	T info;
	Nodo<T> * izq;
	Nodo<T> * der;
	Nodo<T> * padre;

public:
	Nodo(T i)
	{
		info = i;
		izq = NULL;
		der = NULL;
		padre = NULL;
	}

	T getInfo()
	{
		return info;
	}

	Nodo<T> * getIzq()
	{
		return izq;
	}

	Nodo<T> * getDer()
	{
		return der;
	}

	Nodo<T> * getPadre()
	{
		return padre;
	}


	void setInfo(T value)
	{
		info = value;
	}

	void setIzq(Nodo<T> * value)
	{
		izq = value;
	}

	void setDer(Nodo<T> * value)
	{
		der = value;
	}

	void setPadre(Nodo<T> * value)
	{
		padre = value;
	}

	friend std::ostream & operator << <>(std::ostream & os, Nodo<T> & n);
};


template <typename T>
ostream & operator <<(ostream & os, Nodo<T>  & n)
{
	os << "-" << n.info;
	return os;
}