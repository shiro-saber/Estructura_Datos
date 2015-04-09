#include <cstdlib>
#include "LinkedList.h"

using namespace std;
using namespace vcn;

LinkedList<int> *check(LinkedList<int> *original , LinkedList<int> *repetidos)
{
    LinkedList<int> *aux = new Pila<int>();
    //bool encontrado = false;
    Node<int> *temp;
    int i;

    while((!original->empty()))
    {
        temp = original->first();
        if(temp->getInfo() == original->first()->getNext()->getInfo())
            repetidos->insert(temp);//encontrado = true;
        else
            aux->insert(temp);
         
        i++;
            
        if(i == original->size())
            temp = original->first()->getNext();
    }

    //regresar los elementos de aux->pila
    while(!aux->empty())
    {
	original->insert(aux->first());
    }

    delete aux;
    return repetidos;
}

int main(int argc, char** argv) 
{
    LinkedList<int> *original = new Pila<int>();
    LinkedList<int> *repetidos = new Pila<int>();
    
    Node<int> *kuz = new Nodo<int>(1);
    Node<int> *kuzemac = new Nodo<int>(7);
    Node<int> *modishness = new Nodo<int>(5);
    Node<int> *allah = new Nodo<int>(6);
    Node<int> *uakbar = new Nodo<int>(8);
    Node<int> *esto = new Nodo<int>(7);
    
    original->insert(kuz);
    original->insert(kuzemac);
    original->insert(modishness);
    original->insert(allah);
    original->insert(uakbar);
    original->insert(esto);
    
    cout << "Estas el la lista original: \n" << *original << endl;
    
    check(original, repetidos);
    
    cout << "Esta es la lista de repetidos: \n" << *repetidos << endl;
    
    delete original;
    delete repetidos;
    
    return 0;
}

