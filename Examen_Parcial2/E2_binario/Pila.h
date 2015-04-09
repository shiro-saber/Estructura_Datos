#include <iostream>
#include "Nodo.h"

template <class N> class Pila;
template <class N> ostream & operator <<(ostream & os, Pila<N> & s);

template <class N>
class Pila 
{
    
    Nodo<N> * tope;
    int tamano;
    
public:
    Pila()
    {
        tope = nullptr;
        tamano = 0;
    }
    ~Pila();
    
    void push(Nodo<N> * n);
    
    Nodo<N> * pop();
    Nodo<N> * top();
    
    void clear();
    
    int size();
    bool empty();
    
    friend ostream & operator << <>(ostream & os, Pila<N> & s);
    
};

template <class N>
Pila<N>::~Pila()
{
    clear();
}

template <class N>
void Pila<N>::push(Nodo<N> * n)
{
    if (!empty())
    {
        n->setNext(tope);
        tope = n;        
    }
    
    else 
	{   
        tope = n;
    }
    tamano++;
}



template <class N>
Nodo<N> * Pila<N>::pop()
{
    Nodo<N> * temp = nullptr;
    
    if (!empty())
    {
        temp = tope;
        tope = tope -> getNext();
        
        --tamano;
    }
    return temp;
}

template <class N>
Nodo<N> * Pila<N>::top()
{
    return tope;
}


template <class N>
void Pila<N>::clear()
{
    if (!empty())
    {
        Nodo<N> * temp;
        
        while (!empty()) 
	{
            temp = pop();
            delete temp;
        }
    }
}


template <class N>
int Pila<N>::size()
{
    return tamano;
}

template <class N>
bool Pila<N>::empty()
{
    return (tamano == 0);
}


template <typename N>
ostream & operator <<(ostream & os, Pila<N> & s)
{
    Pila<N> * pila_temp = new Pila<N>();
    Nodo<N> * temp;
    
    while ((temp = s.pop()) != nullptr)
    {
        os << *temp << endl;
        pila_temp->push(temp);
    }
        // Regresar los elementos a la pila 
        
    while ((temp = pila_temp->pop()) != nullptr)
    {
		s.push(temp);
    }
        
    delete pila_temp;    
    return os;
}