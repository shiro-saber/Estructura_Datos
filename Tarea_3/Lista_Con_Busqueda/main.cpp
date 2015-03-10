#include <iostream>
#include "BusquedaGenerica.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    const int n = 10;
    const int m = 12;
    
    using namespace vcn;
    
    /* Declarar las listas */
    LinkedList<int> * N = new LinkedList<int>();
    LinkedList<int> * M = new LinkedList<int>();
    LinkedList<int> * P = new LinkedList<int>();
    
    
    for (int i = 0; i < n; ++i) {
        N->insertBack(i);
    }
    
    for (int i = 0; i < m; ++i) {
        M->insertBack(i);
    }

    
    /* Unir ambas listas */
    
    int numero;
    
    for (int i = 0; i < n; ++i) {
        numero = N->at(i)->getInfo();
        P->insertBack(numero);
    }
    
    for (int i = 0; i < m; ++i) {
        numero = M->at(i)->getInfo();
        
        if ( !P->search(numero) )
        {
            P->insertBack(numero);
        }
    }
    
    /* Visualizar las listas */
    cout << "N: " << *N << endl;
    cout << "M: " << *M << endl;
    cout << "P: " << *P << endl;
    
    
    /* Liberar la memoria ocupada por las listas */
    delete N;
    delete M;
    delete P;
    
    return 0;
}