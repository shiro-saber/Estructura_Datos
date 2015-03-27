#include <cstdlib>
#include<iostream>
#include<string.h>
#include"Node.h"
#include"CircularLinkedList.h"

using namespace std;
using namespace vcn;

void print(CircularLinkedList<bool> *este, string esteotro)
{
    for(int i = 0; i < este->size(); ++i)
        if(este->at(i)->getInfo())
            cout << esteotro << " ";
        else
            cout << "º" << "\n";
}

int main(int argc, char** argv) 
{
    CircularLinkedList<bool> *computadoras = new CircularLinkedList<bool>();
    int modishness = 0;//computadoras
    
    cout << "Numero de computadoras.\n";
    cin >> modishness;
    
    for(int i = 0; i < modishness-1; ++i)
        computadoras->LinkedList::insert(false, 0);
    computadoras->LinkedList::insert(true, 0);
    
    cout << "Token Ring\n";
    print(computadoras, "l");
    
    Node<bool> *nodo = computadoras->at(true);
    
    int pos = computadoras->LinkedList::at(nodo)-1;
    int kuz, kuzemac;
    
    cout << "Enviar desde esta computadora: \n";
    cin >> kuz;
    cout << "Enviar a esta computadora: \n";
    cin >> kuzemac;
    kuz++;
    kuzemac++;
    
    for(int j = 0; j < computadoras->size(); ++j)
        cout << j+1 << "\n";
    
    print(computadoras, "l");
    
    while(pos % computadoras->size() != kuz)
    {
        computadoras->at(pos % computadoras->size())->setInfo(false);
        computadoras->at((pos+1) % computadoras->size())->setInfo(true);
        print(computadoras, "l");
        pos++;
    }
    
    print(computadoras, ">");
    
    while(pos % computadoras->size() != kuzemac)
    {
        computadoras->at(pos % computadoras->size())->setInfo(false);
        computadoras->at((pos+1) % computadoras->size())->setInfo(true);
        print(computadoras, "<");
        pos++;
    }
    return 0;
}

