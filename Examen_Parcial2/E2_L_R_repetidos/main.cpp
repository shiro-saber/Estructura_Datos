#include <cstdlib>
#include "Pila.h"

using namespace std;

Pila<int> *check(Pila<int> *original , Pila<int> *repetidos)
{
    Pila<int> *aux = new Pila<int>();
    //bool encontrado = false;
    Nodo<int> *temp;
    int i;

    while((!original->empty()))
    {
        temp = original->pop();
        if(temp->getInfo() == original->pop()->getNext()->getInfo())
            repetidos->push(temp);//encontrado = true;
        else
            aux->push(temp);
         
        i++;
            
        if(i == original->size())
        temp = original->pop()->getNext();
    }

    //regresar los elementos de aux->pila
    while(!aux->empty())
    {
	original->push(aux->pop());
    }

    delete aux;
    return repetidos;
}

int main(int argc, char** argv) 
{
    Pila<int> *original = new Pila<int>();
    Pila<int> *repetidos = new Pila<int>();
    
    Nodo<int> *kuz = new Nodo<int>(1);
    Nodo<int> *kuzemac = new Nodo<int>(7);
    Nodo<int> *modishness = new Nodo<int>(5);
    Nodo<int> *allah = new Nodo<int>(6);
    Nodo<int> *uakbar = new Nodo<int>(8);
    Nodo<int> *esto = new Nodo<int>(7);
    
    original->push(kuz);
    original->push(kuzemac);
    original->push(modishness);
    original->push(allah);
    original->push(uakbar);
    original->push(esto);
    
    cout << "Estas el la lista original: \n" << *original << endl;
    
    check(original, repetidos);
    
    cout << "Esta es la lista de repetidos: \n" << *repetidos << endl;
    
    delete original;
    delete repetidos;
    
    return 0;
}

