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
		raiz = nullptr;
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

	void ancestro(Nodo<N> * node);

	void buscarPrimos(Nodo<N> *node);

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
        
        vector<N> nodosNivel(vector<N> nodos, Nodo<N> * node, int nivAct, int nivel);

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

	if (n != nullptr)
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

	if (n != nullptr)
	{
		if (n->getIzq() == nullptr && n->getDer() == nullptr)
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

	if (n == nullptr)
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
	raiz = nullptr;
}

template <class N>
void ArbolBinario<N>::Clear(Nodo<N> * n)
{
	if (n != nullptr)
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
	if (n != nullptr)
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
	if (n != nullptr)
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
	if (n != nullptr)
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
	if (raiz == nullptr)
	{
		raiz = n;
	}

	else{
		Nodo<N> * padre = buscarLugar();
		n->setPadre(padre);

		if (padre->getIzq() == nullptr){
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
	Nodo<N> * temp = nullptr;

	if (n != nullptr)
	{
		if (n->getInfo() == info){
			return n;
		}
		else{

			temp = buscar(info, n->getIzq());
			if (temp == nullptr)
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

	if (padre != nullptr)
	{
		if (padre->getIzq() == nullptr)
		{
			padre->setIzq(n);
			n->setPadre(padre);
			insertado = true;
		}
		else if (padre->getDer() == nullptr){
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

	if (nodo !=nullptr)
	{
		if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr)
		{
			temp = nodo->getPadre();

			if (temp->getIzq() == nodo)
			{
				temp->setIzq(nullptr);
			}

			else 
			{
				temp->setDer(nullptr);
			}

			nodo->setPadre(nullptr);
		}

		else
		{
			return nodo = nullptr;
		}
	}
	return nodo;
}

template <class N>
Nodo<N> * ArbolBinario<N>::buscarLugar(Nodo<N> * n)
{
	if ((n->getIzq() == nullptr) || (n->getDer() == nullptr))
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
void ArbolBinario<N>::buscarPrimos(Nodo<N> *nodo)
{
    int niv = 0;
    Nodo<N> *kuz = nodo;
    while (kuz != nullptr)
    {
        kuz = kuz->getPadre();
        niv++;
    }
    
    niv--;
    vector<N> primo;
    primo.clear();
    primo = this->nodosNivel(primo, raiz, 0, niv);
    for(int i = 0; i < primo.size(); ++i)
        cout << primo[i].getnombre() << endl;
}

template<class N>
vector<N> ArbolBinario<N>::nodosNivel(vector<N> nodos, Nodo<N> * node, int nivAct, int nivel)
{
    if (node && nivAct < nivel) 
    {
        vector<N> izq = nodosNivel(nodos,node->getIzq,(nivAct+1),nivel);
        vector<N> der = nodosNivel(nodos,node->getDer(),(nivAct+1),nivel);
        if (!izq.empty()) 
            nodos.insert(nodos.end(), izq.begin(), izq.end());
            
        if (!der.empty()) 
            nodos.insert(nodos.end(), der.begin(), der.end());
    }
    else
    {
        if (nivel == nivAct && node)
            nodos.push_back(node->getInfo());
    }

    return nodos;
}

template <class N>
void ArbolBinario<N>::ancestro(Nodo<N> * node)
{
    if (node) 
    {
        cout << node->getInfo().getnombre << " -> ";
        ancestro(node->getPadre());
    }
}

template <class N>
int ArbolBinario<N>::sumatoria()
{
	return sumatoria(raiz);
}

template <class N>
int ArbolBinario<N>::sumatoria(Nodo<N> * n)
{
	if (n != nullptr)
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
	if (n != nullptr)
	{
		Nodo<N> * temp = new Nodo<N>(0);
		temp->setInfo(n->getInfo());

		Nodo<N> * izq = copiar(n->getIzq());
		Nodo<N> * der = copiar(n->getDer());

		if (izq != nullptr)
		{
			temp->setIzq(izq);
			izq->setPadre(temp);
		}

		if (der != nullptr)
		{
			temp->setDer(der);
			der->setPadre(temp);
		}
		return temp;
	}
	else
		return nullptr;
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
	if (node != nullptr)
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
	if (n != nullptr){
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
	if (izq != nullptr)
	{
		n->setIzq(izq);
		izq->setPadre(n);
	}

	Nodo<N> *der = creaArbol(pre, preInicio + elemIzq + 1, preFin, inO, raizIn + 1, inFin);
	if (der != nullptr)
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
	if (izq != nullptr)
	{
		n->setIzq(izq);
		izq->setPadre(n);
	}

	Nodo<N> *der = creaArbolPosO(pos, posInicio + elemIzq, posFin - 1, inO, raizIn + 1, inFin);
	if (der != nullptr)
	{
		n->setDer(der);
		der->setPadre(n);
	}
	return n;
}
