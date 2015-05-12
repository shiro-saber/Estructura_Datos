#pragma once

#include <iostream>
#include "Nodo.h"
#include <string>
#include <vector>

template <class N>
class ArbolBinario
{
private:
	Nodo<N> * raiz;

public:
	ArbolBinario()
	{
		raiz = NULL;
	}

	ArbolBinario(Nodo<N> * r)
	{
		raiz = r;
	}

	Nodo<N> * getRaiz()
	{
		return raiz;
	}

	void Clear();
	void Clear(Nodo<N> * n);

	void Insert(Nodo<N> * n);
	bool InsertAt(N info, Nodo<N> * n);

	Nodo<N> * deleteAt(N info);

	void preOrden();
	void preOrden(Nodo<N> * n);

	int sumatoria();
	int sumatoria(Nodo<N> * n);

	Nodo <N> * sumaArbol();
	void sumaArbol(Nodo<N> * n);

	void inOrden();
	void inOrden(Nodo<N> * n);
	void imprimir();

	Nodo<N> * copiar(Nodo<N> * n);
	ArbolBinario<N> * copiar();

	Nodo <N> * buscar(N info);
	Nodo <N> * buscar(N info, Nodo<N> * n);

	Nodo <N> * buscarHermano(N info);
	Nodo <N> * buscarHermano(N info, Nodo<N> * n);

	bool ancestro(Nodo<N> * n, Nodo<N> * m);

	vector<Nodo <N> *> buscarPrimos(int prof);

	int mostrarHojas();
	int mostrarHojas(Nodo<N> * n);

	int profundidad();
	int profundidad(Nodo<N> * n);

	void posOrden();
	void posOrden(Nodo<N> * n);

	int size();
	int size(Nodo<N> * n);

	Nodo<N> * buscarLugar();
	Nodo<N> * buscarLugar(Nodo<N> * n);

	void printTree(Nodo<N> *node, string str, string left, string right);

	void arbolReflex(Nodo <N> * n);
	void arbolReflex();

	void creaArbol();

	Nodo <N> * creaArbol(char * pre, int pI, int pF, char * inO, int iI, int iF);

	void creaArbolPos(char * pre, int pI, int pF, char * posO, int posI, int posF);
	Nodo <N> * creaArbolPosO(char * pre, int pI, int pF, char * posO, int posI, int posF);

	~ArbolBinario();
};

template <class N>
int ArbolBinario<N>::size()
{
	return size(raiz);
}

template <class N>
int ArbolBinario<N>::profundidad()
{
	return profundidad(raiz);
}

template <class N>
int ArbolBinario<N>::profundidad(Nodo<N> * n)
{
	int izq = 0;
	int der = 0;

	if (n != NULL)
	{
		izq = profundidad(n->getIzq());
		der = profundidad(n->getDer());

		if (izq > der)
			return 1 + izq;
		else
			return 1 + der;
	}
	return 0;
}

template <class N>
int ArbolBinario<N>::mostrarHojas()
{
	return mostrarHojas(raiz);
}

template <class N>
int ArbolBinario<N>::mostrarHojas(Nodo<N> * n)
{
	int cont = 0;

	if (n != NULL)
	{
		if (n->getIzq() == NULL && n->getDer() == NULL)
		{
			cout << *n;
			cont++;
		}
		return cont + mostrarHojas(n->getIzq()) + mostrarHojas(n->getDer());
	}
	return cont;
}

template <class N>
int ArbolBinario<N>::size(Nodo<N> *n)
{
	int nodos = 0;

	if (n == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + size(n->getIzq()) + size(n->getDer());
	}
	return nodos;
}

template <class N>
void ArbolBinario<N>::Clear()
{
	Clear(raiz);
	raiz = NULL;
}

template <class N>
void ArbolBinario<N>::Clear(Nodo<N> * n)
{
	if (n != NULL)
	{
		Clear(n->getIzq());
		Clear(n->getDer());
		delete n;
	}
}

template <class N>
void ArbolBinario<N>::preOrden()
{
	preOrden(raiz);
}

template <class N>
void ArbolBinario<N>::preOrden(Nodo<N> * n)
{
	if (n != NULL)
	{
		std::cout << *n;
		preOrden(n->getIzq());
		preOrden(n->getDer());
	}
}

template <class N>
void ArbolBinario<N>::inOrden()
{
	inOrden(raiz);
}

template <class N>
void ArbolBinario<N>::inOrden(Nodo<N> * n)
{
	if (n != NULL)
	{
		inOrden(n->getIzq());
		std::cout << *n;
		inOrden(n->getDer());
	}
}

template <class N>
void ArbolBinario<N>::posOrden()
{
	posOrden(raiz);
}

template <class N>
void ArbolBinario<N>::posOrden(Nodo<N> * n)
{
	if (n != NULL)
	{
		posOrden(n->getIzq());
		posOrden(n->getDer());
		std::cout << *n;
	}
}

template <class N>
Nodo<N> * ArbolBinario<N>::buscarLugar()
{
	return buscarLugar(raiz);
}

template <class N>
void ArbolBinario<N>::Insert(Nodo<N> * n)
{
	if (raiz == NULL)
	{
		raiz = n;
	}

	else{
		Nodo<N> * padre = buscarLugar();
		n->setPadre(padre);

		if (padre->getIzq() == NULL){
			padre->setIzq(n);
		}
		else
			padre->setDer(n);


	}
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscar(N info)
{
	return buscar(info, raiz);
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscar(N info, Nodo<N> * n)
{
	Nodo<N> * temp = NULL;

	if (n != NULL)
	{
		if (n->getInfo() == info){
			return n;
		}
		else{

			temp = buscar(info, n->getIzq());
			if (temp == NULL)
			{
				temp = buscar(info, n->getDer());
			}
			return temp;
		}
	}
	return temp;
}

template <class N>
bool ArbolBinario<N>::InsertAt(N info, Nodo<N> * n)
{

	bool insertado = false;
	Nodo<N> * padre = buscar(info);

	if (padre != NULL)
	{
		if (padre->getIzq() == NULL)
		{
			padre->setIzq(n);
			n->setPadre(padre);
			insertado = true;
		}
		else if (padre->getDer() == NULL){
			padre->setDer(n);
			insertado = true;
		}
	}
	return insertado;
}

template <class N>
Nodo<N> * ArbolBinario<N>::deleteAt(N info)
{
	Nodo<N> * nodo = buscar(info);
	Nodo<N> * temp;

	if (nodo != NULL)
	{
		if (nodo->getIzq() == NULL && nodo->getDer() == NULL)
		{
			temp = nodo->getPadre();

			if (temp->getIzq() == nodo)
			{
				temp->setIzq(NULL);
			}

			else 
			{
				temp->setDer(NULL);
			}

			nodo->setPadre(NULL);
		}

		else
		{
			return nodo = NULL;
		}
	}
	return nodo;
}

template <class N>
Nodo<N> * ArbolBinario<N>::buscarLugar(Nodo<N> * n)
{
	if ((n->getIzq() == NULL) || (n->getDer() == NULL))
	{
		return n;

	}
	else{
		return buscarLugar(n->getIzq());

	}


}

template <class N>
ArbolBinario<N>::~ArbolBinario(void)
{
	Clear();
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscarHermano(N info)
{
	Nodo<N> * temp = buscar(info);

	return buscarHermano(info, temp);
}

template <class N>
Nodo <N> * ArbolBinario<N>::buscarHermano(N info, Nodo<N> * n)
{


	if (n != NULL && n->getPadre() != NULL)
	{


		if (n->getPadre()->getIzq() == n)
		{
			return n->getPadre()->getDer();

		}

		else
		{
			return n->getPadre()->getIzq();

		}

	}

	return NULL;

}



template <class N>
vector<Nodo <N> *> ArbolBinario<N>::buscarPrimos(int prof)
{
	vector <Nodo <N> * > padres;


	padres.push_back(raiz);

	while (prof-- > 0)
	{
		vector <Nodo <N> * > hijos;

		for (int i = 0; i<padres.size(); i++)
		{
			if (padres[i]->getDer() != NULL)
			{
				hijos.push_back(padres[i]->getDer());
			}
			if (padres[i]->getIzq() != NULL)
			{
				hijos.push_back(padres[i]->getIzq());
			}

		}

		padres = hijos;

	}
	return padres;

}

template <class N>
bool ArbolBinario<N>::ancestro(Nodo<N> * n, Nodo<N> * m)
{

}

template <class N>
int ArbolBinario<N>::sumatoria()
{
	return sumatoria(raiz);
}

template <class N>
int ArbolBinario<N>::sumatoria(Nodo<N> * n)
{
	if (n != NULL)
	{
		return n->getInfo() + sumatoria(n->getIzq()) + sumatoria(n->getDer());
	}
	return 0;
}

template <class N>
ArbolBinario<N> * ArbolBinario<N>::copiar()
{
	return new ArbolBinario <N>(copiar(raiz));
}

template <class N>
Nodo<N> * ArbolBinario<N>::copiar(Nodo<N> * n)
{
	if (n != NULL)
	{
		Nodo<N> * temp = new Nodo<N>(0);
		temp->setInfo(n->getInfo());

		Nodo<N> * izq = copiar(n->getIzq());
		Nodo<N> * der = copiar(n->getDer());

		if (izq != NULL)
		{
			temp->setIzq(izq);
			izq->setPadre(temp);
		}

		if (der != NULL)
		{
			temp->setDer(der);
			der->setPadre(temp);
		}
		return temp;
	}
	else
		return NULL;
}

template <class N>
Nodo<N> * ArbolBinario<N>::sumaArbol()
{
	sumaArbol(raiz);
	return 0;
}

template <class N>
void ArbolBinario<N>::sumaArbol(Nodo<N> * n)
{
	if (n != NULL)
	{
		n->setInfo(sumatoria(n));
		sumaArbol(n->getIzq());
		sumaArbol(n->getDer());
	}
}

template <class N>
void ArbolBinario<N>::printTree(Nodo<N> *node, string str, string left, string right)
{
	if (node != NULL)
	{
		printTree(node->getDer(), right + "    ", right + "    |", right + "     ");
		cout << str << "|----" << *node << endl;
		printTree(node->getIzq(), left + "    ", left + "     ", left + "    |");
	}
}

template <class N>
void ArbolBinario <N>::imprimir()
{
	printTree(raiz, " ", " ", " ");
}


template <class N>
void ArbolBinario <N>::arbolReflex()
{
	arbolReflex(raiz);
}

template <class N>
void ArbolBinario <N>::arbolReflex(Nodo <N> * n)
{
	Nodo <N> * temp;
	if (n != NULL){
		temp = n->getIzq();
		n->setIzq(n->getDer());
		n->setDer(temp);

		arbolReflex(n->getIzq());
		arbolReflex(n->getDer());
	}
}

template <class N>
Nodo <N> * ArbolBinario <N>::creaArbol(char * pre, int preInicio, int preFin, char * inO, int inInicio, int inFin)
{
	if (preInicio == preFin)
	{
		Nodo<N> * n1 = new Nodo<N>(pre[preInicio]);
		return n1;
	}

	if (preFin - preInicio == 1)
	{
		if (pre[preInicio] == inO[inInicio])
		{
			Nodo<N> * n1 = new Nodo<N>(pre[preInicio]);
			Nodo<N> * n2 = new Nodo<N>(pre[preInicio + 1]);
			cout << endl << "PValue: " << n1->getInfo() << endl;
			cout << endl << "HValue: " << n2->getInfo() << endl;
			n1->setDer(n2);
			n2->setPadre(n1);
			return n1;
		}
		else
		{
			Nodo<N> * n1 = new Nodo<N>(pre[preInicio + 1]);
			Nodo<N> * n2 = new Nodo<N>(pre[preInicio]);
			n1->setIzq(n2);
			n2->setPadre(n1);
			return n1;
		}
	}
	int raizIn = 0;

	for (int i = inInicio; i<inFin; i++)
	{
		if (inO[i] == pre[preInicio])
			raizIn = i;
	}

	int elemIzq = raizIn - inInicio;

	Nodo<N> * n = new Nodo<N>(pre[preInicio]);
	Nodo<N> *izq = creaArbol(pre, preInicio + 1, preInicio + elemIzq, inO, inInicio, raizIn - 1);
	if (izq != NULL)
	{
		n->setIzq(izq);
		izq->setPadre(n);
	}

	Nodo<N> *der = creaArbol(pre, preInicio + elemIzq + 1, preFin, inO, raizIn + 1, inFin);
	if (der != NULL)
	{
		n->setDer(der);
		der->setPadre(n);
	}

	return n;
}

template <class N>
Nodo <N> * ArbolBinario <N>::creaArbolPosO(char * pos, int posInicio, int posFin, char * inO, int inInicio, int inFin)
{
	if (posInicio == posFin)
	{
		Nodo<N> * n1 = new Nodo<N>(pos[posFin]);
		return n1;
	}

	if (posFin - posInicio == 1)
	{
		if (pos[posFin] != inO[inInicio])
		{
			Nodo<N> * n1 = new Nodo<N>(pos[posFin]);
			Nodo<N> * n2 = new Nodo<N>(pos[posFin - 1]);
			n1->setIzq(n2);
			n2->setPadre(n1);
			return n1;
		}
		else
		{
			Nodo<N> * n1 = new Nodo<N>(pos[posFin - 1]);
			Nodo<N> * n2 = new Nodo<N>(pos[posFin]);
			n1->setDer(n2);
			n2->setPadre(n1);
			return n1;
		}
	}
	int raizIn = 0;

	for (int i = inInicio; i < inFin; i++)
	{
		if (inO[i] == pos[posFin])
			raizIn = i;
	}

	int elemIzq = raizIn - inInicio;

	Nodo<N> * n = new Nodo<N>(pos[posFin]);
	Nodo<N> *izq = creaArbolPosO(pos, posInicio, posInicio + elemIzq - 1, inO, inInicio, raizIn - 1);
	if (izq != NULL)
	{
		n->setIzq(izq);
		izq->setPadre(n);
	}

	Nodo<N> *der = creaArbolPosO(pos, posInicio + elemIzq, posFin - 1, inO, raizIn + 1, inFin);
	if (der != NULL)
	{
		n->setDer(der);
		der->setPadre(n);
	}
	return n;
}