//template de la cola
#pragma once

#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T> class Cola;
template <typename T> ostream & operator << (ostream & os, Cola<T> & c); 

template <class T>
class Cola
{
	Nodo<T> *inicio;
	Nodo<T> *fin;
	int tamano;

public:
	Cola(void); //constructor
	~Cola(void); //destructor
	Nodo<T> *getInicio(); 
	Nodo<T> *getFin();
	int size();

	bool empty(); //esta vacio o no

	void enqueue(Nodo<T> *); //inserta
	Nodo<T> *dequeue(); //elimina

	Nodo<T> *find(T value); //encuentra

	void clear(); //borra todo

	friend ostream & operator << <>(ostream & os, Cola &c );
};

template<class T> 
Cola<T>::Cola()
{
	inicio = fin = NULL;
	tamano = 0;
}

template <class T>
Cola<T>::~Cola()
{
	clear();
}

template <class T>
void Cola<T>::clear()
{
	Nodo<T> *temp = inicio;

	while(temp != NULL)
	{
		inicio = inicio->getNext();
		delete temp;
		temp = inicio;
		tamano--;
	}

	fin = NULL;
}

template <class T> 
Nodo<T> *Cola<T>::getInicio()
{
	return inicio;
}

template <class T> 
Nodo<T> *Cola<T>::getFin()
{
	return fin;
}

template <class T> 
int Cola<T>::size()
{
	return tamano;
}

template <class T> 
bool Cola<T>::empty()
{
	return tamano == 0;
}

template <class T> 
void Cola<T>::enqueue(Nodo<T> *nodo)
{
	if(!empty())
	{
		fin->setNext(nodo);
		fin = nodo;
	}
	else
		inicio = fin = nodo;
	
	tamano++;
}

template <class T> 
Nodo<T> *Cola<T>::dequeue()
{
	Nodo<T> *temp = NULL;
	
	if(!empty())
	{
		temp = inicio;
		if(inicio == fin)
			inicio = fin = NULL;
		else
			inicio = inicio->getNext();
		
		temp->setNext(NULL);
		tamano--;
	}

	return temp;
}

template <class T> 
Nodo<T> *Cola<T>::find(T value)
{
	Nodo<T> *temp = inicio;
	bool encontrado = false;

	while(!encontrado && temp != NULL)
	{
		if(temp->getInfo() == value)
			encontrado = true;
		else
			temp = temp->getNext();
	}

	return temp;
}

template <typename T> 
ostream & operator <<(ostream & os, Cola<T> & c)
{
	Nodo<T> *temp = c.getInicio();
	
	while(temp != NULL)
	{
		os << *temp << endl;
		temp = temp->getNext();
	}

	return os;
}