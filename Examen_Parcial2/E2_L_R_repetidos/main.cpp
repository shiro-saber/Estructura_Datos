#include <cstdlib>
#include "LinkedList.h"

using namespace std;
using namespace vcn;

LinkedList<int> *check(LinkedList<int> *original)
{
    LinkedList<int> * repetidos = new LinkedList<int>();
    for (int i = 0; i < original->size(); ++i) {
        for (int j = i + 1; j < original->size(); ++j) {
            if (original->at(i)->getInfo()==original->at(j)->getInfo()) {
                int r = original->at(i)->getInfo();
                bool agregamela = true;
                for (int k = 0; k < repetidos->size(); ++k) {
                    if (r==repetidos->at(k)->getInfo()) {
                        agregamela=false;
                    }
                }
                if (agregamela) {
                    repetidos->insertFront(r);
                }
            }
        }
    }
    return repetidos;
}

int main(int argc, char** argv) 
{
    LinkedList<int> *original = new Pila<int>();
    
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
    
    LinkedList<int> *repetidos = check(original);
    cout << "Esta la lista de repetidos: \n" << *repetidos << endl;
    
    delete repetidos;
    delete original;
    
    return 0;
}

